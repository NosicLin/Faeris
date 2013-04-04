#include <Windows.h>
#include  <direct.h>  
#include  <stdio.h>  

NS_FS_BEGIN

void Sys::usleep(long time)
{
	Sleep(time);
}
std::string Sys::currentDir()
{
	char   buffer[2048];   
    _getcwd(buffer, 2048);   
	return buffer;
}


NS_FS_END 

