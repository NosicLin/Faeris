#include "event/FsTouchEventListener.h"

const char* TouchEventListener::className()const 
{
	return FS_TOUCH_EVENT_LISTENER_CLASS_NAME;
}

TouchEventListener::TouchEventListener()
{

}

TouchEventListener::~TouchEventListener()
{

}


TouchEventListener* TouchEventListener::create()
{
	return new TouchEventListener;
}


void TouchEventListener::touchBegin(float /* x */,float /* y */)
{
}
void TouchEventListener::touchMove(float /* x */,float /* y */)
{
}
void TouchEventListener::touchEnd(float /* x */,float /* y */)
{
}

void TouchEventListener::touchCancel(float /* x */,float /* y */)
{

}

void TouchEventListener::touchesBegin(Vector2* /* points */,int /* num */)
{

}


void TouchEventListener::touchesEnd(Vector2* /* points */,int /* num */)
{

}

void TouchEventListener::touchesMove(Vector2* /* points */,int /* num */)
{

}

void TouchEventListener::touchesCancel(Vector2* /* points */,int /* num */)
{

}


