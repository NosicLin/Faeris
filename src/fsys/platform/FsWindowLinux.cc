#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <GL/glx.h>

#include "core/FsWindow.h"
#include "core/FsFrame.h"

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

typedef ::Window XWindow;

FAERIS_NAMESPACE_BEGIN

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

static void s_sendEventToWindow(Window* win,XEvent* src_event);
class WindowFrameListener;

static WindowFrameListener* s_listener=NULL;
static Display* s_dpy=NULL;
static FsInt s_module_ref_nu=0;
Atom s_wm_delete_msg;
static std::vector<Window*> s_wins;

class PlatformWindow
{
	public:
		XWindow m_X11Window;
		Display* m_dpy;
		GLXContext m_contex;
};

static Display* s_X11GetDisplay()
{
	if(s_dpy==NULL)
	{
		s_dpy=XOpenDisplay(NULL);
		if(s_dpy==NULL)
		{
			FS_TRACE_WARN("Can't Connect to X  Server");
		}
		s_wm_delete_msg= XInternAtom(s_dpy, "WM_DELETE_WINDOW", False);
	}
	return s_dpy;
}

static void s_ModuleAddRef()
{
	s_module_ref_nu++;
}
static void s_ModuleDecRef()
{
	s_module_ref_nu--;
	FS_TRACE_ERROR_ON(s_module_ref_nu<0,"Some Error Ref Happend");
	if(s_module_ref_nu<=0)
	{
		XCloseDisplay(s_dpy);
	}
}

class WindowFrameListener:public FrameListener
{
	public:
		virtual void frameBegin(FsLong now,FsLong diff)
		{
			s_ModuleAddRef();
			Display* dpy=s_X11GetDisplay();
			XEvent event;
			XSync(dpy,false);
			while(XEventsQueued(dpy,QueuedAfterReading))
			{
				XNextEvent(dpy,&event);
				std::vector<Window*>::iterator iter;
				for(iter=s_wins.begin();iter<s_wins.end();++iter)
				{
					if(event.xany.window==(*iter)->getPlatformWindow()->m_X11Window)
					{
						s_sendEventToWindow(*iter,&event);
						break;
					}
					/*
					FS_TRACE_ERROR("Failed To Find a Event(%s) Match A Window(%ld)\n",
							event_names[event.type],
							event.xany.window);
							*/
				}
			}
			s_ModuleDecRef();
		}
};


static void s_RegisterWindow(Window* win)
{
	if(s_wins.size()==0)
	{
		s_listener=new WindowFrameListener;
		Frame::instance()->addListener(s_listener);
	}
	s_wins.push_back(win);
}

static void s_UnRegisterWindow(Window* win)
{
	std::vector<Window*>::iterator iter;
	for(iter=s_wins.begin();iter<s_wins.end();++iter)
	{
		if((*iter)==win)
		{
			s_wins.erase(iter);
			break;
		}
	}
	if(s_wins.size()==0)
	{
		Frame::instance()->removeListener(s_listener);
		delete s_listener;
		s_listener=NULL;
		Frame::instance()->stop();
	}
}

static void s_sendEventToWindow(Window* win,XEvent* src_event)
{
	switch(src_event->type)
	{
		case ClientMessage:
			{
				printf("client message\n");
				if((Atom)(src_event->xclient.data.l[0])==s_wm_delete_msg)
				{
					QuitEvent event;
					win->handleEvent(&event);
				}
				break;
			}
		case ConfigureNotify:
			{
				FsUint width,height;
				width=src_event->xconfigure.width;
				height=src_event->xconfigure.height;
				ResizeEvent event(width,height); 
				win->handleEvent(&event);
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
				win->handleEvent(&event);
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
				win->handleEvent(&event);
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
				win->handleEvent(&event);
				break;
			}
		case FocusIn:
			{
				FocusEvent event(true);
				win->handleEvent(&event);
				break;
			}
		case FocusOut:
			{
				FocusEvent event(false);
				win->handleEvent(&event);
				break;
			}
		case DestroyNotify:
			{
				printf("window kill\n");
				break;
			}

		case KeyPress:
			/*TODO*/
			break;
		default:
			FS_TRACE_WARN("Unkown XEvent(%s)",event_names[src_event->type]);
	}
}



bool Window::init(FsLong flags)
{
	GLint attr[]={GLX_RGBA,GLX_DEPTH_SIZE,24,GLX_DOUBLEBUFFER,None};
	XWindow win,root;
	GLXContext glc;
	XSetWindowAttributes swa;

	Display* dpy=s_X11GetDisplay();
	if(dpy==NULL)
	{
		return 0;
	}
	root=DefaultRootWindow(dpy);
	XVisualInfo* vi=glXChooseVisual(dpy,0,attr);
	if(vi==NULL)
	{
		FS_TRACE_WARN("No Appropriate Visual Found");
		return 0;
	}
	Colormap cmap=XCreateColormap(dpy,root,vi->visual,AllocNone);
	swa.colormap=cmap;
	swa.event_mask=FS_XWINDOW_EVENT_MASK;
	win=XCreateWindow(dpy,root,0,0,600,600,0,vi->depth,InputOutput,vi->visual,
			CWColormap|CWEventMask,&swa);

	XSetWMProtocols(dpy, win, &s_wm_delete_msg, 1);

	glc=glXCreateContext(dpy,vi,NULL,GL_TRUE);

	PlatformWindow* platwin=new PlatformWindow;
	m_caption=std::string("Untitled Window");

	platwin->m_X11Window=win;
	platwin->m_dpy=dpy;
	platwin->m_contex=glc;

	m_window=platwin;
	s_ModuleAddRef();
	s_RegisterWindow(this);
	return true;
}

Window* Window::create(FsLong flags)
{
	Window* win=new Window(flags);
	if(!win->m_window)
	{
		delete win;
		return NULL;
	}
	return win;
}
Window::Window(FsLong flags)
{
	m_render=NULL;
	m_window=NULL;
	init(flags);
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

Window::~Window()
{
	destroy();
}

void Window::destroy()
{
	if(m_render)
	{
		m_render->setRenderTarget(NULL);
		m_render=NULL;
	}
	if(m_window)
	{
		s_UnRegisterWindow(this);
		glXDestroyContext(m_window->m_dpy,m_window->m_contex);
		XDestroyWindow(m_window->m_dpy,m_window->m_X11Window);
		XSync(m_window->m_dpy,false);
		delete m_window;
		m_window=NULL;
		s_ModuleDecRef();
	}
}


void Window::makeCurrent(Render* r)
{
	if(m_window)
	{
		glXMakeCurrent(m_window->m_dpy,m_window->m_X11Window,m_window->m_contex);
	}
	m_render=r;
}

void Window::loseCurrent(Render* r)
{
	if(m_window)
	{
		glXMakeCurrent(m_window->m_dpy,None,NULL);
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


FAERIS_NAMESPACE_END


















