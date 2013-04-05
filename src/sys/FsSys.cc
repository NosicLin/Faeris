#include "sys/FsSys.h"
#include "FsConfig.h"

#if FS_PLATFORM_OS(FS_OS_LINUX) || FS_PLATFORM_OS(FS_OS_ANDROID)
	#include "platform/FsSysLinux.cc"
#elif FS_PLATFORM_OS(FS_OS_WIN32) 
	#include "platform/FsSysWin32.cc"
#else 
	#error "Unsupport Os"
#endif  /*FS_PLATFORM_OS*/

