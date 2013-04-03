#include "sys/FsSys.h"
#include "FsConfig.h"

#if FS_PLATFORM_OS(FS_OS_LINUX)
	#include "platform/FsSysLinux.cc"
#elif FS_PLATFORM_OS(FS_OS_WIN32)
	#include "platform/FsSysWin32.cc"
#else 
	#error "Unsupport Os"
#endif  /*FS_PLATFORM_OS*/

