#include"FsSysFile.h"

#if FS_PLATFORM_OS(FS_OS_WIN)|| FS_PLATFORM_OS(FS_OS_LINUX)
	#include "platform/FsSysFileStd.cc"
#else
	#error "Error Platform For SysFile"
#endif 

FAERIS_NAMESPACE_BEGIN

static const FsChar* s_SysFileName="SysFileObject";
const FsChar* SysFile::getFileName()
{
	return s_SysFileName;
}

FAERIS_NAMESPACE_END
