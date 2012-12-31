#include "fsys/FsWindow.h"
#include "fsys/FsFrame.h"
#include "graphics/FsRender.h"
#include "fsys/FsEventListener.h"
#include "fsys/FsEventDispatcher.h"
#include<stdio.h>
#include <string>


using namespace Faeris;


class WinListener:public EventListener
{
	public:
		virtual void onFocus(Window* win, FocusEvent* e)
		{
			std::string name=win->getCaption();
			printf("%s:",name.c_str());
			if(e->focus)
			{
				printf("FocusIn\n");
			}
			else 
			{
				printf("FocusOut\n");
			}
		}

		virtual void onKey(Window* win,KeyEvent* e)
		{
			std::string name=win->getCaption();
			printf("%s:",name.c_str());
			printf("key event\n");
		}
		virtual void onResize(Window* win,ResizeEvent* e)
		{
			std::string name=win->getCaption();
			printf("%s:",name.c_str());
			printf("window resize(%d,%d)\n",e->width,e->height);
		}
		virtual void onMotion(Window* win,MotionEvent* e)
		{
			std::string name=win->getCaption();
			printf("%s:",name.c_str());
			printf("mouse motion (%d,%d) \n",e->x,e->y);
		}
		virtual void onMouse(Window* win,MouseEvent* e)
		{
			std::string name=win->getCaption();
			printf("%s:",name.c_str());
			if(e->button==FS_LBUTTON)
			{
				printf("Left Button");
			}
			else if(e->button==FS_MBUTTON)
			{
				printf("Middle Button");
			}
			else if(e->button==FS_RBUTTON)
			{
				printf("Right Button");
			}
			else 
			{
				printf("unkown Button");
			}
			printf("(%d,%d)",e->x,e->y);
			printf(":");
			if(e->state==FS_DOWN)
			{
				printf("Down");
			}
			else if(e->state==FS_UP)
			{
				printf("Up");
			}
			printf("\n");
		}
};
class MyFrameListener:public FrameListener 
{
	public:
		MyFrameListener()
		{
			m_time=0;
		}

	public:
		virtual void frameUpdate(FsLong diff)
		{
			m_time++;
			printf("my frame update (%d), avgFps=%d\n",m_time,Frame::shareFrame()->getAvgFPS());
			Render::shareRender()->clear(true);
			Render::shareRender()->swapBuffers();
		}
	private:
		FsInt m_time;
};


int main()
{
	


	Window* win=Window::shareWindow();

	WinListener* listener=new WinListener;
	EventDispatcher::shareEventDispatcher()->addEventListener(listener);


	if(win==NULL)
	{
		printf("create win error\n");
		return 0;
	}

	Render* render=Render::shareRender();


	win->setSize(1024,800);
	win->setCaption("Faeris.V1.0.1");
	win->show();
	win->setPosition(600,200);


	
	render->setRenderTarget(win);
	render->setClearColor(Color(255,0,0));
	render->clear(true);
	render->swapBuffers();


	MyFrameListener* framelistener=new MyFrameListener();
	Frame::shareFrame()->addListener(framelistener);
	Frame::shareFrame()->setFPS(0);
	Frame::shareFrame()->start();
	//render->setRenderTarget(NULL);


	Window::purgeShareWindow();

	delete listener;
	delete framelistener;
	printf("exit\n");



	return 0;

}


