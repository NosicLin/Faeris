#ifndef _FS_TOUCH_DISPATCHER_H_
#define _FS_TOUCH_DISPATCHER_H_
#include "FsMacros.h"
#include "event/FsTEventDispatcher.h"


NS_FS_BEGIN

class TouchPoint
{
	public:
		int id;
		float x;
		float y;
};

class TouchEvent 
{
	public:
		TouchEvent(int type,int point_nu,TouchPoint* points);
		~TouchEvent();
	public:
		const TouchPoint* getPoints(){return m_points;}
		int getPointsNu(){return m_count;}
		int getType(){return m_type;}

	private:
		int m_type;
		int m_count;
		TouchPoint* m_points;
};

class TouchEventListener:public FsObject
{
	public:
		TouchEventListener* create();

	protected:
		TouchEventListener();
		virtual ~TouchEventListener();

	public:
		void handleEvent(TouchEvent* event)
		{
			onTouchEvent(event);
		}

	public:
		virtual void onTouchEvent(TouchEvent* event);

		/* inherit FsObject */
		virtual const char* className();
};


class TouchDispatcher:public TEventDispatcher<TouchEvent,TouchEventListener>
{
	public:
		enum 
		{
			TOUCHES_BEGIN,
			TOUCHES_POINTER_UP,
			TOUCHES_MOVE,
			TOUCHES_POINTER_DOWN,
			TOUCHES_END,
			TOUCHES_CANCEL,
		};

	public:
		static TouchDispatcher* create();

		/* inherit FsObject */
		const char* className() ;

};
NS_FS_END
#endif /*_FS_TOUCH_DISPATCHER_H_*/









