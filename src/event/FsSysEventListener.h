#ifndef _FS_SYS_EVENT_LISTENER_H_
#define _FS_SYS_EVENT_LISTENER_H_
#include "FsMacros.h"
#include "core/FsObject.h"

NS_FS_BEGIN
class SysEventListener:public FsObject 
{
	public:
		SysEventListener* create();

	protected:
		SysEventListener();
		virtual ~SysEventListener();
	public:
		virtual void foreground();
		virtual void background();
		virtual void quit();
		virtual void exit();

	public:
		/* inherit FsObject */
		virtual const char* className();
};
NS_FS_END

#endif /*_FS_SYS_EVENT_LISTENER_H_*/


