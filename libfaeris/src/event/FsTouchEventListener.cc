#include "event/FsTouchEventListener.h"

NS_FS_BEGIN
const char* TouchEventListener::className() 
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


NS_FS_END
