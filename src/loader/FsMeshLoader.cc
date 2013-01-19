#include <string.h>
#include "loader/FsMeshLoader.h"
#include "loader/FsGeometryLoader.h"
#include "loader/FsMaterialLoader.h"
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
		return createFromScript(file);
	}
	return NULL;
}

Mesh* MeshLoader::loadFromMgr(const char* name)
{
	/*TODO(add real Mgr here)*/
	return create(name);
}

Mesh* MeshLoader::create(const char* filename)
{
	FsFile* file=VFS::open(filename);
	if(file==NULL)
	{
		FS_TRACE_WARN("Load Mesh Failed(File Not Found %s)",filename);
		return NULL;
	}
	Mesh* ret=create(file);
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
		ret=createStaticMeshFromDict(script);
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





Mesh* MeshLoader::createStaticMeshFromDict(FsDict* script)
{
	FsUlong fflags=0,vflags=0;
	Mesh* ret=NULL;
	FsInt i;

	/* create mesh */
	ret=new Mesh(Mesh::TYPE_STATIC);

	FsArray* sct_submesh=ScriptUtil::getArray(script,"mesh");
	if(sct_submesh==NULL)
	{
		FS_TRACE_WARN("Can't Get \"mesh\"(Key Not Find)");
		script->decRef();
		return ret;
	}

	FsInt submesh_nu=sct_submesh->size();

	/* create submesh */
	for(i=0;i<submesh_nu;i++)
	{
		FsDict* sct_curmesh=ScriptUtil::getDict(sct_submesh,i);
		if(sct_curmesh==NULL)
		{
			FS_TRACE_WARN("Submesh is Not Dict Object,Ingore");
			continue;
		}

		Geometry* g=NULL;
		Material* m=NULL;
		FsString* sct_geometry=ScriptUtil::getString(sct_curmesh,"geometry");
		FsString* sct_material=ScriptUtil::getString(sct_curmesh,"material");
		g=GeometryLoader::loadFromMgr(sct_geometry->cstr());
		m=MaterialLoader::loadFromMgr(sct_material->cstr());

		SubMesh* sm=new SubMesh(g,m);

		ret->pushSubMesh(sm);

		sct_curmesh->decRef();
	}

	sct_submesh->decRef();
	return ret;
}

NS_FS_END


























