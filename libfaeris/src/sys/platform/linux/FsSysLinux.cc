#include "sys/FsSys.h"

#include <unistd.h>
#include <errno.h>
#include <time.h>

NS_FS_BEGIN
/*
FsLong Sys::getTime()
{
	return 0;

}
*/
void Sys::usleep(long time)
{
	struct timespec req= { time/1000, (time%1000)*1000000 };
	struct timespec rem;
	int ret=0;
	while(1)
	{
		ret=nanosleep(&req,&rem);
		if(ret==-1)
		{
			if(errno==EINTR)
			{
				req=rem;
				nanosleep(&req,&rem);
				continue;
			}
		}
		break;
	}
}

const char* Sys::currentDir()
{
	getcwd(m_tempBuf,FS_SYS_TEMP_BUF_SIZE);
	return m_tempBuf;
}

NS_FS_END

