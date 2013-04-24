#include "FsMacros.h"
#include "sys/FsSys.h"

#include "FsJniUtil.h"

NS_FS_BEGIN

JavaVM* Sys::m_jvm=NULL;

void Sys::setJavaVM(JavaVM* jvm)
{
	m_jvm=jvm;
}


JavaVM* Sys::getJavaVM()
{
	return m_jvm;
}


const char* Sys::packageName()
{
	JNIEnv* env=JniUtil::getEnv();
	jobject ob_ret;
	FS_JNI_CALL_STATIC_METHOD("org/faeris/lib/FsGlobal",
							  "getPackageName",
							  "()Ljava/lang/String;",
							  Object,
							  ob_ret);
	jstring j_str=(jstring)ob_ret;
	const char* apk_name=env->GetStringUTFChars(j_str,NULL);
	strncpy(m_tempBuf,apk_name,FS_SYS_TEMP_BUF_SIZE);
	env->ReleaseStringUTFChars(j_str,apk_name);
	return m_tempBuf;
}

const char* Sys::apkPath()
{
	JNIEnv* env=JniUtil::getEnv();
	jobject ob_ret;
	FS_JNI_CALL_STATIC_METHOD("org/faeris/lib/FsGlobal",
							  "getApkPath",
							  "()Ljava/lang/String;",
							  Object,
							  ob_ret);
	jstring j_str=(jstring)ob_ret;
	const char* apk_path=env->GetStringUTFChars(j_str,NULL);
	strncpy(m_tempBuf,apk_path,FS_SYS_TEMP_BUF_SIZE);
	env->ReleaseStringUTFChars(j_str,apk_path);

	return m_tempBuf;
}


NS_FS_END 
