#include "core/FsWindow.h"
#include "graphics/FsRender.h"



FAERIS_NAMESPACE_BEGIN
void Window::handleEvent(Event* e)
{
	switch(e->type)
	{
		case Event::MOUSE_EVENT:
			for(Iterator iter=m_listeners.begin();iter!=m_listeners.end();++iter)
			{
				(*iter)->onMouse(this,(MouseEvent*)e);
			}
			break;
		case Event::KEY_EVENT:
			for(Iterator iter=m_listeners.begin();iter!=m_listeners.end();++iter)
			{
				(*iter)->onKey(this,(KeyEvent*)e);
			}
			break;
		case Event::FOCUS_EVENT:
			for(Iterator iter=m_listeners.begin();iter!=m_listeners.end();++iter)
			{
				(*iter)->onFocus(this,(FocusEvent*)e);
			}
			break;
		case Event::QUIT_EVENT:
			if(quit())  /* check weather to quit */
			{
				/* notify listener to quit */
				for(Iterator iter=m_listeners.begin();iter!=m_listeners.end();++iter)
				{
					(*iter)->onQuit(this,(QuitEvent*)e);
				}
				/* destroy resource */
				destroy();
			}
			break;
		case Event::RESIZE_EVENT:
			for(Iterator iter=m_listeners.begin();iter!=m_listeners.end();++iter)
			{
				(*iter)->onResize(this,(ResizeEvent*)e);
			}
			break;
		case Event::MOTION_EVENT:
			for(Iterator iter=m_listeners.begin();iter!=m_listeners.end();++iter)
			{
				(*iter)->onMotion(this,(MotionEvent*)e);
			}
			break;
		default:
			FS_TRACE_WARN("Unkown Event");
	}
}
void Window::addEventListener(EventListener* l)
{
	m_listeners.push_back(l);
}
void Window::removeEventListener(EventListener* l)
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
void Window::dropAllEventListener()
{
	m_listeners.clear();
}
FsBool Window::quit()
{
	return true;
}



FAERIS_NAMESPACE_END

#if FS_PLATFORM_OS(FS_OS_LINUX)
#include "platform/FsWindowLinux.cc"
#else 
#error "Unsupport Platform OS"
#endif 

