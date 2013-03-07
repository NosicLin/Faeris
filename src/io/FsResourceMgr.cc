#include "io/FsResourceMgr.h"
#include "io/FsResource.h"
#include "io/FsVFS.h"

NS_FS_BEGIN
ResourceMgr::ResourceMgr(ResourceCreateFunc func)
{
	m_func=func;
}
void ResourceMgr::addSearchPath(const char* path)
{

}

void ResourceMgr::removeSearchPath(const char* path)
{

}

Resource* ResourceMgr::load(const char* path,bool search_path)
{
	return NULL;
}

void ResourceMgr::remove(Resource* res)
{

}


NS_FS_END

