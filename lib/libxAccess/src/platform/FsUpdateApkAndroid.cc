
#include "FsUpdateApk.h"

#include "sys/platform/android/FsJniUtil.h"

#define  UPDATE_APK_RET_SUCCESS  1 

NS_FS_BEGIN
static const char* JNI_CALLFUNCTION_CLASS_NAME="com/ihuizhi/minder/Fs_rCallFunction";




void UpdateApk::checkUpdate(void)
{
	JNIEnv* env=JniUtil::getEnv();
	JniUtil::attachCurrentThread();

	jlong value=(jlong)this;
	FS_JNI_CALL_VOID_STATIC_METHOD(JNI_CALLFUNCTION_CLASS_NAME,"CheckUpdate","(J)V" , value);
}



NS_FS_END