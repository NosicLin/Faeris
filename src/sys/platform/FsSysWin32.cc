#include <Windows.h>


NS_FS_BEGIN

void Sys::usleep(long time)
{
	Sleep(time);
}

NS_FS_END 

