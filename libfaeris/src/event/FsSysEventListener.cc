

#include "event/FsSysEventListener.h"
NS_FS_BEGIN

SysEventListener* SysEventListener::create()
{
	SysEventListener* ret=new SysEventListener;
	return ret;
}

SysEventListener::SysEventListener() { }
SysEventListener::~SysEventListener() { }

void SysEventListener::foreground() { }
void SysEventListener::background() { }
void SysEventListener::quit() { }
void SysEventListener::exit() { }
const char* SysEventListener::className()
{
	return FS_SYS_EVENT_LISTENER_CLASS_NAME;
}

NS_FS_END



