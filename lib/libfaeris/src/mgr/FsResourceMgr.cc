#include "mgr/FsResourceMgr.h"
#include "mgr/FsResource.h"
#include "support/util/FsPathUtil.h"
#include "sys/io/FsVFS.h"

NS_FS_BEGIN
ResourceMgr::ResourceMgr(ResourceCreateFunc func)
{
	m_func=func;
}


void ResourceMgr::addSearchPath(const char* path)
{
	if(existSearchPath(path))
	{
		return ;
	}
	m_searchPaths.push_back(std::string(path));
}

bool ResourceMgr::existSearchPath(const char* path)
{
	if(pathPos(path)==-1)
	{
		return false;
	}
	return true;

}

void ResourceMgr::removeSearchPath(const char* path)
{
	int pos=pathPos(path);
	if(pos==-1)
	{
		FS_TRACE_WARN("path not found");
	}
	m_searchPaths.erase(m_searchPaths.begin()+pos);
}

Resource* ResourceMgr::load(const char* file_name)
{
	/* file_name is absolute path */
	Resource* ret=NULL;
	if(PathUtil::absolutePath(file_name)) 
	{
		return loadFromPath(file_name);
	}

	/* direct load */
	ret=loadFromPath(file_name);

	if(ret==NULL)
	{
		loadFromSearchPath(file_name);
	}
	return ret;

}

void ResourceMgr::remove(Resource* res)
{
	if(res->m_mgr!=this)
	{
		FS_TRACE_WARN("Resource Is Not Manager");
		return ;
	}

	FsString* key=res->getResourceName();
	assert(key);
	removeCache(key->cstr());
	key->decRef();

}

void ResourceMgr::add(const char* name,Resource* res)
{
	if(res->m_mgr)
	{
		if(res->m_mgr==this)
		{
			FS_TRACE_WARN("Resource Is Aready Manager");
		}
		else 
		{
			FS_TRACE_WARN("Resource Is Manage By Other Manager");
		}
		return;
	}
	FsString* fs_name=FsString::create(name);
	m_caches[fs_name]=res;

	res->m_mgr=this;
	res->setResourceName(fs_name);

	fs_name->decRef();
}


/* protected */
int ResourceMgr::pathPos(const char* path)
{
	std::string path_str(path);
	int pos=-1;
	int path_nu=m_searchPaths.size();

	for(int i=0;i<path_nu;i++)
	{
		if(m_searchPaths[i]==path_str)
		{
			pos=i;
			break;
		}
	}
	return pos;
}

Resource* ResourceMgr::loadFromSearchPath(const char* file_name)
{
	int path_nu=m_searchPaths.size();
	Resource* ret=NULL;
	for( int i=0;i<path_nu;i++)
	{
		std::string load_path=m_searchPaths[i]+std::string(file_name);
		ret=loadFromPath(load_path.c_str());
		if(ret)
		{
			break;
		}
	}
	return ret;
}

void ResourceMgr::removeCache(const char* name)
{
	FsString* fs_name=FsString::create(name);
	m_caches.erase(fs_name);
	fs_name->decRef();
}

Resource* ResourceMgr::findFromCache(FsString* name)
{
	MgrSet::iterator iter=m_caches.find(name);
	if(iter==m_caches.end())
	{
		return NULL;
	}
	return iter->second;
}

Resource* ResourceMgr::loadFromPath(const char* name)
{
	FsString* fs_name=FsString::create(name);
	Resource* ret=findFromCache(fs_name);
	if(ret==NULL)
	{
		FsFile* file=VFS::open(name);
		if(file==NULL)
		{
			ret=NULL;
		}
		else 
		{
			ret=m_func(file);
			FS_SAFE_DEC_REF(file);
			if(ret)
			{
				add(name,ret);
			}
		}
	}
	else 
	{
		FS_SAFE_ADD_REF(ret);
	}
	fs_name->decRef();
	return ret;
}
NS_FS_END




















