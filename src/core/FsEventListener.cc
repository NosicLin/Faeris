#include "core/FsEvent.h"
#include "core/FsEventListener.h"
FAERIS_NAMESPACE_BEGIN

void EventListener::onMouse(Window* win,MouseEvent* e){}
void EventListener::onMotion(Window* win,MotionEvent* e){}
void EventListener::onKey(Window* win,KeyEvent *e){}
void EventListener::onTouch(Window* win,TouchEvent* e){}
void EventListener::onFocus(Window* win,FocusEvent* e){}
void EventListener::onQuit(Window* win,QuitEvent* e){}
void EventListener::onResize(Window* win,ResizeEvent* e){}
EventListener::~EventListener(){}

FAERIS_NAMESPACE_END




