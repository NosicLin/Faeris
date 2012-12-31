#ifndef _FS_EVENT_LISTENER_H_
#define _FS_EVENT_LISTENER_H_
#include "FsMacros.h"
#include "fsys/FsEvent.h"

NS_FS_BEGIN
class Window;
class EventListener
{
	public:
		virtual void onResize(ResizeEvent* e);
		virtual void onMouse(MouseEvent* e);
		virtual void onMotion(MotionEvent* e);
		virtual void onKey(KeyEvent* e);
		virtual void onTouch(TouchEvent* e);
		virtual void onFocus(FocusEvent* e);
		virtual void onQuit(QuitEvent* e);
		virtual ~EventListener();
};
NS_FS_END

#endif /*_FS_EVENT_LISTENER_H_*/


