#include <stdio.h>
#include "FsLog.h"
#include "FsConfig.h"
#include "io/FsFile.h"
#include "io/FsVFS.h"
#include <stdarg.h>


NS_FS_BEGIN
static FsLog* s_global_log=NULL;
FileLog* FileLog::ms_stdoutFileLog=NULL;

static void init_global_log()
{
	if(s_global_log==NULL)
	{
#if FS_CONFIG(FS_LOG_FILE)
		s_global_log=FileLog::Create(FS_CONFIG(LOG_FILE_NAME));
#elif FS_CONFIG(FS_LOG_STDIO)
		s_global_log=FileLog::getStdoutFileLog();
#else
		s_global_log=FileLog::getStdoutFileLog();
#endif
	}
}

static void FsLog_FormatLogBuffer(char* buf,ulong size,
								   const char* fmt,va_list ap)
{
	uint msg_len=vsnprintf(buf,size-1,fmt,ap);
	buf[msg_len]='\0';
}

static void FsLog_FormatLogTagBuffer(char* buf,ulong size,
								const char* tag,const char* fmt,
								va_list ap)
{
	uint fmtbyte=snprintf(buf,size-1,"%s:",tag);
	uint msg_len=vsnprintf(buf+fmtbyte,size-1-fmtbyte,fmt,ap);
	buf[fmtbyte+msg_len]='\0';

}

void FsLog::tagLog(const char* tag,const char* fmt,...)
{
	char buf[FS_MAX_LOG_BUF];
	va_list args;
	va_start(args,fmt);
	FsLog_FormatLogTagBuffer(buf,FS_MAX_LOG_BUF,tag,fmt,args);
	va_end(args);

	logMsg(buf);
}
void FsLog::log(const char* fmt,...)
{
	char buf[FS_MAX_LOG_BUF];

	va_list args;
	va_start(args,fmt);
	FsLog_FormatLogBuffer(buf,FS_MAX_LOG_BUF,fmt,args);
	va_end(args);

	logMsg(buf);
}


FileLog* FileLog::create(const char* filename)
{

	FsFile* f=VFS::open(filename,VFS::FS_IO_CREATE|VFS::FS_IO_APPEND);
	if(f==NULL)
	{
		return NULL;
	}
	FileLog* fl=new FileLog(f);
	return fl;
}


FileLog* FileLog::getStdoutFileLog()
{
	if(ms_stdoutFileLog==NULL)
	{
		ms_stdoutFileLog=new FileLog(VFS::getStdout());
	}
	return ms_stdoutFileLog;
}


FileLog::FileLog(FsFile* file)
{
	m_file=file;
}

void FileLog::logMsg(const char* msg)
{
	m_file->writeStr("%s\n",msg);
}

FileLog::~FileLog()
{
	delete m_file;
}


void FsUtil_TagLog(const char* tag,const char* fmt,...)
{
	init_global_log();

	char buf[FS_MAX_LOG_BUF];
	va_list args;
	va_start(args,fmt);
	FsLog_FormatLogTagBuffer(buf,FS_MAX_LOG_BUF,tag,fmt,args);
	va_end(args);

	s_global_log->log("%s",buf);
}

void FsUtil_Log(const char* fmt,...)
{
	init_global_log();
	char buf[FS_MAX_LOG_BUF];

	va_list args;
	va_start(args,fmt);
	FsLog_FormatLogBuffer(buf,FS_MAX_LOG_BUF,fmt,args);
	va_end(args);

	s_global_log->log("%s",buf);
}



NS_FS_END
