#ifndef _FS_LUA_TOUCH_EVENT_LISTENER_H_
#define _FS_LUA_TOUCH_EVENT_LISTENER_H_

#include "FsMacros.h"
#include "event/FsTouchEventListener.h"

NS_FS_BEGIN
class LuaTouchEventListener:public TouchEventListener
{
	public:
		static LuaTouchEventListener* create();

	public:
		virtual void touchBegin(float x,float y);
		virtual void touchMove(float x,float y);
		virtual void touchEnd(float x,float y);
		virtual void touchCancel(float x,float y);

		/* 
		virtual void touchesBegin(Vector2* points,int num);
		virtual void touchesMove(Vector2* points,int num);
		virtual void touchesEnd(Vector2* points,int num);
		virtual void touchesCancel(Vector2* points,int num);
		*/

	public:
		virtual const char* className();
};
NS_FS_END

#endif /*_FS_LUA_TOUCH_EVENT_LISTENER_H_*/


