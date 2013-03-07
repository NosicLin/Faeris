#ifndef _FS_RESOURCE_H_
#define _FS_RESOURCE_H_ 
#include <string>

#include "FsMacros.h"
#include "io/FsResourceMgr.h"
#include "core/FsObject.h"

NS_FS_BEGIN 

class Resource :public FsObject
{
	public:
		Resource();
		virtual ~Resource();
	protected:
		virtual void onDestroy();
		void setMgr(ResourceMgr* mgr){m_mgr=mgr;}
		void setName(const char* name){m_resourceName=std::string(name);}
	private:
		ResourceMgr* m_mgr;
		std::string m_resourceName;
	private:
		friend class ResourceMgr;
};
NS_FS_END

#endif /*_FS_RESOURCE_H_*/

