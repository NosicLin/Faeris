#ifndef _FS_RESOURCE_H_
#define _FS_RESOURCE_H_ 
#include <string>

#include "FsMacros.h"
#include "FsObject.h"
#include "support/util/FsString.h"

NS_FS_BEGIN 
class ResourceMgr;
class Resource :public FsObject
{
	public:
		Resource();
		virtual ~Resource();

	protected:
		void setMgr(ResourceMgr* mgr);
		void setResourceName(FsString* name);
		FsString* getResourceName();

	private:
		ResourceMgr* m_mgr;
		FsString* m_resourceName;

	private:
		friend class ResourceMgr;
};
NS_FS_END

#endif /*_FS_RESOURCE_H_*/

