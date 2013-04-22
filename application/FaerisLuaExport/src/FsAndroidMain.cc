
#include <jni.h>

#include "FsMacros.h"
#include "sys/platform/FsAndroidInfo.h"
#include "FsLuaEngine.h"
#include "common/FsGlobal.h"

NS_FS_USE
extern "C"
{
	jint JNI_OnLoad(JavaVM* vm, void* reserved)
	{
		LuaEngine* engine=LuaEngine::create();
		Global::setScriptEngine(engine);
		engine->decRef();

		AndroidInfo::setJavaVM(vm);

		return JNI_VERSION_1_4;
	}
}
