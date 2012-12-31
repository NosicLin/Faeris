#include "FsTimer.h"

#if FS_PLATFORM_OS(FS_OS_LINUX)
	#include "platform/FsTimeLinux.cc"
#elif FS_PLATFORM_OS(FS_OS_WIN32)
	#include "platform/FsTimeWin32.cc"
#else 
	#error "Unsupport Platform OS"
#endif 
