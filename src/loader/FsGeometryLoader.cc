#include "loader/FsGeometryLoader.h"
#include "loader/FsLoaderUtil.h"
#include "model/FsGeometry.h"
#include "fsys/FsVFS.h"
#include "util/FsDict.h"
#include "util/FsScriptUtil.h"

NS_FS_BEGIN

ResourceMgr* GeometryLoader::m_mgr=NULL;

Geometry* GeometryLoader::create(const FsChar* filename)
{
	FsFile* file=VFS::open(filename);
	if(file==NULL)
	{
		return NULL;
	}
	Geometry* ret=create(file);
	file->decRef();
	return ret;
}

Geometry* GeometryLoader::create(FsFile* file)
{
	if(LoaderUtil::fileType(file)==FS_FTYPE_SCRIPT)
	{
		return createFromScript(file);
	}
	else 
	{
		return createFromBinary(file);
	}
}


Geometry* GeometryLoader::createFromScript(FsFile* file)
{
	Geometry* ret=NULL;
	FsDict* script=NULL;
	FsString* sct_type=NULL;

	script=ScriptUtil::parseScript(file);
	if(script==NULL)
	{
		FS_TRACE_WARN("parseScript Failed");
		goto error;
	}

	sct_type=ScriptUtil::getString(script,"type");
	if(sct_type==NULL)
	{
		FS_TRACE_WARN("Script Isn't Geometry Type Infor");
		goto error;
	}

	if(sct_type->equal("geometry"))
	{

		ret=createFromDict(script);
	}
	else 
	{
		FS_TRACE_WARN("File Is Not Geometry Type");
	}

	script->decRef();
	sct_type->decRef();
	return ret;
error:
	if(script) script->decRef();
	if(sct_type) sct_type->decRef();
	return NULL;
}


Geometry::Attribute* s_ToGeometryAttribute(FsDict* dict,FsInt count)
{

	FsString* sct_name=ScriptUtil::getString(dict,"name");
	if(sct_name==NULL)
	{
		FS_TRACE_WARN("Can't Get \"name\" For Attribute");
		return NULL;
	}
	FsString* sct_type=ScriptUtil::getString(dict,"type");
	if(sct_type==NULL)
	{
		FS_TRACE_WARN("Can't get \"type\" In Attribute");
		sct_name->decRef();
		return NULL;
	}
	FsInt size;
	if(ScriptUtil::getInteger(dict,"size",&size))
	{
		FS_TRACE_WARN("Can't get \"size\" In Attribute");
		sct_name->decRef();
		sct_type->decRef();
		return NULL;
	}
	if(size<1||size>4)
	{
		FS_TRACE_WARN("Size(%d) Is Out Of Range(1-4)",size);
		sct_name->decRef();
		sct_type->decRef();
		return NULL;
	}
	FsInt type;
	if(sct_type->equal("float"))
	{
		type=FS_FLOAT;
	}
	else if(sct_type->equal("int"))
	{
		type=FS_INT;
	}
	else if(sct_type->equal("int8"))
	{
		type=FS_INT8;
	}
	else if(sct_type->equal("int16"))
	{
		type=FS_INT16;
	}
	else if(sct_type->equal("int32"))
	{
		type=FS_INT32;
	}
	else if(sct_type->equal("uint8"))
	{
		type=FS_UINT8;
	}
	else if(sct_type->equal("uint16"))
	{
		type=FS_UINT16;
	}
	else if(sct_type->equal("uint32"))
	{
		type=FS_UINT32;
	}
	else 
	{
		FS_TRACE_WARN("Unkown Type(%s) For Attribute",sct_type->cstr());
		sct_name->decRef();
		sct_type->decRef();
		return NULL;
	}

	Geometry::Attribute* ret=new Geometry::Attribute(sct_name,type,size,count);

	FsArray* sct_value=ScriptUtil::getArray(dict,"value");
	if(sct_value==NULL)
	{
		FS_TRACE_WARN("Can't Find Values For Attribute");
		return ret;
	}

	FsInt min_count=sct_value->size()/size;
	if(min_count>count)
	{
		min_count=count;
	}
	FsVoid* p_value=ret->value;
	for(FsInt i=0;i<min_count;i++)
	{
		for(FsInt j=0;j<size;j++)
		{
			switch(type)
			{
				case FS_FLOAT:
				{
					FsFloat fvalue=0;
					ScriptUtil::getFloat(sct_value, i*size+j,&fvalue);
					*(((FsFloat*)p_value)+i*size+j)=fvalue;
					break;
				}
				case FS_INT:
				case FS_INT32:
				case FS_UINT32:
				{
					FsInt i32value=0;
					ScriptUtil::getInteger(sct_value,i*size+j,&i32value);
					*(((FsInt*)p_value)+i*size+j)=i32value;
					break;
				}
				case FS_INT8:
				case FS_UINT8:
				{
					FsInt i8value=0;
					ScriptUtil::getInteger(sct_value,i*size+j,&i8value);
					*(((FsInt8*)p_value)+i*size+j)=i8value;
					break;
				}
				case FS_INT16:
				case FS_UINT16:
				{
					FsInt i16value=0;
					ScriptUtil::getInteger(sct_value,i*size+j,&i16value);
					*(((FsInt16*)p_value)+i*size+j)=i16value;
					break;
				}
			}
		}
	}
	sct_value->decRef();
	return ret;
}

Geometry* GeometryLoader::createFromDict(FsDict* dict)
{
	FsInt vertex_nu=0;
	FsInt face_nu=0;
	Geometry* ret=NULL;

	if(!ScriptUtil::getInteger(dict,"vertexNu",&vertex_nu))
	{
		FS_TRACE_WARN("Can't Get \"vertexNu\"");
	}
	if(!ScriptUtil::getInteger(dict,"face3Nu",&face_nu))
	{
		FS_TRACE_WARN("Can't Get \"face3Nu\"");
	}

	ret=new Geometry(vertex_nu,face_nu);
	FsArray* attrs=ScriptUtil::getArray(dict,"attributes");
	if(!attrs)
	{
		return ret;
	}

	FsInt attrs_nu=attrs->size();
	for(FsInt i=0;i<attrs_nu;i++)
	{
		FsDict* cur_attr=ScriptUtil::getDict(attrs,i);
		if(cur_attr==NULL)
		{
			FS_TRACE_WARN("Object Is Not Dict,Ingore");
			continue;
		}
		Geometry::Attribute* ga=s_ToGeometryAttribute(cur_attr,vertex_nu);
		if(ga!=NULL)
		{
			ret->addAttribute(ga);
			ga->decRef();
		}
	}
	attrs->decRef();

	FsArray* face3=ScriptUtil::getArray(dict,"face3");
	if(!face3)
	{
		return ret;
	}
	Face3* p_face=ret->fFacesPointer();
	FsInt cur_face_nu=face3->size()/3;
	if(cur_face_nu>face_nu)
	{
		cur_face_nu=face_nu;
	}
	FsInt value;
	for(FsInt i=0;i<cur_face_nu;i++)
	{

		if(ScriptUtil::getInteger(face3,i*3+0,&value))
		{
			p_face[i].a=value;
		}

		if(ScriptUtil::getInteger(face3,i*3+1,&value))
		{
			p_face[i].b=value;
		}

		if(ScriptUtil::getInteger(face3,i*3+2,&value))
		{
			p_face[i].c=value;
		}
	}
	face3->decRef();
	return ret;
}

void GeometryLoader::saveGeometry(Geometry* g,FsFile* file,FsInt type)
{
	if(type==FS_FTYPE_BINARY)
	{
		saveGeometryWithBinary(g,file);
	}
	else 
	{
		saveGeometryWithScript(g,file);
	}
}

void GeometryLoader::saveGeometryWithScript(Geometry* g,FsFile* file)
{
	file->writeStr("type:\"geometry\"\n");
	file->writeStr("version:\"v1.0\"\n");
	file->writeStr("vertexNu:%d\n",g->getVertexNu());
	file->writeStr("faceNu:%d\n",g->getFaceNu());
	file->writeStr("attributes:[\n");
	FsDict* attrs=g->getAttrs();
	FsDict::Iterator iter(attrs);
	while(!iter.done())
	{
		Geometry::Attribute* cur_attr=(Geometry::Attribute*)iter.getValue();
		file->writeStr("\t{\n");
		file->writeStr("\t\tname:\"%s\"\n",cur_attr->name->cstr());
		file->writeStr("\t\ttype:\"");
		switch(cur_attr->type)
		{
			case FS_FLOAT:
				file->writeStr("float");
				break;
			case FS_INT:
				file->writeStr("int");
				break;
			case FS_INT8:
				file->writeStr("int8");
				break;
			case FS_INT16:
				file->writeStr("int16");
				break;
			case FS_INT32:
				file->writeStr("int32");
				break;
			case FS_UINT8:
				file->writeStr("uint8");
				break;
			case FS_UINT16:
				file->writeStr("uint16");
				break;
			case FS_UINT32:
				file->writeStr("uint32");
				break;
		}
		file->writeStr("\"\n");
		file->writeStr("\t\tsize:%d\n",cur_attr->size);
		file->writeStr("\t\tvalue:[");
		FsVoid* value=cur_attr->value;
		for(FsInt i=0;i<cur_attr->count;i++)
		{
			switch(cur_attr->type)
			{
				case FS_FLOAT:
				{
					file->writeStr("%f,",*(((FsFloat*)value)+i));
					break;
				}
				case FS_INT:
				case FS_INT32:
				{
					file->writeStr("%d,",*(((FsInt*)value)+i));
					break;
				}
				case FS_INT8:
				{
					file->writeStr("%d,",*(((FsInt8*)value)+i));
					break;
				}
				case FS_INT16:
				{
					file->writeStr("%d,",*(((FsInt16*)value)+i));
					break;
				}
				case FS_UINT8:
				{
					file->writeStr("%u,",*(((FsUint8*)value)+i));
					break;
				}
				case FS_UINT16:
				{
					file->writeStr("%u,",*(((FsUint16*)value)+i));
					break;
				}
				case FS_UINT32:
				{
					file->writeStr("%u,",*(((FsUint32*)value)+i));
					break;
				}
			}
		}
		file->writeStr("]\n");
		file->writeStr("\t},");
		cur_attr->decRef();
	}

	file->writeStr("]\n");
	attrs->decRef();
	Face3* face=g->fFacesPointer();
	FsInt faceNu=g->getFaceNu();
	if(face)
	{
		file->writeStr("face3:[");
		for(FsInt i=0;i<faceNu;i++)
		{
			file->writeStr("%d,",(face+i)->a);
			file->writeStr("%d,",(face+i)->b);
			file->writeStr("%d,",(face+i)->c);
		}
		file->writeStr("]\n");
	}
}

NS_FS_END


































