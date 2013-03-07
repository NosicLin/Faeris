#include <string.h>
#include "loader/FsMeshLoader.h"
#include "loader/FsGeometryLoader.h"
#include "loader/FsMaterialLoader.h"
#include "util/FsScriptUtil.h"
#include "model/FsGeometry.h"
#include "io/FsVFS.h"
#include "io/FsResourceMgr.h"

NS_FS_BEGIN
static bool s_isBinaryFile(FsFile* file)
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
	Mesh* ret=NULL;

	Geometry* g=NULL;
	Material* m=NULL;
	FsString* sct_geometry=ScriptUtil::getString(script,"geometry");
	if(sct_geometry)
	{
		g=ResourceMgr::loadGeometry(sct_geometry->cstr());
		sct_geometry->decRef();
	}
	FsString* sct_material=ScriptUtil::getString(script,"material");
	if(sct_material)
	{

		m=ResourceMgr::loadMaterial(sct_material->cstr());
		sct_material->decRef();
	}

	ret=new Mesh(g,m);
	return ret;
}

NS_FS_END


























