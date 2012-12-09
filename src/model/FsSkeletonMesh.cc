#include "model/FsSkeletonMesh.h"

FAERIS_NAMESPACE_BEGIN 

static ResourceMgr* s_skeleton_mesh_mgr=NULL;
static ResourceMgr* s_getMgr()
{
	if(s_skeleton_mesh_mgr==NULL)
	{
		s_skeleton_mesh_mgr=new ResourceMgr((ResourceMgr::NeedCreateFunc)SkeletonMesh::create);
	}
}

ResourceMgr* SkeletonMesh::getMgr() 
{
	return s_getMgr();
}

SkeletonMesh::create(FsFile* file)
{
	SkeletonMesh* mesh=SkeletonMeshUtil::loadSkt(file);
	if(mesh==NULL)
	{
		FS_TRACE_WARN("Create SkeletonMesh Failed");
		return NULL;
	}
	return mesh;
}

SkeletonMesh::loadFromMgr(const FsChar* filename)
{
	ResourceMgr* mgr=s_getMgr();
	SkeletonMesh* mesh=(SkeletonMesh*)mgr->load(filename);
	return mesh;
}

FAERIS_NAMESPACE_END 



