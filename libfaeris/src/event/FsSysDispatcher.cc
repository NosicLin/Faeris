#include "event/FsSysDispatcher.h"
#include "event/FsSysEventListener.h"
#include "util/FsSlowArray.h"
NS_FS_BEGIN

const char* SysDispatcher::className()
{
	return FS_SYS_DISPATCHER_CLASS_NAME;
}

SysDispatcher* SysDispatcher::create()
{
	SysDispatcher* ret=new SysDispatcher;
	return ret;
}

void SysDispatcher::dispatchSysEvent(int type)
{
	SysEvent* event=new SysEvent(type);
	m_eventPending->push_back(event);
}

void SysDispatcher::addEventListener(SysEventListener* l)
{
	m_listenerArray->push(l);
}

void SysDispatcher::removeEventListener(SysEventListener* l)
{
	m_listenerArray->remove(l);
}

void SysDispatcher::clearPending()
{
	clearEvent(m_eventPending);
}

void SysDispatcher::update(int priority,float dt)
{
	swapEventQueue();
	int event_nu=m_eventHandling->size();
	m_listenerArray->lock();
	for(int i=0;i<event_nu;i++)
	{
		SysEvent* event=m_eventHandling->at(i);
		int listen_nu=m_listenerArray->size();


		for( int j=0;j<listen_nu;j++)
		{
			SysEventListener*  listen=(SysEventListener*) m_listenerArray->get(j);
			switch(event->m_type)
			{
				case FOREGROUND:
					listen->foreground();
					break;

				case BACKGROUND:
					listen->background();
					break;

				case QUIT:
					listen->quit();
					break;

				case EXIT:
					listen->exit();
					break;
			}
			listen->decRef();
		}
	}
	m_listenerArray->unlock();
	m_listenerArray->flush();
	clearEvent(m_eventHandling);
}

SysDispatcher::SysDispatcher()
{
	init();
}

SysDispatcher::~SysDispatcher()
{
	destroy();
}

void SysDispatcher::init()
{
	m_eventPending=new EventQueue();
	m_eventHandling=new EventQueue();
	m_listenerArray=FsSlowArray::create();
}

void SysDispatcher::destroy()
{
	clearEvent(m_eventPending);
	clearEvent(m_eventHandling);
	delete m_eventPending;
	delete m_eventHandling;

	m_listenerArray->decRef();
}

void SysDispatcher::swapEventQueue()
{
	EventQueue* temp=m_eventPending;
	m_eventPending=m_eventHandling;
	m_eventHandling=temp;
}
void SysDispatcher::clearEvent(EventQueue* queue)
{
	EventQueue::iterator iter=queue->begin();
	for(;iter!=queue->end();++iter)
	{
		delete *iter;
	}
	queue->clear();
}

NS_FS_END



