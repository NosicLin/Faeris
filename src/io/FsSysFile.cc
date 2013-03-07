#include"FsSysFile.h"

#if FS_PLATFORM_OS(FS_OS_WIN32)|| FS_PLATFORM_OS(FS_OS_LINUX)
	#include "platform/FsSysFileStd.cc"
#else
	#error "Error Platform For SysFile"
#endif 

NS_FS_BEGIN

static const char* s_SysFileName="SysFileObject";
const char* SysFile::getFileName()
{
	return s_SysFileName;
}

NS_FS_END
