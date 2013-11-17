#include "FsTest.h"
#include "FsMacros.h"

#if FS_PLATFORM_OS(FS_OS_LINUX) 
	#include "platform/FsTestLinux.cc"

#elif FS_PLATFORM_OS(FS_OS_ANDROID)
	#include "platform/FsTestAndroid.cc"

#elif FS_PLATFORM_OS(FS_OS_WIN32) 
	#include "platform/FsTestWin32.cc"
#else 
	#error "Unsupport Os"
#endif  /*FS_PLATFORM_OS*/


