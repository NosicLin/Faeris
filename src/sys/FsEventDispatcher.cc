#include "fsys/FsEventDispatcher.h"

NS_FS_BEGIN

static EventDispatcher* s_share_event_dispatch=NULL;
EventDispatcher* EventDispatcher::shareEventDispatcher()
{
	if(!s_share_event_dispatch)
	{
		s_share_event_dispatch=new EventDispatcher;
	}
	return s_share_event_dispatch;
}
void EventDispatcher::purgeShareEventDispatcher()
{
	delete s_share_event_dispatch;
}

void EventDispatcher::addEventListener(EventListener* l)
{
	m_listeners.push_back(l);
}

void EventDispatcher::removeEventListener(EventListener* l)
{
	Iterator iter;
	for(iter=m_listeners.begin();iter!=m_listeners.end();++iter)
	{
		if(*iter==l)
		{
			m_listeners.erase(iter);
			break;
		}
	}
}
void EventDispatcher::dropAllEventListener()
{
	m_listeners.clear();
}

void EventDispatcher::dispatchEvent(Event* e)
{
	for(Iterator iter=m_listeners.begin();iter!=m_listeners.end();++iter)
	{
		switch(e->type)
		{
			case Event::MOUSE_EVENT:
				(*iter)->onMouse((MouseEvent*)e);
				break;
			case Event::KEY_EVENT:
				(*iter)->onKey((KeyEvent*)e);
				break;
			case Event::FOCUS_EVENT:
				(*iter)->onFocus((FocusEvent*)e);
				break;
			case Event::QUIT_EVENT:
				(*iter)->onQuit((QuitEvent*)e);
				break;
			case Event::RESIZE_EVENT:
				(*iter)->onResize((ResizeEvent*)e);
				break;
			case Event::MOTION_EVENT:
				(*iter)->onMotion((MotionEvent*)e);
				break;
			default:
				FS_TRACE_WARN("Unkown Event");
		}
	}
}

NS_FS_END
