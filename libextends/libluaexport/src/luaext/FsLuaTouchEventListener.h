#ifndef _FS_LUA_TOUCH_EVENT_LISTENER_H_
#define _FS_LUA_TOUCH_EVENT_LISTENER_H_

#include "FsMacros.h"
#include "event/FsTouchDispatcher.h"

NS_FS_BEGIN
class LuaTouchEventListener:public TouchEventListener
{
	public:
		static LuaTouchEventListener* create();

	public:
		virtual void onTouchEvent(TouchEvent* event);
	public:
		/* multi touch */
		void touchesBegin(TouchEvent* event);
		void touchesPointerDown(TouchEvent* event);
		void touchesMove(TouchEvent* event);
		void touchesPointerUp(TouchEvent* event);
		void touchesEnd(TouchEvent* event);

		/*  single touch */
		void touchBegin(TouchEvent* event);
		void touchMove(TouchEvent* event);
		void touchEnd(TouchEvent* event);

	public:
		virtual const char* className();
};
NS_FS_END

#endif /*_FS_LUA_TOUCH_EVENT_LISTENER_H_*/


