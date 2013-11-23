#include "FsUpdateApk.h"
#include "FsMacros.h"

NS_FS_BEGIN



UpdateApk* UpdateApk::create()
{
	UpdateApk* ret = new UpdateApk();
	return ret;
}


void UpdateApk::onResult(int ret)
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onResult",2,0,"fi",this, ret);
}

UpdateApk::UpdateApk()
{
}
UpdateApk::~UpdateApk()
{
}


NS_FS_END


#if FS_PLATFORM_OS(FS_OS_LINUX) 
#include "platform/FsUpdateApkLinux.cc"

#elif FS_PLATFORM_OS(FS_OS_ANDROID)
#include "platform/FsUpdateApkAndroid.cc"

#elif FS_PLATFORM_OS(FS_OS_WIN32)
#include "platform/FsUpdateApkWin32.cc"
#else 
#error "FsUpateApk platform error"
#endif  /*FsUpateApk*/


