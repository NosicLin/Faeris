#ifndef _FS_LUA_SYS_EVENT_LISTENER_H_
#define _FS_LUA_SYS_EVENT_LISTENER_H_
#include "FsMacros.h"


NS_FS_BEGIN
class LuaSysEventListener:public  SysEventListener 
{
	public:
		static LuaSysEventListener* create();

	public:
		/* inherit  SysEventListener */
		virtual void foreground();
		virtual void background();
		virtual void exit();
		virtual void quit();


		/* inherit FsObject */
		virtual const char*  className();

	protected:
		LuaSysEventListener();
		~LuaSysEventListener();

};
NS_FS_END

#endif /*_FS_LUA_SYS_EVENT_LISTENER_H_*/


