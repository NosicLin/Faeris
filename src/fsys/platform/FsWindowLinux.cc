#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include "GL/glew.h"

#include <GL/glx.h>

#include <string.h>
#include <stdlib.h>

#include "util/FsLog.h"
#include "fsys/FsWindow.h"
#include "fsys/FsFrame.h"
#include "fsys/FsEventDispatcher.h"

#define FS_XWINDOW_EVENT_MASK ( \
		ExposureMask \
		|KeyPressMask \
		|ButtonPressMask \
		|ButtonReleaseMask \
		|ButtonMotionMask \
		|StructureNotifyMask \
		|PointerMotionMask \
		|FocusChangeMask \
		)

NS_FS_BEGIN
typedef ::Window XWindow;
static void s_sendEventToWindow(Window* win,XEvent* src_event);

static const char *event_names[] = {
   "",
   "",
   "KeyPress",
   "KeyRelease",
   "ButtonPress",
   "ButtonRelease",
   "MotionNotify",
   "EnterNotify",
   "LeaveNotify",
   "FocusIn",
   "FocusOut",
   "KeymapNotify",
   "Expose",
   "GraphicsExpose",
   "NoExpose",
   "VisibilityNotify",
   "CreateNotify",
   "DestroyNotify",
   "UnmapNotify",
   "MapNotify",
   "MapRequest",
   "ReparentNotify",
   "ConfigureNotify",
   "ConfigureRequest",
   "GravityNotify",
   "ResizeRequest",
   "CirculateNotify",
   "CirculateRequest",
   "PropertyNotify",
   "SelectionClear",
   "SelectionRequest",
   "SelectionNotify",
   "ColormapNotify",
   "ClientMessage",
   "MappingNotify"
};


class WindowFrameListener;

static Window* s_shareWindow=NULL;
static WindowFrameListener* s_frameListener=NULL;

class PlatformWindow
{
	public:
		XWindow m_X11Window;
		Display* m_dpy;
		GLXContext m_contex;
		Atom m_delete_msg;
		XVisualInfo* m_vi;
		
	protected:
		FsBool initWin();
		FsBool initGL();
	public:
		static PlatformWindow* create();
		PlatformWindow();
		~PlatformWindow();
};

PlatformWindow::PlatformWindow()
{
	m_X11Window=0;
	m_dpy=NULL;
	m_contex=NULL;
	m_delete_msg=0;
}
PlatformWindow::~PlatformWindow()
{
	glXDestroyContext(m_dpy,m_contex);
	XDestroyWindow(m_dpy,m_X11Window);
	XCloseDisplay(m_dpy);
	XFree(m_vi);
}
PlatformWindow* PlatformWindow::create()
{
	PlatformWindow* ret=new PlatformWindow();
	if(!ret->initWin())
	{
		delete ret;
		return NULL;
	}
	return ret;
}

FsBool PlatformWindow::initWin()
{
	m_dpy=XOpenDisplay(NULL);
	if(!m_dpy)
	{
		FS_TRACE_WARN("Can't Connect to x Server ");
		return false;
	}
	m_delete_msg=XInternAtom(m_dpy,"WM_DELETE_WINDOW",False);

	GLint attr[]={GLX_RGBA,GLX_DEPTH_SIZE,24,GLX_DOUBLEBUFFER,None};
	XWindow root;

	XSetWindowAttributes swa;

	root=DefaultRootWindow(m_dpy);
	m_vi=glXChooseVisual(m_dpy,0,attr);
	if(m_vi==NULL)
	{
		FS_TRACE_WARN("No Appropriate Visual Found");
		return false;
	}
	Colormap cmap=XCreateColormap(m_dpy,root,m_vi->visual,AllocNone);
	swa.colormap=cmap;
	swa.event_mask=FS_XWINDOW_EVENT_MASK;
	m_X11Window=XCreateWindow(
			m_dpy,
			root,
			0,0,600,600,
			0,m_vi->depth,
			InputOutput,
			m_vi->visual,
			CWColormap|CWEventMask,&swa);

	XSetWMProtocols(m_dpy, m_X11Window, &m_delete_msg, 1);

	if(!initGL())
	{
		return false;
	}

	XSync(m_dpy,false);
	return true;
}
FsBool PlatformWindow::initGL()
{
	m_contex=glXCreateContext(m_dpy,m_vi,NULL,GL_TRUE);
	glXMakeCurrent(m_dpy,m_X11Window,m_contex);
	const GLubyte* gl_version=glGetString(GL_VERSION);
	GLenum ret=glewInit();
	FsUtil_Log("OpenGL Version=%s",gl_version);
	if(atof((FsChar*)gl_version)<1.5)
	{
		char str_compain[256]={0};
		sprintf(str_compain,"OpenGL 1.5 or higher is required(your version is %s), \
				please upgrade the driver of your video card",gl_version);
		FsUtil_Log("%s",str_compain);
		return false;
	}
	if(ret!=GLEW_OK)
	{
		FsUtil_Log("Init Glew Failed %s",glewGetErrorString(ret));
		return false;
	}
	return true;
}



class WindowFrameListener:public FrameListener
{
	public:
		virtual void frameBegin(FsLong diff)
		{
			if(!s_shareWindow)
			{
				return ;
			}
			PlatformWindow* plt_window=s_shareWindow->getPlatformWindow();
			if(!plt_window)
			{
				return ;
			}
			Display* dpy=plt_window->m_dpy;
			XEvent event;
			XSync(dpy,false);
			while(XEventsQueued(dpy,QueuedAfterReading))
			{
				XNextEvent(dpy,&event);
				s_sendEventToWindow(s_shareWindow,&event);
			}
		}
};


static void s_sendEventToWindow(Window* win,XEvent* src_event)
{
	PlatformWindow* plt_window=win->getPlatformWindow();
	EventDispatcher* dispatcher=EventDispatcher::shareEventDispatcher();
	printf("handle event \n");

	if(!plt_window)
	{
		return ;
	}

	switch(src_event->type)
	{
		case ClientMessage:
			{
				if((Atom)(src_event->xclient.data.l[0])==plt_window->m_delete_msg)
				{
					QuitEvent event;
					dispatcher->dispatchEvent(&event);
				}
				break;
			}
		case ConfigureNotify:
			{
				FsUint width,height;
				width=src_event->xconfigure.width;
				height=src_event->xconfigure.height;
				ResizeEvent event(width,height); 
				dispatcher->dispatchEvent(&event);
				break;
			}
		case ButtonPress:
			{
				XButtonEvent* e=(XButtonEvent*) src_event;
				FsInt button;
				switch(e->button)
				{
					case  Button1:
						button=FS_LBUTTON;
						break;
					case Button2:
						button=FS_MBUTTON;
						break;
					case Button3:
						button=FS_RBUTTON;
						break;
					default:
						/*FIXME if middle button rool,it will used button4 or button5*/
						button=0;
						FS_TRACE_WARN("Unkown Button Type");
						break;
				}
				FsUint mask=0;
				FsUint xmask=e->state;
				if(xmask&ControlMask) mask|=FS_MASK_CTRL;
				if(xmask&ShiftMask) mask|=FS_MASK_SHIFT;
				MouseEvent event(button,FS_DOWN,mask,e->x,e->y);
				dispatcher->dispatchEvent(&event);
				break;
			}
		case ButtonRelease:
			{
				XButtonEvent* e=(XButtonEvent*) src_event;
				FsInt button;
				switch(e->button)
				{
					case  Button1:
						button=FS_LBUTTON;
						break;
					case Button2:
						button=FS_MBUTTON;
						break;
					case Button3:
						button=FS_RBUTTON;
						break;
					default:
						button=0;
						FS_TRACE_WARN("Unkown Button Type");
						break;
				}
				FsUint mask=0;
				FsUint xmask=e->state;
				if(xmask&ControlMask) mask|=FS_MASK_CTRL;
				if(xmask&ShiftMask) mask|=FS_MASK_SHIFT;
				MouseEvent event(button,FS_UP,mask,e->x,e->y);
				dispatcher->dispatchEvent(&event);
				break;
			}
		case MotionNotify:
			{
				XMotionEvent* e=(XMotionEvent*) src_event;
				FsUint mask=0;
				FsUint xmask=e->state;
				if(xmask&Button1Mask) mask|=FS_MASK_LBUTTON;
				if(xmask&Button2Mask) mask|=FS_MASK_MBUTTON;
				if(xmask&Button3Mask) mask|=FS_MASK_RBUTTON;
				if(xmask&ControlMask) mask|=FS_MASK_CTRL;
				if(xmask&ShiftMask) mask|=FS_MASK_SHIFT;
				MotionEvent event(mask,e->x,e->y,0,0);
				dispatcher->dispatchEvent(&event);
				break;
			}
		case FocusIn:
			{
				FocusEvent event(true);
				dispatcher->dispatchEvent(&event);
				break;
			}
		case FocusOut:
			{
				FocusEvent event(false);
				dispatcher->dispatchEvent(&event);
				break;
			}
		case DestroyNotify:
			{
				break;
			}

		case KeyPress:
			/*TODO*/
			break;
		default:
			FS_TRACE_WARN("Unkown XEvent(%s)",event_names[src_event->type]);
	}
}



Window* Window::shareWindow()
{
	if(s_shareWindow==NULL)
	{
		PlatformWindow* plt_window=PlatformWindow::create();
		if(!plt_window)
		{
			FS_TRACE_WARN("Create PlatformWindow Failed");
			return NULL;
		}
		s_shareWindow=new Window;
		s_shareWindow->m_window=plt_window;
		s_frameListener=new WindowFrameListener;
		Frame::shareFrame()->addListener(s_frameListener);
		FS_ASSERT(s_shareWindow);
	}
	return s_shareWindow;
}

void Window::purgeShareWindow()
{
	if(s_shareWindow)
	{
		Frame::shareFrame()->removeListener(s_frameListener);
		delete s_frameListener;
		s_frameListener=NULL;
		delete s_shareWindow;
		s_shareWindow=NULL;
	}
}


void Window::setCaption(const FsChar* name)
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return ;
	}
	XStoreName(m_window->m_dpy,m_window->m_X11Window,name);
	m_caption=std::string(name);
}

void Window::setPosition(FsInt x,FsInt y)
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return ;
	}
	XMoveWindow(m_window->m_dpy,m_window->m_X11Window,x,y);
}

void Window::setSize(FsUint width,FsUint height)
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return ;
	}
	XResizeWindow(m_window->m_dpy,m_window->m_X11Window,width,height);
}

void Window::show()
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return ;
	}
	XMapWindow(m_window->m_dpy,m_window->m_X11Window);

}
void Window::hide()
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return ;
	}
	XUnmapWindow(m_window->m_dpy,m_window->m_X11Window);
}

FsInt Window::getWidth()
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return 0;
	}
	FsInt x,y;
	FsUint width,height;
	FsUint border;
	FsUint depth;
	::Window w;
	XGetGeometry(m_window->m_dpy,m_window->m_X11Window,&w,
			&x,&y,&width,&height,&border,&depth);
	return width;
}
FsInt Window::getHeight()
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return 0;
	}
	FsInt x,y;
	FsUint width,height;
	FsUint border;
	FsUint depth;
	XWindow w;
	XGetGeometry(m_window->m_dpy,m_window->m_X11Window,&w,
			&x,&y,&width,&height,&border,&depth);
	return width;
}
FsInt Window::getPosX()
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return 0;
	}
	FsInt x,y;
	FsUint width,height;
	FsUint border;
	FsUint depth;
	XWindow w;
	XGetGeometry(m_window->m_dpy,m_window->m_X11Window,&w,
			&x,&y,&width,&height,&border,&depth);
	return x;
}
FsInt Window::getPosY()
{
	if(!m_window)
	{
		FS_TRACE_WARN("X11 Window Already Destroy");
		return 0;
	}
	FsInt x,y;
	FsUint width,height;
	FsUint border;
	FsUint depth;
	XWindow w;
	XGetGeometry(m_window->m_dpy,m_window->m_X11Window,&w,
			&x,&y,&width,&height,&border,&depth);
	return y;
}


void Window::makeCurrent(Render* r)
{
	if(m_window)
	{
		//glXMakeCurrent(m_window->m_dpy,m_window->m_X11Window,m_window->m_contex);
	}
	m_render=r;
}

void Window::loseCurrent(Render* r)
{
	if(m_window)
	{
		//glXMakeCurrent(m_window->m_dpy,None,m_window->m_contex);
	}
	m_render=NULL;
}

void Window::swapBuffers()
{
	if(m_window)
	{
		glXSwapBuffers(m_window->m_dpy,m_window->m_X11Window);
	}
}
Window::~Window()
{
	if(m_render)
	{
		m_render->setRenderTarget(NULL);
		m_render=NULL;
	}
	delete m_window;
	m_window=NULL;

}

NS_FS_END

















