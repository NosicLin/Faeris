#include "util/FsResourceMgr.h"
#include "util/FsResource.h"

NS_FS_BEGIN
Resource::Resource()
{
	m_mgr=NULL;
}

Resource::~Resource() {}

void Resource::onDestroy()
{
	if(m_mgr)
	{
		m_mgr->remove(this);
	}
	delete this;
}
NS_FS_END

