#ifndef _FAERY_SYS_FILE_H_
#define _FAERY_SYS_FILE_H_

#include "FsMacros.h"
#include "FsFile.h"


#if FS_PLATFORM_OS(FS_OS_WIN32) || FS_PLATFORM_OS(FS_OS_LINUX)
	#include<stdio.h>
	typedef FILE* SysFilePlateform ;
#else 
	#error "Error Platform For SysFile"
#endif 


NS_FS_BEGIN
class SysFile:public FsFile 
{
	public:
		static SysFile* open(const FsChar* name,FsUint mode=FsFile::FS_IO_RDONLY);
		static SysFile* getStdout();
		static SysFile* getStderr();
		static SysFile* getStdin();
	private:
		static SysFile* ms_stdout;
		static SysFile* ms_stdin;
		static SysFile* ms_stderr;
	public:
		virtual FsLong read(FsVoid* buf,FsLong length);
		virtual FsLong write(const FsVoid* buf,FsLong length);
		virtual FsLong seek(FsLong offset,FsInt where);
		virtual FsInt close();
		virtual FsLong tell();
		virtual ~SysFile();
		virtual const FsChar* getFileName();
	protected:
		SysFile(SysFilePlateform f){m_platfromFile=f;}
	private:
		SysFilePlateform m_platfromFile;
};
NS_FS_END

#endif  /*_FAERY_SYS_FILE_H_*/


