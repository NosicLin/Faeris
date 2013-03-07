#include"FsSysFile.h"

#if FS_PLATFORM_OS(FS_OS_WIN32)|| FS_PLATFORM_OS(FS_OS_LINUX)
	#include "platform/FsSysStdFile.cc"
#else
	#error "Error Platform For SysFile"
#endif 

NS_FS_BEGIN

const char* SysFile::getFileName()
{
	return FS_SYSFILE_CLASS_NAME;
}

NS_FS_END
