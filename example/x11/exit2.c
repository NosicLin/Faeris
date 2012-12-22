#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <X11/Xutil.h>

int main(int argc, char *argv[])
{
	Display *d = NULL;
	Window w,root;
	XEvent e;
	char *msg = "Hello World!";
	int s;
	bool done = false;
	XSizeHints *hints;
	Visual *vi;
	unsigned long cw_mask = CWEventMask | CWColormap | CWOverrideRedirect;
	XSetWindowAttributes swa;
	d = XOpenDisplay(NULL);
	if(d == NULL)
	{
		perror("Cannot open Display\n");
		exit(0);
	}
	s = DefaultScreen(d);
	root = DefaultRootWindow(d);
	vi = DefaultVisual(d,s);
	swa.override_redirect = True;
	swa.event_mask=ExposureMask;
	swa.colormap = XCreateColormap(d,root,vi,AllocNone);
	 w = XCreateSimpleWindow(d,RootWindow(d,s),100,100,1024,768,100,BlackPixel(d,s),WhitePixel(d,s));
	w = XCreateWindow(d,root,200,200,400,400,0,24,InputOutput,vi,cw_mask,&swa);
	hints = XAllocSizeHints();
	hints->flags = PSize;
	//XSetWMNormalHints(d,w,hints);

	Atom wmDeleteMessage =XInternAtom(d,"WM_DELETE_WINDOW",False);
	XSetWMProtocols(d,w,&wmDeleteMessage,1);
	XSelectInput(d,w,ExposureMask|KeyPressMask|StructureNotifyMask);
	XMapWindow(d,w);
	while(!done)
	{
		XNextEvent(d,&e);
		if(e.type == Expose)
		{
			//XFillRectangle(d,w,DefaultGC(d,s),20,20,100,100);
			//XDrawString(d,w,DefaultGC(d,s),50,50,msg,strlen(msg));
		}
		switch(e.type)
		{
			case KeyPress:
				XDestroyWindow(d,w);
				break;
			case DestroyNotify:
				done = true;
				break;
			case ClientMessage:
				if(e.xclient.data.l[0] == wmDeleteMessage)
				{
					done = true;
				}
				break;
		}
	}
	XCloseDisplay(d);
	return 0;
}

