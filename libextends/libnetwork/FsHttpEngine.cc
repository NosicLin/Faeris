#include "FsHttpEngine.h"

NS_FS_BEGIN

HttpEngine* HttpEngine::create()
{
	HttpEngine* ret=new HttpEngine;
	ret->start();
	return ret;
}


void HttpEngine::send(HttpRequest* request)
{
	m_reqMutex->lock();
	m_requests->push(request);
	m_reqMutex->unlock();

	m_reqSem->post();
}

void HttpEngine::clear()
{
	m_reqMutex->lock();
	m_requests->clear();
	m_reqMutex->unlock();
}

void HttpEngine::stop()
{
	m_stop=true;
	m_reqSem->post();
}


void HttpEngine::run()
{
	while(!m_stop)
	{
		m_reqSem->wait();

		m_reqMutex->lock();
		if(m_requests->size()==0)
		{
			m_reqMutex->unlock();
			continue;
		}
		else 
		{
			HttpRequest* request=m_requests->get(0); 
			m_requests->remove(0);
			m_reqMutex->unlock();

			/* do Request here */


		}

	}
}

HttpEngine::HttpEngine()
{
	init();
}

bool HttpEngine::init()
{
	m_requests=FsArray::create();
	m_reqSem=new Semaphore(0);
	m_reqMutex=new Mutex();
	m_stop=false;
	return true;
}


void HttpEngine::destroy()
{
	stop(); /* signal thread to  stop */
	join(); /* wait thread to exit */

	if(m_requests)
	{
		m_requests->decRef();
		m_requests=NULL;
	}
	if(m_reqSem)
	{
		delete m_reqSem;
		m_reqSem=NULL;
	}
	if(m_reqMutex)
	{
		delete m_reqMutex;
		m_reqMutex=NULL;
	}
}


HttpEngine::~HttpEngine 
{
	destroy();
}

NS_FS_END 













