#include <string.h>
#include "loader/FsMeshLoader.h"
#include "util/FsScriptUtil.h"
#include "model/FsGeometry.h"
#include "fsys/FsVFS.h"

NS_FS_BEGIN
static FsBool s_isBinaryFile(FsFile* file)
{
	return false;
}


Mesh* MeshLoader::create(FsFile* file)
{
	if(s_isBinaryFile(file))
	{
//		return loadMeshWithBinaryFile(file);
	}
	else 
	{
		return loadMeshWithScriptFile(file);
	}
	return NULL;
}

Mesh* MeshLoader::create(const char* filename)
{
	FsFile* file=VFS::open(filename);
	if(file==NULL)
	{
		FS_TRACE_WARN("Load Mesh Failed(File Not Found %s)",filename);
		return NULL;
	}
	Mesh* ret=loadMesh(file);
	file->decRef();
	return ret;
}

Mesh* MeshLoader::createFromScript(FsFile* file)
{
	Mesh* ret=NULL;
	FsDict* script=NULL;
	FsString* sct_type=NULL;

	script=ScriptUtil::parseScript(file);

	if(script==NULL)
	{
		FS_TRACE_WARN("ParseScript Failed");
		goto error;
	}

	sct_type=ScriptUtil::getString(script,"type");
	if(sct_type==NULL)
	{
		FS_TRACE_WARN("Script Doesn't Have Mesh Infor");
		goto error;
	}
	if(sct_type->equal("mesh.static"))
	{
		ret=parseStaticMeshWithScriptFile(script);
	}
	else if(sct_type->equal("mesh.shape"))
	{
	//	ret=parseShapeMeshWithScriptFile(script);
	}
	else if(sct_type->equal("mesh.skeleton"))
	{
	//	ret=parseSkeletonMeshWithScriptFile(script);
	}
	else 
	{
		FS_TRACE_WARN("Can't Sure Mesh Type Here");
	}

	if(script) script->decRef();
	if(sct_type) sct_type->decRef();
	return ret;
error:
	if(script) script->decRef();
	if(sct_type) sct_type->decRef();
	return NULL;
}


static FsBool s_MeshLoadFFlags(FsDict* script,const char* name,FsUlong* fflags)
{
	FsUint i;
	FsString* sct_fflags=ScriptUtil::getString(script,name);
	if(sct_fflags!=NULL)
	{
		const FsChar* chstr=sct_fflags->cstr();
		FsUint chstr_len=((FsString*)sct_fflags)->length();
		for(i=0;i<chstr_len;i++)
		{
			switch(chstr[i])
			{
				case 'f':
					*fflags|=Geometry::F_FACE_BIT;
					break;
				case 'n':
					*fflags|=Geometry::F_NORMAL_BIT;
					break;
				case 'c':
					*fflags|=Geometry::F_COLOR_BIT;
					break;
			}
		}
		sct_fflags->decRef();
	}
	else 
	{
		return false;
	}
	return true;
}

static FsBool s_MeshLoadVFlags(FsDict* script,const char* name,FsUlong* vflags)
{
	FsUint i;
	FsString* sct_vflags=ScriptUtil::getString(script,name);
	if(sct_vflags!=NULL)
	{
		const FsChar* chstr=((FsString*)sct_vflags)->cstr();
		FsUint chstr_len=((FsString*)sct_vflags)->length();
		for(i=0;i<chstr_len;i++)
		{
			switch(chstr[i])
			{
				case 'v':
					*vflags|=Geometry::V_VERTICS_BIT;
					break;
				case 'n':
					*vflags|=Geometry::V_NORMALS_BIT;
					break;
				case 't':
					*vflags|=Geometry::V_TEXCOORDS_BIT;
					break;
				case 'c':
					*vflags|=Geometry::V_COLORS_BIT;
					break;
				case 'w':
					*vflags|=Geometry::V_WEIGHT_BIT;
					break;
			}
		}
		sct_vflags->decRef();
	}
	else 
	{
		return false;
	}

	return true;
}
static FsBool s_GeometryLoadVVertex(Geometry* geo,FsDict* dict,const char* name)
{
	FsArray* sct_vvertex=ScriptUtil::getArray(dict,name);
	Vector3* p_vvertex=geo->vVerticsPointer();
	FS_TRACE_ERROR_ON(p_vvertex==NULL,"Some Bug Happend");
	FsUint vertex_nu=geo->getVertexNu();
	if(sct_vvertex!=NULL)
	{
		FsUint num=sct_vvertex->size()/3;
		if(num>vertex_nu)
		{
			num=vertex_nu;
		}
		for(FsUint j=0;j<num;j++)
		{
			/* get x */
			FsObject* sct_value1=sct_vvertex->get(j*3);
			if(FsString::checkType(sct_value1))
			{
				(p_vvertex+j)->x=ScriptUtil::parseFloat((FsString*)sct_value1);
			}
			/* get y */
			FsObject* sct_value2=sct_vvertex->get(j*3+1);
			if(FsString::checkType(sct_value2))
			{
				(p_vvertex+j)->y=ScriptUtil::parseFloat((FsString*)sct_value2);
			}

			/* get z */
			FsObject* sct_value3=sct_vvertex->get(j*3+2);
			if(FsString::checkType(sct_value3))
			{
				(p_vvertex+j)->z=ScriptUtil::parseFloat((FsString*)sct_value3);
			}
			sct_value1->decRef();
			sct_value2->decRef();
			sct_value3->decRef();
		}
		sct_vvertex->decRef();
	}
	else 
	{
		return false;
	}
	return true;
}
static FsBool s_GeometryLoadVNormal(Geometry* geo,FsDict* dict,const char* name)
{
	FsArray* sct_vnormal=ScriptUtil::getArray(dict,name);
	Vector3* p_normal=geo->vNormalsPointer();
	FsUint vertex_nu=geo->getVertexNu();
	if(sct_vnormal!=NULL)
	{
		FsUint num=sct_vnormal->size()/3;
		if(num>vertex_nu)
		{
			num=vertex_nu;
		}
		for(FsUint j=0;j<num;j++)
		{
			/* get x */
			FsObject* sct_value1=sct_vnormal->get(j*3);
			if(FsString::checkType(sct_value1))
			{
				(p_normal+j)->x=ScriptUtil::parseFloat((FsString*)sct_value1);
			}
			/* get y */
			FsObject* sct_value2=sct_vnormal->get(j*3+1);
			if(FsString::checkType(sct_value2))
			{
				(p_normal+j)->y=ScriptUtil::parseFloat((FsString*)sct_value2);
			}
			/* get z */
			FsObject* sct_value3=sct_vnormal->get(j*3+2);
			if(FsString::checkType(sct_value3))
			{
				(p_normal+j)->z=ScriptUtil::parseFloat((FsString*)sct_value3);
			}
			sct_value1->decRef();
			sct_value2->decRef();
			sct_value3->decRef();
		}
		sct_vnormal->decRef();
	}
	else 
	{
		return false;
	}
	return true;
}
static FsBool s_GeometryLoadFFace(Geometry* geo,FsDict* dict,const char* name)
{
	FsArray* sct_fface=ScriptUtil::getArray(dict,name);
	Face3* p_face=geo->fFacesPointer();
	FsUint face_nu=geo->getFaceNu();
	if(sct_fface!=NULL)
	{
		FsUint num=sct_fface->size()/3;
		if(num>face_nu)
		{
			num=face_nu;
		}
		for(FsUint j=0;j<num;j++)
		{
			FsObject* sct_value1=sct_fface->get(j*3);
			if(FsString::checkType(sct_value1))
			{
				(p_face+j)->a=ScriptUtil::parseInteger((FsString*)sct_value1);
			}
			/* get y */
			FsObject* sct_value2=sct_fface->get(j*3+1);
			if(FsString::checkType(sct_value2))
			{
				(p_face+j)->b=ScriptUtil::parseInteger((FsString*)sct_value2);
			}
			/* get z */
			FsObject* sct_value3=sct_fface->get(j*3+2);
			if(FsString::checkType(sct_value3))
			{
				(p_face+j)->c=ScriptUtil::parseInteger((FsString*)sct_value3);
			}
			sct_value1->decRef();
			sct_value2->decRef();
			sct_value3->decRef();
		}
		sct_fface->decRef();
	}
	else 
	{
		return false;
	}
	return true;

}
static FsBool s_GeometryLoadVColor(Geometry* geo,FsDict* dict,const char* name)
{
	FsArray* sct_vcolor=ScriptUtil::getArray(dict,name);
	Color* p_color=geo->vColorsPointer();
	FsUint vertex_nu=geo->getVertexNu();
	if(sct_vcolor!=NULL)
	{
		FsUint num=sct_vcolor->size()/4;
		if(num>vertex_nu)
		{
			num=vertex_nu;
		}
		for(FsUint j=0;j<num;j++)
		{
			FsUint value;

			/* get red */
			FsObject* sct_value1=sct_vcolor->get(j*4);
			if(FsString::checkType(sct_value1))
			{
				value=ScriptUtil::parseInteger((FsString*)sct_value1);
				(p_color+j)->r=value>255?255:value;
			}
			/* get green*/
			FsObject* sct_value2=sct_vcolor->get(j*4+1);
			if(FsString::checkType(sct_value2))
			{
				value=ScriptUtil::parseInteger((FsString*)sct_value2);
				(p_color+j)->g=value>255?255:value;
			}
			/* get blue */
			FsObject* sct_value3=sct_vcolor->get(j*4+2);
			if(FsString::checkType(sct_value3))
			{
				value=ScriptUtil::parseInteger((FsString*)sct_value3);
				(p_color+j)->b=value>255?255:value;
			}
			/* get alpha */
			FsObject* sct_value4=sct_vcolor->get(j*4+3);
			if(FsString::checkType(sct_value4))
			{
				value=ScriptUtil::parseInteger((FsString*)sct_value4);
				(p_color+j)->a=value>255?255:value;
			}
			sct_value1->decRef();
			sct_value2->decRef();
			sct_value3->decRef();
			sct_value4->decRef();
		}
		sct_vcolor->decRef();
	}
	else 
	{
		return false;
	}
	return true;

}

Mesh* MeshLoader::parseStaticMeshWithScriptFile(FsDict* script)
{
	FsUint submesh_nu=0;
	FsUlong fflags=0,vflags=0;
	Mesh* ret=NULL;
	FsUint i;

	if(!ScriptUtil::getInteger(script,"meshNu",(FsInt*)&submesh_nu))
	{
		FS_TRACE_WARN("Can't Get \"meshNu\"");
		submesh_nu=0;
	}

	if(!s_MeshLoadFFlags(script,"fflags",&fflags))
	{
		FS_TRACE_WARN("Can't Get \"fflags\"");
		fflags=0;
	}
	if(!s_MeshLoadVFlags(script,"vflags",&vflags))
	{
		FS_TRACE_WARN("Can't Get \"vflags\"");
		vflags=0;
	}

	/* create mesh */
	ret=new Mesh(submesh_nu,Mesh::TYPE_STATIC);

	FsArray* sct_submesh=ScriptUtil::getArray(script,"mesh");
	if(sct_submesh==NULL)
	{
		FS_TRACE_WARN("Can't Get \"mesh\"(Key Not Find)");
		script->decRef();
		return ret;
	}
	if(submesh_nu>sct_submesh->size())
	{
		FS_TRACE_WARN("meshNu is %u,But Only %ld Submesh In Mesh",submesh_nu,sct_submesh->size());
		submesh_nu=sct_submesh->size();
	}


	/* create submesh */
	for(i=0;i<submesh_nu;i++)
	{
		SubMesh* submesh=ret->getSubMesh(i);
		FsUint vertex_nu=0,face_nu=0;
		FsObject* sct_curmesh=sct_submesh->get(i);
		if(!FsDict::checkType(sct_curmesh))
		{
			FS_TRACE_WARN("Submesh is Not Dict Object,Ingore");
			sct_curmesh->decRef();
			continue;
		}

		/* get submesh */
		FsDict* sct_curdict=(FsDict*)sct_curmesh;

		/* load vertex number */
		if(!ScriptUtil::getInteger(sct_curdict,"vertexNu",(FsInt*)&vertex_nu))
		{
			FS_TRACE_WARN("Can't Get \"vertexNu\"");
			vertex_nu=0;
		}
		/* load face number */
		if(!ScriptUtil::getInteger(sct_curdict,"faceNu",(FsInt*)&face_nu))
		{
			FS_TRACE_WARN("Can't Get \"faceNu\"");
			face_nu=0;
		}

		/*TODO(Load Material)*/

		/* load Geometry */
		Geometry* geometry=new Geometry(vertex_nu,face_nu,fflags|vflags);

		/* vflags */
		if(vflags&Geometry::V_VERTICS_BIT) /* load vertex */
		{
			memset(geometry->vVerticsPointer(),0,sizeof(Vector3)*vertex_nu);
			s_GeometryLoadVVertex(geometry,sct_curdict,"vvertex");
		}

		if(vflags&Geometry::V_NORMALS_BIT) /* load normal */
		{
			memset(geometry->vNormalsPointer(),0,sizeof(Vector3)*vertex_nu);
			s_GeometryLoadVNormal(geometry,sct_curdict,"vnormal");
		}
		if(vflags&Geometry::V_TEXCOORDS_BIT) /*load TexCoord*/
		{
		}
		if(vflags&Geometry::V_COLORS_BIT) /*load Color*/
		{
			memset(geometry->vColorsPointer(),0,sizeof(Color)*vertex_nu);
			s_GeometryLoadVColor(geometry,sct_curdict,"vcolor");

		}
		if(vflags&Geometry::V_WEIGHT_BIT) /*load Weight*/
		{

		}

		/* fflags */
		if(fflags&Geometry::F_FACE_BIT)
		{
			memset(geometry->fFacesPointer(),0,sizeof(Face3)*face_nu);
			s_GeometryLoadFFace(geometry,sct_curdict,"fface");
		}
		if(fflags&Geometry::F_NORMAL_BIT)
		{

		}
		if(fflags&Geometry::F_COLOR_BIT)
		{
		}

		submesh->setGeometry(geometry);
		geometry->decRef();


		/*TODO(Set Material)*/;
		sct_curmesh->decRef();
	}
	sct_submesh->decRef();
	return ret;
}


FsBool s_saveMeshWithScript(Mesh* mesh,FsFile* file)
{
	FsInt submesh_nu=mesh->subMeshNu();
	file->writeStr("type:\"mesh.static\"\n");
	file->writeStr("version:\"v1.0\"\n");
	file->writeStr("meshNu:%d\n",submesh_nu);
	file->writeStr("mesh:[\n");
	for(FsInt i=0;i<submesh_nu;i++)
	{
		SubMesh* submesh=mesh->getSubMesh(i);
		Geometry* geometry=submesh->getGeometry();
		if(geometry)
		{
			file->writeStr("\t{\n");
			FsUint vertex_nu=geometry->getVertexNu();
			FsUint face_nu=geometry->getFaceNu();
			file->writeStr("\t\tvertexNu:%d\n",vertex_nu);
			file->writeStr("\t\tfaceNu:%d\n",face_nu);

			Vector3* vvertex=geometry->vVerticsPointer();
			if(vvertex)
			{
				file->writeStr("\t\tvvertex:[");
				for(FsUint j=0;j<vertex_nu;j++)
				{
					Vector3* pv=vvertex+j;
					file->writeStr("%f,%f,%f,",pv->x,pv->y,pv->z);
				}
				file->writeStr("]\n");
			}
			Vector3* vnormal=geometry->vNormalsPointer();
			if(vnormal)
			{
				file->writeStr("\t\tvnormal:[");
				for(FsUint j=0;j<vertex_nu;j++)
				{
					Vector3* pv=vnormal+j;
					file->writeStr("%f,%f,%f,",pv->x,pv->y,pv->z);
				}
				file->writeStr("]\n");
			}

			Face3* faces=geometry->fFacesPointer();
			if(faces)
			{
				file->writeStr("\t\tffaces:[");
				for(FsUint j=0;j<face_nu;j++)
				{
					Face3* pf=faces+j;
					file->writeStr("%u,%u,%u,",pf->a,pf->b,pf->c);
				}
				file->writeStr("]\n");
			}

			file->writeStr("\t},\n");
			geometry->decRef();
		}
	}
	file->writeStr("]\n");
	return true;
}

FsBool MeshLoader::saveMesh(Mesh* mesh,FsFile* file,bool text)
{
	FsBool ret;
	if(text)
	{
		ret=s_saveMeshWithScript(mesh,file);
	}
	else 
	{
	//	ret=s_saveMeshWithBinary(mesh,file);
	}
	return ret;
}

NS_FS_END


























