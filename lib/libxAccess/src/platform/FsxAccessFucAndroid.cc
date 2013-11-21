#include "FsxAccessFuc.h"

#include "FsMacros.h"
#include "sys/platform/android/FsJniUtil.h"

NS_FS_USE;

static const char* JNI_CALLFUNCTION_CLASS_NAME="com/rwhz/minder/Fs_rCallFunction";


void f_BillingPointUp(const char* bpid, const char* price )
{
//	FS_TRACE_WARN("BillingPointUp, My platform Is Android");

	JNIEnv* env=JniUtil::getEnv();
	jstring jbpid=env->NewStringUTF(bpid);
	jstring jprice=env->NewStringUTF(price);

	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_STATIC_METHOD(JNI_CALLFUNCTION_CLASS_NAME,"BillingPointUp","(Ljava/lang/String;Ljava/lang/String;)V",jbpid,jprice);
	env->DeleteLocalRef(jbpid);
	env->DeleteLocalRef(jprice);

}


void f_LogTalkingData(const char* eventID, const char* eventLabel)
{
	JNIEnv* env=JniUtil::getEnv();
	jstring jeventID=env->NewStringUTF(eventID);
	jstring jeventLabel=env->NewStringUTF("");

	if (eventLabel != NULL)
	{
		jeventLabel = env->NewStringUTF(eventLabel);
	}

	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_STATIC_METHOD(JNI_CALLFUNCTION_CLASS_NAME,"LogTalkingData","(Ljava/lang/String;Ljava/lang/String;)V",jeventID,jeventLabel);
	env->DeleteLocalRef(jeventID);
	env->DeleteLocalRef(jeventLabel);

}