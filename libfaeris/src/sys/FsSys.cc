#include "sys/FsSys.h"
#include "FsConfig.h"

NS_FS_BEGIN

FsDict* Sys::m_env=NULL;
char Sys::m_tempBuf[FS_SYS_TEMP_BUF_SIZE];

NS_FS_END 



#if FS_PLATFORM_OS(FS_OS_LINUX) 
	#include "platform/linux/FsSysLinux.cc"

#elif FS_PLATFORM_OS(FS_OS_ANDROID)
	#include "platform/linux/FsSysLinux.cc"
	#include "platform/android/FsSysAndroid.cc"

#elif FS_PLATFORM_OS(FS_OS_WIN32) 
	#include "platform/win32/FsSysWin32.cc"

#else 
	#error "Unsupport Os"
#endif  /*FS_PLATFORM_OS*/

