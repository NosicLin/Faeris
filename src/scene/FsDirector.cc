#include "scene/FsDirector.h"
#include "event/FsTouchDispatcher.h"
#include "event/FsTouchEventListener.h"
#include "common/FsGlobal.h"
#include "util/FsArray.h"
#include "math/FsVector2.h"
#include "scene/FsScene.h"

NS_FS_BEGIN

class DirectorTouchEventListener:public TouchEventListener
{
	public:
		static DirectorTouchEventListener* create(Director* director);

	public:
		virtual void touchBegin(float x,float y);
		virtual void touchMove(float x,float y);
		virtual void touchEnd(float x,float y);
		virtual void touchCancel(float x,float y);

		virtual void touchesBegin(Vector2* points,int num);
		virtual void touchesMove(Vector2* points,int num);
		virtual void touchesEnd(Vector2* points,int num);
		virtual void touchesCancel(Vector2* points,int num);

	protected:
		DirectorTouchEventListener(Director* director);
		~DirectorTouchEventListener();
	private:
		Director* m_director;
};

DirectorTouchEventListener* DirectorTouchEventListener::create(Director* director)
{
	DirectorTouchEventListener* ret=new DirectorTouchEventListener(director);
	return ret;
}


void DirectorTouchEventListener::touchBegin(float x,float y)
{
	m_director->touchEvent(TouchDispatcher::TOUCH_BEGIN,x,y);
}

void DirectorTouchEventListener::touchMove(float x,float y)
{
	m_director->touchEvent(TouchDispatcher::TOUCH_MOVE,x,y);
}

void DirectorTouchEventListener::touchEnd(float x,float y)
{
	m_director->touchEvent(TouchDispatcher::TOUCH_END,x,y);
}

void DirectorTouchEventListener::touchCancel(float x,float y)
{
	m_director->touchEvent(TouchDispatcher::TOUCH_CANCEL,x,y);
}



void DirectorTouchEventListener::touchesBegin(Vector2* points,int num)
{
	m_director->touchesEvent(TouchDispatcher::TOUCHES_BEGIN,points,num);
}


void DirectorTouchEventListener::touchesMove(Vector2* points,int num)
{
	m_director->touchesEvent(TouchDispatcher::TOUCHES_MOVE,points,num);
}


void DirectorTouchEventListener::touchesEnd(Vector2* points,int num)
{
	m_director->touchesEvent(TouchDispatcher::TOUCHES_END,points,num);
}

void DirectorTouchEventListener::touchesCancel(Vector2* points,int num)
{
	m_director->touchesEvent(TouchDispatcher::TOUCHES_CANCEL,points,num);
}

DirectorTouchEventListener::DirectorTouchEventListener(Director* director)
{
	m_director=director;
}
DirectorTouchEventListener::~DirectorTouchEventListener()
{
}


Director* Director::create()
{
	Director* ret=new Director;
	return ret;
}

const char* Director::className()
{
	return FS_DIRECTOR_CLASS_NAME;
}

void Director::update(int priority,float dt)
{
	if(m_stop)
	{
		return ;
	}
	if(!m_current) return;

	switch(priority)
	{
		case Scheduler::MIDDLE:
			update(dt);
			break;
		case Scheduler::LOW:
			draw();
			break;
	}
}
void Director::push()
{
	if(m_current)
	{
		m_secenQueue->push(m_current);
	}
	FS_TRACE_WARN_ON(m_current==NULL,"No Current Exist");
}
void Director::pop()
{
	if(m_secenQueue->size()==0)
	{
		FS_TRACE_WARN("No Scene in Queue");
		return ;
	}
	Scene* scene=(Scene*)m_secenQueue->get(m_secenQueue->size()-1);
	m_secenQueue->pop();

	repace(scene);
}

void Director::run(Scene* scene)
{
	repace(scene);
}

void Director::pause()
{
	m_stop=true;
}
void Director::start()
{
	m_stop=false;
}
bool Director::isRunning()
{
	return !m_stop;
}
void Director::setAutoSwapBuffers(bool swap)
{
	m_autoSwapBuffers=swap;
}



Director::Director()
{
	init();
}

Director::~Director()
{
	destroy();
}
void Director::init()
{
	m_current=NULL;
	m_secenQueue=FsArray::create();
	m_stop=false;
	m_autoSwapBuffers=false;

	m_touchEventListener=DirectorTouchEventListener::create(this);
	Global::touchDispatcher()->addEventListener(m_touchEventListener);

}
void Director::destroy()
{
	if(m_current)
	{
		m_current->exit();
		m_current->decRef();
		m_current=NULL;
	}
	m_secenQueue->decRef();

	Global::touchDispatcher()->removeEventListener(m_touchEventListener);
	m_touchEventListener->decRef();
}

void Director::repace(Scene* scene)
{
	if(m_current)
	{
		m_current->exit();
		m_current->decRef();
	}
	if(scene)
	{
		scene->enter();
		scene->addRef();
	}
	m_current=scene;
}

void Director::draw()
{


	Render* render=Global::render();
	if(!render) return;

	render->clear();

	if(m_current)
	{
		m_current->draw(render);
	}
	if(m_autoSwapBuffers)
	{
		render->swapBuffers();
	}
}

void Director::update(float dt)
{
	if(m_current)
	{
		m_current->update(dt);
	}
}

void Director::touchEvent(int type,float x,float y)
{
	if(m_stop) return;
	if(!m_current) return;
	switch(type)
	{
		case TouchDispatcher::TOUCH_BEGIN:
			m_current->touchBegin(x,y);
			break;
		case TouchDispatcher::TOUCH_MOVE:
			m_current->touchMove(x,y);
			break;
		case TouchDispatcher::TOUCH_END:
			m_current->touchEnd(x,y);
			break;
	}
}
void Director::touchesEvent(int type,Vector2* points,int num)
{
	if(m_stop) return;
	if(!m_current) return ;

	switch(type)
	{
		case TouchDispatcher::TOUCHES_BEGIN:
			m_current->touchesBegin(points,num);
			break;
		case TouchDispatcher::TOUCHES_MOVE:
			m_current->touchesMove(points,num);
			break;
		case TouchDispatcher::TOUCHES_END:
			m_current->touchesEnd(points,num);
			break;
	}
}







NS_FS_END





















