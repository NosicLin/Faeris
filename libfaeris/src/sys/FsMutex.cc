#include "sys/FsMutex.h"

NS_FS_BEGIN
Mutex::Mutex()
{
	pthread_mutex_init(&m_mutex,NULL);
}

Mutex::~Mutex()
{
	pthread_mutex_destory(&m_mutex);
}


int Mutex::lock()
{
	int ret=pthread_mutex_lock(m_mutex);
	if(ret<0)
	{
		FS_TRACE_WARN("Lock Mutex Failed");
		return -1;
	}
	return 0;
}

int Mutex::lock(bool retry)
{
	int ret=-1;
	do{
		ret=pthread_mutex_lock(m_mutex);

		if((ret==-1)&&retry)
		{
			continue;
		}
		break;
	}while(true);

	return ret;
}

int Mutex::trylock()
{
	int ret=pthread_mutex_trylock(m_mutex);

	if(ret<0)
	{
		return -1;
	}
	return 0;
}

int Mutex::unlock()
{
	int ret=pthread_mutex_unlock(m_mutex);
	if(ret<0)
	{
		FS_TRACE_WARN("Unlock Mutex Failed");
		return -1;
	}
	return 0;
}






NS_FS_END 
