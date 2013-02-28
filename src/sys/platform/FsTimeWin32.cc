#include <Windows.h>

#include "fsys/FsTimer.h"

NS_FS_BEGIN 
Timer::Timer()
{
	m_begin=GetTickCount();
}
void Timer::reset()
{
	m_begin=GetTickCount();
}

FsLong Timer::now() const 
{
	return  GetTickCount()-m_begin;
}

NS_FS_END 

