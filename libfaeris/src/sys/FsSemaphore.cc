#include "sys/FsSemaphore.h"


Semaphore::Semaphore()
{
	sem_init(&m_sem,0,1);
}


Semaphore::Semaphore(unsigned int num)
{
	sem_init(&m_sem,0,num);
}

Semaphore::~Semaphore()
{
	sem_destory(&m_sem);
}

int Semaphore::wait()
{
	int ret=sem_wait(&m_sem);
	if(ret<0)
	{
		FS_TRACE_WRAN("Wait Failed");
		return -1;
	}
	return 0;
}




