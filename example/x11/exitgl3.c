/*                   iobounce.c:
 *
 *   "pool ball" that "bounces" around a 2-d "surface". 
 *            RIGHTMOUSE stops ball
 *            MIDDLEMOUSE increases y velocity
 *            LEFTMOUSE increases x velocity
 *
 *           (ported from ~4Dgifts/example/grafix/iobounce.c)
 */

#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#define XMIN 100
#define YMIN 100
#define XMAX 900
#define YMAX 700

#define BLACK           0
#define YELLOW          3

#define LEFTMOUSE       3
#define MIDDLEMOUSE     2
#define RIGHTMOUSE      1

#define TRUE            1
#define FALSE           0

long xmaxscrn, ymaxscrn; /* maximum size of screen */
/* in x and y */

Display *dpy;            /* The X server connection */
Atom del_atom;           /* WM_DELETE_WINDOW atom   */
Window glwin;            /* handle to the GL window */
XEvent event;

static void openwindow(char *);
static void drawball(void);
static void clean_exit(void);

long xvelocity = 0, yvelocity = 0;

main(int argc, char *argv[])
{
	int myExpose, myConfigure,
		myButtRelease, myKeyPress,
		myButtonNumber;   /* store which events occur */
	long xsize, ysize;



	myExpose = myConfigure = myButtRelease = myKeyPress =
		myButtonNumber = FALSE;

	openwindow(argv[0]);

	while (TRUE) {

		KeySym keysym;
		char buf[4];

		/* this "do while" loop does the `get events' half of the     */
		/* "get events,process events" action of the infinite while.  */
		/* This is to ensure the event queue is always drained before */
		/* the events that have come in are processed.                */
		while (XEventsQueued(dpy,QueuedAfterReading)) { /* end "do { } while"
														 * XEventsQueued(dpy,QueuedAfterReading)
														 * is like qtest()--it only tells you if 
														 * there're any events presently in the 
														 * queue.it does not disturb the event
														 * queue's contents in any way.       */

			XNextEvent(dpy, &event);
			switch (event.type) {

				/* "Expose" events are sort of like "REDRAW" in gl-speak in
				 * terms of when a window or a previously invisible part
				 * becomes visible */
				case Expose:   /* Exposures */
					myExpose = TRUE;
					break;

					/* "ConfigNotify" events are like "REDRAW" in terms of changes to
					 * a window's size or position.*/
				case ConfigureNotify:  /* Resize GL manually */
					xsize = event.xconfigure.width;
					ysize = event.xconfigure.height;
					myConfigure = TRUE;
					break;

					/* Wait for "ButtonRelease" events so the queue doesn't fill up
					 * the way it would if the user sits on ButtonPresss. */
				case ButtonRelease:
					if (event.xbutton.button == Button1) {  
						myButtonNumber = LEFTMOUSE;        
						myButtRelease = TRUE;             
					} else if (event.xbutton.button ==
							Button2) {
						myButtonNumber = MIDDLEMOUSE;
						myButtRelease = TRUE;      
					} else if (event.xbutton.button ==
							Button3) {
						myButtonNumber = RIGHTMOUSE;
						myButtRelease = TRUE; 
					}  /* twirl the green sphere */
					break;

					/* "ClientMessage" is generated if the WM itself is dying
					 * and sends an exit signal to any running prog. */
				case ClientMessage:
					if (event.xclient.data.l[0] == del_atom)
						clean_exit();
					break;

					/* "KeyPress" events are those that would be generated before
					 * whenever queueing up any KEYBD key via qdevice. */
				case KeyPress:
					/* save out which unmodified key (i.e. the key was not
					 * modified w/something like "Shift", "Ctrl", or "Alt")
					 * got pressed for use below. */
					XLookupString((XKeyEvent *)&event, buf, 4, &keysym, 0);
					myKeyPress = TRUE;
					break;

			}  /* end switch (event.type) */
		}

		/* On an "Expose" event, redraw the affected pop'd or
		 * de-iconized window
		 */
		if (myExpose) {
			drawball();       /* draw the GL stuff */
			myExpose = FALSE; /* reset flag--queue now empty */
		}

		/* On a "ConfigureNotify" event, the GL window has either
		 * been moved or resized.  Respond accordingly and then
		 * redraw its contents.
		 */

		if (myConfigure) {
			glViewport(0, 0, xsize, ysize);
			glLoadIdentity();
			gluOrtho2D(XMIN-0.5, XMAX+0.5, YMIN-0.5, YMAX+0.5);
			drawball();           /* draw the GL stuff */
			myConfigure = FALSE;  /* reset flag--queue now
								   * empty */
		}

		/* On a "ButtonRelease" event, myButtonNumber stores which
		 * mouse button was pressed/released and then we update
		 * x/yvelocity accordingly
		 */

		 if (myButtRelease) {
		 if (myButtonNumber == LEFTMOUSE) {  /* increase
		 xvelocity */
		if (xvelocity >= 0)
			xvelocity += 3;
		else
			xvelocity -= 3;
	} else if (myButtonNumber == MIDDLEMOUSE) {
		/* increase yvelocity*/
		if (yvelocity >= 0)
			yvelocity += 3;
		else
			yvelocity -= 3;
	} else if (myButtonNumber == RIGHTMOUSE) {
		/* stop ball */
		xvelocity = yvelocity = 0;
	} else {
		fprintf(stderr,"ERROR:  thinks mouse button # ");
	}
	drawball();
	myButtRelease = FALSE;
	}

	/* On a keypress of Esc key, exit program. */
	if (myKeyPress) {
		if (keysym == XK_Escape)
			clean_exit();
	}

	drawball();

	}
}

static int attributeList[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
GLUquadricObj *qobj; 

static Bool WaitForNotify(Display *d, XEvent *e, char *arg) {
	return (e->type == MapNotify) && (e->xmap.window ==
			(Window)arg);
}

static void openwindow(char *progname) {

	int scrnnum;       /* X screen number  */    
	int xorig, yorig;  /* window (upper-left) origin */
	XVisualInfo *vi;
	GLXContext cx;
	Colormap cmap;
	XSizeHints Winhints;/* used to fix window size */
	XSetWindowAttributes swa;
	XColor colorstruct;

	/* Connect to the X server and get screen info */
	if ((dpy = XOpenDisplay(NULL)) == NULL) {
		fprintf(stderr, "%s: cannot connect to X server %s\n",
				progname, XDisplayName(NULL));
		exit(1);
	}
	scrnnum = DefaultScreen(dpy);
	ymaxscrn = DisplayHeight(dpy, scrnnum);
	xmaxscrn = DisplayWidth(dpy, scrnnum);

	/* get an appropriate visual */
	vi = glXChooseVisual(dpy, DefaultScreen(dpy),
			attributeList);
	if (vi == NULL) {
		printf("Couldn't get visual.\n");
		exit(0);
	}

	/* create a GLX context */
	cx = glXCreateContext(dpy, vi, None, GL_TRUE);

	if (cx == NULL) {
		printf("Couldn't get context.\n");
		exit(0);
	}

	/* create a colormap */
	cmap = XCreateColormap(dpy, RootWindow(dpy, vi->screen),
			vi->visual, AllocNone);

	XSync(dpy, 0);
	/* create a window */
	swa.colormap = cmap;
	swa.border_pixel = 0;

	/* express interest in certain events */
	swa.event_mask = StructureNotifyMask | KeyPressMask |
		ButtonPressMask |
		ButtonReleaseMask | ExposureMask;
	glwin = XCreateWindow(dpy, RootWindow(dpy, vi->screen), 
			10, 10, 300, 300,
			0, vi->depth, InputOutput,
			vi->visual,
			CWBorderPixel|CWColormap|CWEventMask, &swa);

	XMapWindow(dpy, glwin);
	XIfEvent(dpy, &event, WaitForNotify, (char*)glwin);

	/* connect the context to the window */
	glXMakeCurrent(dpy, glwin, cx);

	/* express interest in WM killing this app */
	if ((del_atom = XInternAtom(dpy, "WM_DELETE_WINDOW",
					True)) != None)
		XSetWMProtocols(dpy, glwin, &del_atom, 1);

	colorstruct.pixel = BLACK;    
	colorstruct.red   = 0;
	colorstruct.green = 0;
	colorstruct.blue  = 0;
	colorstruct.flags = DoRed | DoGreen | DoBlue;
	//XStoreColor(dpy, cmap, &colorstruct);
	colorstruct.pixel = YELLOW;
	colorstruct.red   = 65535;
	colorstruct.green = 65535;
	colorstruct.blue  = 0;
	colorstruct.flags = DoRed | DoGreen | DoBlue;
	//XStoreColor(dpy, cmap, &colorstruct);

	glLoadIdentity();
	gluOrtho2D(XMIN - 0.5,  XMAX + 0.5,  YMIN - 0.5,  YMAX + 0.5);

	/* clear the buffer */
	glClearIndex((GLfloat)BLACK);
	qobj = gluNewQuadric(); 
	gluQuadricDrawStyle(qobj,GLU_FILL);
	glFlush();
}

static void drawball(void) {
	static int xpos = 500, ypos = 500;
	GLdouble radius = 14.0;

	glClear(GL_COLOR_BUFFER_BIT);
	xpos += xvelocity;
	ypos += yvelocity;
	if (xpos > XMAX - radius || xpos < XMIN + radius) {
		xpos -= xvelocity;
		xvelocity = -xvelocity;
	}
	if (ypos > YMAX - radius || ypos < YMIN + radius) {
		ypos -= yvelocity;
		yvelocity = -yvelocity;
	}

	glIndexi(YELLOW);
	glPushMatrix(); 
	glTranslatef(xpos,  ypos, 0.); 
	gluDisk( qobj, 0., radius, 10, 1); 
	glPopMatrix(); 
	glXSwapBuffers(dpy, glwin);
}

/*  clean_exit  --  Clean up before exiting */
static void clean_exit(void)
{
	gluDeleteQuadric(qobj); 
	XCloseDisplay(dpy);
	exit(0);
}
