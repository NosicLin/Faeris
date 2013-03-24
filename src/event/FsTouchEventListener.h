#ifndef _FS_TOUCH_EVENT_LISTENER_H_
#define _FS_TOUCH_EVENT_LISTENER_H_

#include "core/FsObject.h"
class TouchEventListener:public FsObject
{
	public:
		TouchEventListener* create();

	protected:
		TouchEventListener();
		virtual ~TouchEventListener();

	public:
		virtual void touchBegin(float x,float y);
		virtual void touchMove(float x,float y);
		virtual void touchEnd(float x,float y);
		virtual void touchCancel(float x,float y);

		virtual void touchesBegin(Vector2* points,int num);
		virtual void touchesMove(Vector2* points,int num);
		virtual void touchesEnd(Vector2* points,int num);
		virtual void touchesCancel(Vector2* points,int num);

		/* inherit FsObject */
		virtual const char* className()const ;
};

#endif /*_FS_TOUCH_EVENT_LISTENER_H_*/




