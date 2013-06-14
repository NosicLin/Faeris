#include "event/FsTouchDispatcher.h"
#include "common/FsGlobal.h"

NS_FS_BEGIN


/* touch event */
TouchEvent::TouchEvent(int type,int point_nu,TouchPoint* points)
{
	assert(point_nu>0);
	m_type=type;
	m_points=new TouchPoint[point_nu];

	for(int i=0;i<point_nu;i++)
	{
		m_points[i]=points[i];
	}
	m_count=point_nu;
}
TouchEvent::~TouchEvent()
{
	delete m_points;
	m_points=NULL;
}


TouchEventListener* TouchEventListener::create()
{
	return new TouchEventListener;
}

TouchEventListener::TouchEventListener() { }
TouchEventListener::~TouchEventListener() {} 
void TouchEventListener::onTouchEvent(TouchEvent* event){}

const char* TouchEventListener::className()
{
	return FS_TOUCH_EVENT_LISTENER_CLASS_NAME;
}



const char* TouchDispatcher::className()  
{
	return FS_TOUCH_DISPATCHER_CLASS_NAME;
}

TouchDispatcher* TouchDispatcher::create()
{
	return new TouchDispatcher();
}






NS_FS_END








