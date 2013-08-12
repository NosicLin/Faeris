#include <Windows.h>

#include "sys/FsTimer.h"

NS_FS_BEGIN 
Timer::Timer()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&m_begin.count);
	QueryPerformanceFrequency((LARGE_INTEGER*)&m_begin.frequency);
}
void Timer::reset()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&m_begin.count);
}

long Timer::now() const 
{
	__int64 current;
	QueryPerformanceCounter((LARGE_INTEGER*)&current);
	return  (long)(double(current-m_begin.count)/double(m_begin.frequency)*1000);
}

NS_FS_END 

