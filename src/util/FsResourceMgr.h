#ifndef _FS_RESOURCE_MGR_H_
#define _FS_RESOURCE_MGR_H_ 

#include <string>
#include <vector>
#include <map>
#include "FsMacros.h"

FAERIS_NAMESPACE_BEGIN
class Resource;
class FsFile;
class ResourceMgr 
{
	public:
		typedef Resource* (*NeedCreateFunc)(FsFile* file);
	public:
		ResourceMgr(NeedCreateFunc func);
	public:
		void addSearchPath(const FsChar* path);
		bool existSearchPath(const FsChar* path);
		void removeSearchPath(const FsChar* path);

		Resource* load(const FsChar* path,FsBool search_path=true);
		void remove(Resource* res);

	private:
		NeedCreateFunc m_func;
		std::vector<std::string> m_searchPath;

		FsInt m_resNu;
		std::map<std::string,Resource*> m_resources;
};
FAERIS_NAMESPACE_END
#endif  /*_FS_RESOURCE_MGR_H_*/


