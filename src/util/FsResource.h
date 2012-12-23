#ifndef _FS_RESOURCE_H_
#define _FS_RESOURCE_H_ 
#include <string>

#include "FsMacros.h"
#include "util/FsResourceMgr.h"
#include "core/FsObject.h"

FAERIS_NAMESPACE_BEGIN 

class Resource :public FsObject
{
	public:
		Resource();
		virtual ~Resource();
	protected:
		virtual void onDestroy();
		void setMgr(ResourceMgr* mgr){m_mgr=mgr;}
		void setName(const FsChar* name){m_resourceName=std::string(name);}
	private:
		ResourceMgr* m_mgr;
		std::string m_resourceName;
	private:
		friend class ResourceMgr;
};
FAERIS_NAMESPACE_END

#endif /*_FS_RESOURCE_H_*/

