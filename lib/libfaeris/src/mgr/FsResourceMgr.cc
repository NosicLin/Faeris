#include "mgr/FsResourceMgr.h"
#include "mgr/FsResource.h"
#include "support/util/FsPathUtil.h"
#include "sys/io/FsVFS.h"

NS_FS_BEGIN
ResourceMgr::ResourceMgr(ResourceCreateFunc func)
{
	m_func=func;
	m_preload=FsDict::create();
}


ResourceMgr::~ResourceMgr()
{
	clearCache();
	m_preload->decRef();
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
		FsFile* file=VFS::createFile(name);
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

bool ResourceMgr::preloadResource(const char* path)
{
	FsString* fs_path=FsString::create(path);
	Resource* ret=load(path);

	if(ret)
	{
		m_preload->insert(fs_path,ret);
		FS_SAFE_DEC_REF(fs_path);
		FS_SAFE_DEC_REF(ret);
		return true;
	}
	else 
	{
		FS_SAFE_DEC_REF(fs_path);
		return false;
	}
}


bool ResourceMgr::unPreloadResource(const char* path)
{
	FsString* fs_path=FsString::create(path);
	bool ret=m_preload->remove(fs_path);
	FS_SAFE_DEC_REF(fs_path);
	return ret;
}

int ResourceMgr::getPreloadResourceNu()
{
	return m_preload->size();
}

int ResourceMgr::getCacheResourceNu()
{
	return m_caches.size();
}

void ResourceMgr::clearPreloadResource()
{
	m_preload->clear();
}

void ResourceMgr::clearCache()
{
	MgrSet::iterator iter=m_caches.begin();

	for(;iter!=m_caches.end();++iter)
	{
		iter->second->setMgr(NULL);
	}
	m_caches.clear();

}

void ResourceMgr::dump()
{
	printf("%s Dump Resource Begin\n",className());
	printf("----Cache Resource----\n");
	for(MgrSet::iterator iter=m_caches.begin();iter!=m_caches.end();++iter)
	{
		printf("\t%s\n",iter->first->cstr());
	}
	printf("----Preload Resource----\n");

	FsDict::Iterator iter(m_preload);
	while(!iter.done())
	{
		FsString* key=(FsString*)iter.getKey();
		printf("\t%s\n",key->cstr());
		key->decRef();
		iter.next();
	}


	printf("%s Dump Resource End\n",className());

}


NS_FS_END













