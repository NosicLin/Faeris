#include "FsFile.h"
#include "stdarg.h"
#include "stdio.h"
NS_FS_BEGIN
static const char* s_FsFileName="FsFileObject";
const char* FsFile::className()
{
	return s_FsFileName;
}

long FsFile::writeStr(const char* fmt,...)
{
	int cnt=1024;
	long fmt_byte=0;

	while(1)
	{
		char* buffer=new char[cnt];

		va_list argptr;
		va_start(argptr,fmt);
		fmt_byte=vsnprintf(buffer,cnt,fmt,argptr);
		va_end(argptr);
		if(fmt_byte<cnt)
		{
			buffer[fmt_byte]='\0';
			write(buffer,fmt_byte);
			delete[] buffer;
			break;
		}
		cnt*=2;
		delete[] buffer;
	}
	return  fmt_byte;
}

long FsFile::getLength()
{
	long cur_pos=tell();
	seek(0,FS_SEEK_END);

	long length=tell();
	seek(cur_pos,FS_SEEK_SET);
	return length;
}

NS_FS_END

