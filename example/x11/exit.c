// example.cpp
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <stdio.h>
int main()
{
   Display* display = XOpenDisplay(NULL);
   Window window = XCreateSimpleWindow(display,
                                       DefaultRootWindow(display),
                                       0, 0,
                                       500, 400,
                                       0,
                                       0, 0);

   // register interest in the delete window message
   Atom wmDeleteMessage = XInternAtom(display, "WM_DELETE_WINDOW", False);
   XSetWMProtocols(display, window, &wmDeleteMessage, 1);

   printf("Starting up...\n");
   XMapWindow(display, window);

   while (1) {
      XEvent event;
      XNextEvent(display, &event);

      if (event.type == ClientMessage &&
          event.xclient.data.l[0] == wmDeleteMessage) {
         printf("Shutting down now!!!\n");
         break;
      }
   }

   XCloseDisplay(display);
   return 0;
}
