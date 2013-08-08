#include <Windows.h>

#include "sys/FsTimer.h"

NS_FS_BEGIN 
Timer::Timer()
{
	m_begin=timeGetTime();
}
void Timer::reset()
{
	m_begin=timeGetTime();
}

long Timer::now() const 
{
	DWORD current=timeGetTime();
	return  current-m_begin;
}

NS_FS_END 

