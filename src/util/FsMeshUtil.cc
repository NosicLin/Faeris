#include "util/FsMeshUtil.h"
#include "util/FsScriptUtil.h"

static FsBool s_isBinaryFile(FsFile* file)
{
	return false;
}

Mesh* MeshUtil::loadMesh(FsFile* file)
{
	if(s_isBinaryFile(file))
	{
		return s_loadMeshWithBinaryFile(file);
	}
	else 
	{
		return s_loadMeshWithScriptFile(file);
	}
}

Mesh* MeshUtil::loadMeshWithScriptFile(FsFile* file)
{
	Mesh* ret=NULL;
	FsDict* script=NULL;
	FsObject* type=NULL;
	FsString* str_type=NULL;

	script=ScriptUtil::parseScript(file);

	if(script==NULL)
	{
		FS_TRACE_WARN("ParseScript Failed");
		goto error;
	}
	type=script->lookup("type");
	if(type==NULL)
	{
		FS_TRACE_WARN("Script Doesn't Have Mesh Infor");
		goto error;
	}
	if(!FsString::checkType(type))
	{
		FS_TRACE_WARN("Can't Sure Mesh Type Here");
		goto error;
	}
	str_type=(FsString*)type;

	if(str_type->equal("mesh.static"))
	{
		ret=parseStaticMeshWithScriptFile(script);
	}
	else if(str_type->equal("mesh.shape"))
	{
		ret=parseShapeMeshWithScriptFile(script);
	}
	else if(str_type->equal("mesh.skeleton"))
	{
		ret=parseSkeletonMeshWithScriptFile(script);
	}
	else 
	{
		FS_TRACE_WARN("Can't Sure Mesh Type Here");
	}
	if(script) script->decRef();
	if(type) type->decRef();
	return ret;
error:
	if(script) script->decRef();
	if(type) type->decRef();
	return NULL;
}

Mesh* MeshUtil::parseStaticMeshWithScriptFile(FsDict* script)
{
	FsUint submesh_nu;
	FsUlong fflags,vflags;
	Mesh* ret=NULL;
	FsUint i;

	/* get sub mesh number */
	FsObject* sct_mesh_nu=script->lookup("meshNu");
	if(src_mesh_nu!=NULL)
	{
		if(!FsString:checkType(sct_mesh_nu))
		{
			FS_TRACE_WARN("Can't Get \"meshNu\"");
			submesh_nu=0;
		}
		else 
		{
			submesh_nu=FsScriptUtil::parseInt((FsString*)scr_mesh_nu);
		}
		sct_mesh_nu->decRef();
		sct_mesh_nu=NULL;

	}
	else 
	{
		FS_TRACE_WARN("Can't Get \"meshNu\"");
		submesh=0;
	}
	sct_mesh_nu=NULL;

	/* get fflags */
	FsObject* sct_fflags=script->lookup("fflags");
	if(sct_fflags!=NULL)
	{
		if(!FsString:checkType(sct_mesh_nu))
		{
			FS_TRACE_WARN("Can't Get \"fflags\"(Type Error)");
			fflags=0;
		}
		else 
		{
			const FsChar* chstr=((FsString*)sct_fflags)->cstr();
			FsUint chstr_len=((FsString*)sct_fflags)->length();
			for(i=0;i<chstr_len;i++)
			{
				switch(chstr[i])
				{
					case 'f':
						fflags|=Geometry::F_FACE_BIT;
						break;
					case 'n':
						fflags|=Geometry::F_NORMAL_BIT;
						break;
					case 'c':
						fflags|=Geometry::F_COLOR_BIT;
						break;
				}
			}
		}
		sct_fflags->decRef();
		sct_fflags=NULL;
	}
	else 
	{
		FS_TRACE_WARN("Can't Get \"fflags\"(Key Not Find)");
		fflags=NULL;
	}

	/* get vflags */
	FsObject* sct_vflags=script->lookup("vflags");
	if(sct_vflags!=NULL)
	{
		if(!FsString::checkType(sct_vflags))
		{
			FS_TRACE_WARN("Can't Get \"vflags\"(Type Error)");
			vflags=0;
		}
		else 
		{
			const FsChar* chstr=((FsString*)sct_vflags)->cstr();
			FsUint chstr_len=((FsString*)sct_vflags)->length();
			for(i=0;i<chstr_len;i++)
			{
				switch(chstr[i])
				{
					case 'v':
						vflags|=Geometry::V_VERTICS_BIT;
						break;
					case 'n':
						vflags|=Geometry::V_NORMALS_BIT;
						break;
					case 't':
						vflags|=Geometry::V_TEXCOORDS_BIT;
						break;
					case 'c':
						vflags|=Geometry::V_COLORS_BIT;
						break;
				}
			}
		}
		sct_vflags->decRef();
		sct_vflags=NULL;
	}
	else 
	{
		vflags=0;
	}


	/* create mesh */
	ret=new Mesh(src_mesh_nu,Mesh::TYPE_STATIC);

	FsObject* sct_submesh=script->lookup("mesh");
	if(sct_submesh==NULL)
	{
		FS_TRACE_WARN("Can't Get \"mesh\"(Key Not Find)");
		script->decRef();
		return mesh;
	}
	if(!FsArray::checkType(sct_submesh))
	{
		FS_TRACE_WARN("Can't Get \"mesh\"(Type Error)");
		script->decRef();
		sct_submesh->decRef();
		return mesh;
	}

	FsArray* sct_mesharray=(FsArray*)sct_mesharray;
	if(submesh_nu>sct_mesharray->size())
	{
		FS_TRACE_WARN("meshNu is %u,But Only %u Submesh In Mesh",submesh_nu,sct_mesharray->size());
		submesh_nu=sct_mesharray->size();
	}

	/* create submesh */
	for(i=0;i<submesh_nu;i++)
	{
		FsSubMesh* submesh=mesh->getSubMesh(i);
		FsUint vertex_nu,face_nu;
		FsObject* sct_curdict=sct_mesharray->get(i);
		if(FsDict::checkType(sct_curdict))
		{
			FS_TRACE_WARN("Submesh is Not Dict Object,Ingore");
			sct_curdict->decRef();
			continue;
		}

		/* get submesh */
		FsDict* sct_curmesh=(FsDict*)sct_curdict;

		/* load vertex number */
		FsObject* sct_vertex_nu=sct_curmesh->lookup("vertexNu");
		if(sct_vertex_nu!=NULL)
		{
			if(FsString::checkType(sct_vertex_nu))
			{
				vertex_nu=StringUtil::parseInteger((FsString*)sct_vertex_nu);
			}
			else 
			{
				FS_TRACE_WARN("Can't Get \"vertexNu\"(Type Error)");
				vertex_nu=0;
			}
			sct_vertex_nu->decRef();
		}
		else 
		{
			FS_TRACE_WARN("Can't Get \"vertexNu\"(Key Not Find)");
			vertex_nu=0;
		}

		/* load face number */
		FsObject* sct_face_nu=sct_curmesh->lookup("faceNu");
		if(sct_face_nu!=NULL)
		{
			if(FsString::checkType(sct_face_nu))
			{
				face_nu=StringUtil::parseInteger((FsString*)sct_face_nu);
			}
			else 
			{
				FS_TRACE_WARN("Can't Get \"faceNu\"(Type Error)");
				face_nu=0;
			}
			sct_face_nu->decRef();
		}
		else 
		{
			FS_TRACE_WARN("Can't Get \"vertexNu\"(Key Not Find)");
			face_nu=0;
		}
		/*TODO(Load Material)*/

		/* load Geometry */
		Geometry* geometry=new Geometry(vertex_nu,face_nu,fflags&vflags);


		if(vflags&Geometry::V_VERTICS_BIT) /* load vertex */
		{
			FsObject* sct_vertex=sct_curmesh->lookup("vertex");
			Vector3* p_vertex=geometry->vVerticsPointer();
			if(sct_vertex!=NULL)
			{
				if(FsArray::checkType(sct_vertex))
				{
					FsArray* sct_varray=(FsArray*)sct_vertex;
					FsUint num=sct_vertex->size()/3;
					if(num>vertex_nu)
					{
						num=vertex_nu;
					}
					for(FsUint j=0;j<num;j++)
					{
						/* get x */
						FsObject* sct_value1=sct_varray->get(j*3);
						if(FsString::checkType(sct_value1))
						{
							(p_vertex+j)->x=FsScriptUtil::parseFloat((FsString*)sct_value1);
						}
						/* get y */
						FsObject* sct_value2=sct_varray->get(j*3+1);
						if(FsString::checkType(sct_value2))
						{
							(p_vertex+j)->y=FsScriptUtil::parseFloat((FsString*)sct_value2);
						}

						/* get z */
						FsObject* sct_value3=sct_varray->get(j*3+2);
						if(FsString::checkType(sct_value3))
						{
							(p_vertex+j)->z=FsScriptUtil::parseFloat((FsString*)sct_value3);
						}
						sct_value1->decRef();
						sct_value2->decRef();
						sct_value3->decRef();
					}
				}
				else 
				{
					FS_TRACE_WARN("Can't Get \"vertex\"(Type Error)");
				}
				sct_vertex->decRef();
			}
			else 
			{
				FS_TRACE_WARN("Can't Get \"vertex\"(Key Not Find)");
			}
		}

		if(vflags&Geometry::V_NORMALS_BIT) /* load normal */
		{


		}
		if(vflags&Geometry::V_TEXCOORDS_BIT) /*load TexCoord*/
		{

		}
		if(vflags&Geometry::V_COLORS_BIT) /*load Color*/
		{

		}
		if(vflags&Geometry::V_WEIGHT_BIT) /*load Weight*/
		{

		}
		if(fflags&Geometry::F_FACE_BIT)
		{

		}
		if(fflags&Geometry::F_NORMAL_BIT)
		{

		}
		if(fflags&Geometry::F_COLOR_BIT)
		{
		}
	}
}




























