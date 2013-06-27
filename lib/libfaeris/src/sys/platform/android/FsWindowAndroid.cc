#include "sys/FsWindow.h"

NS_FS_BEGIN

Window* Window::create()
{
	static bool window_exit=false;
	if(window_exit)
	{
		FS_TRACE_WARN("Only One Window Can Exist");
		return NULL;
	}
	window_exit=true;
	Window* ret=new Window();
	return ret;
}


void Window::makeCurrent(Render* r)
{
	/*TODO*/
}

void Window::loseCurrent(Render* r)
{
	/* TODO */
}

void Window::swapBuffers()
{
	/* TODO */
}

void Window::setCaption(const char* name)
{
	/* TODO */
}

void Window::setPosition(int x,int y)
{
	/* TODO */
}

void Window::setSize(uint width,uint height)
{
	/* TODO */
}

void Window::show()
{
	/* TODO */
}

void Window::hide()
{
	/* TODO */
}

void Window::setStyle(long flags)
{
	/* TODO */
}

void Window::setFullScreen(bool full) 
{
	/* TODO */
}


int  Window::getWidth()
{
	//return AndroidInfo::getViewWidth();
	return 0;
}

int Window::getHeight()
{
	//return AndroidInfo::getViewHeight();
	return 0;
}




int Window::getPosX()
{
	return 0;
}

int Window::getPosY()
{
	return 0;
}

void Window::setCenter()
{
	/* TODO */
}

Window::~Window()
{
}

NS_FS_END 





















