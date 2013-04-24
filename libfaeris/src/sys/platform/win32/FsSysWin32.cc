#include <Windows.h>
#include  <direct.h>  
#include  <stdio.h>  
#include "util/FsPathUtil.h"

NS_FS_BEGIN

void Sys::usleep(long time)
{
	Sleep(time);
}

const char* Sys::currentDir()
{
    _getcwd(m_tempBuf, FS_SYS_TEMP_BUF_SIZE); 
	return m_tempBuf;
}



NS_FS_END 

