#include "fsys/FsEvent.h"
#include "fsys/FsEventListener.h"
NS_FS_BEGIN

void EventListener::onMouse(Window* win,MouseEvent* e){}
void EventListener::onMotion(Window* win,MotionEvent* e){}
void EventListener::onKey(Window* win,KeyEvent *e){}
void EventListener::onTouch(Window* win,TouchEvent* e){}
void EventListener::onFocus(Window* win,FocusEvent* e){}
void EventListener::onQuit(Window* win,QuitEvent* e){}
void EventListener::onResize(Window* win,ResizeEvent* e){}
EventListener::~EventListener(){}

NS_FS_END




