#include "event/FsTouchDispatcher.h"
#include "event/FsTouchEventListener.h"
#include "common/FsGlobal.h"

NS_FS_BEGIN
const char* TouchDispatcher::className()  
{
	return FS_TOUCH_DISPATCHER_CLASS_NAME;
}

TouchDispatcher* TouchDispatcher::create()
{
	TouchDispatcher* ret=new TouchDispatcher;
	return ret;
}
void TouchDispatcher::update(int /*priority*/,float /*dt*/)
{
	swapEventQueue();
	int event_nu=m_eventHandling->size();

	m_listenerArray->lock();
	for(int i=0;i<event_nu;i++)
	{
		TouchEvent* event=m_eventHandling->at(i);
		int listen_nu=m_listenerArray->size();

		for(int j=0;j<listen_nu;j++)
		{
			TouchEventListener* listen=(TouchEventListener*)m_listenerArray->get(j);
			switch(event->m_type)
			{
				case TOUCH_BEGIN:
					listen->touchBegin(event->m_x,event->m_y);
					break;
				case TOUCH_MOVE:
					listen->touchMove(event->m_x,event->m_y);
					break;
				case TOUCH_END:
					listen->touchEnd(event->m_x,event->m_y);
					break;
				case TOUCH_CANCEL:
					listen->touchCancel(event->m_x,event->m_y);
					break;
				case TOUCHES_BEGIN:
					listen->touchesBegin(event->m_points,event->m_num);
					break;
				case TOUCHES_MOVE:
					listen->touchesMove(event->m_points,event->m_num);
					break;
				case TOUCHES_END:
					listen->touchesEnd(event->m_points,event->m_num);
					break;
				case TOUCHES_CANCEL:
					listen->touchesCancel(event->m_points,event->m_num);
					break;
			}
			listen->decRef();
		}
	}
	m_listenerArray->unlock();
	m_listenerArray->flush();
	clearEvent(m_eventHandling);
}

void TouchDispatcher::dispatchTouchEvent(int type,float x,float y)
{
	m_eventPending->push_back(new TouchEvent(type,x,y));
}

void TouchDispatcher::dispatchTouchesEvent(int type,Vector2* points,int num)
{
	m_eventPending->push_back(new TouchEvent(type,points,num));
}

void TouchDispatcher::addEventListener(TouchEventListener* l)
{
	m_listenerArray->push(l);
}
void TouchDispatcher::removeEventListener(TouchEventListener* l)
{
	m_listenerArray->remove(l);
}



TouchDispatcher::TouchDispatcher()
{
	init();
}
TouchDispatcher::~TouchDispatcher()
{
	destroy();
}



void TouchDispatcher::init()
{
	m_eventHandling=new EventQueue;
	m_eventPending=new EventQueue;

	m_listenerArray=FsSlowArray::create();
}

void TouchDispatcher::destroy()
{
	clearEvent(m_eventHandling);
	clearEvent(m_eventPending);

	delete m_eventHandling;
	delete m_eventPending;

	m_listenerArray->decRef();
}

void TouchDispatcher::swapEventQueue()
{
	std::vector<TouchEvent*>* event_queue=m_eventHandling;
	m_eventHandling=m_eventPending;
	m_eventPending=event_queue;
}

void TouchDispatcher::clearEvent(EventQueue* queue)
{
	EventQueue::iterator iter=queue->begin();
	for(;iter!=queue->end();++iter)
	{
		delete *iter;
	}
	queue->clear();
}


TouchDispatcher::TouchEvent::TouchEvent(int type,float x,float y)
{
	m_type=type;
	m_x=(float)x;
	m_y=(float)y;
}

TouchDispatcher::TouchEvent::TouchEvent(int type,Vector2* points,int num)
{
	m_type=type;
	m_points=new Vector2[num];
	for(int i=0;i<num;i++)
	{
		m_points[i]=points[i];
	}
}


NS_FS_END








