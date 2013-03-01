#ifndef _FS_RESOURCE_MGR_H_
#define _FS_RESOURCE_MGR_H_ 

#include <string>
#include <vector>
#include <map>
#include "FsMacros.h"

NS_FS_BEGIN
class Resource;
class FsFile;
class ResourceMgr 
{
	public:
		typedef Resource* (*ResourceCreateFunc)(FsFile* file);
	public:
		ResourceMgr(ResourceCreateFunc func);
	public:
		void addSearchPath(const FsChar* path);
		bool existSearchPath(const FsChar* path);
		void removeSearchPath(const FsChar* path);
		Resource* load(const FsChar* path,FsBool search_path=true);
		void remove(Resource* res);
		void setResouceRoot(const FsChar* path);
	private:
		ResourceCreateFunc m_func;
};
NS_FS_END
#endif  /*_FS_RESOURCE_MGR_H_*/


