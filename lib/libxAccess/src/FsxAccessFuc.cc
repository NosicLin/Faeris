
#include "FsxAccessFuc.h"
#include "FsMacros.h"

#if FS_PLATFORM_OS(FS_OS_LINUX) 
#include "platform/FsxAccessFucLinux.cc"

#elif FS_PLATFORM_OS(FS_OS_ANDROID)
#include "platform/FsxAccessFucAndroid.cc"

#elif FS_PLATFORM_OS(FS_OS_WIN32) 
#include "platform/FsxAccessFucWin32.cc"
#else 
#error "FsPayFunction error"
#endif  /*FsPayFunction*/

