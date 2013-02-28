#include <Windows.h>


NS_FS_BEGIN

void Sys::usleep(FsLong time)
{
	Sleep(time);
}

NS_FS_END 

