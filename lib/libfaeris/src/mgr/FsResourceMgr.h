#ifndef _FS_RESOURCE_MGR_H_
#define _FS_RESOURCE_MGR_H_ 

#include <string>
#include <vector>
#include <map>
#include "FsMacros.h"
#include "support/util/FsString.h"
#include "support/util/FsDict.h"

NS_FS_BEGIN
class Resource;
class FsFile;

class ResourceMgr:public FsObject
{
	public:
		class KeyCompare
		{
			public:
				bool operator()(FsString* left,FsString* right) const
				{
					int cmp=left->compare(*right);
					if(cmp<0)
					{
						return true;
					}
					return false;
				}
		};

	public:
		typedef Resource* (*ResourceCreateFunc)(FsFile* file);
		typedef std::map<FsString*,Resource*,KeyCompare> MgrSet;

	public:
		ResourceMgr(ResourceCreateFunc func);
		virtual ~ResourceMgr();
	public:
		void addSearchPath(const char* path);
		bool existSearchPath(const char* path);
		void removeSearchPath(const char* path);

		Resource* load(const char* path);
		void remove(Resource* res);
		void add(const char* name,Resource* res);

	public:
		bool preloadResource(const char* path);
		bool unPreloadResource(const char* path);
		void clearPreloadResource();


	protected:
		int pathPos(const char* path);
		Resource* loadFromSearchPath(const char* path);

		void removeCache(const char* name);
		Resource* loadFromPath(const char* path);
		Resource* findFromCache(FsString* name);

		void clearCache();

	protected:
		ResourceCreateFunc m_func;
		std::vector<std::string> m_searchPaths;
		MgrSet m_caches;

		FsDict* m_preload;
};
NS_FS_END

#endif  /*_FS_RESOURCE_MGR_H_*/



