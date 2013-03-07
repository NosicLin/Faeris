#include "sys/FsEvent.h"
#include "sys/FsEventListener.h"
NS_FS_BEGIN

void EventListener::onMouse(MouseEvent* e){}
void EventListener::onMotion(MotionEvent* e){}
void EventListener::onKey(KeyEvent *e){}
void EventListener::onTouch(TouchEvent* e){}
void EventListener::onFocus(FocusEvent* e){}
void EventListener::onQuit(QuitEvent* e){}
void EventListener::onResize(ResizeEvent* e){}
EventListener::~EventListener(){}

NS_FS_END




