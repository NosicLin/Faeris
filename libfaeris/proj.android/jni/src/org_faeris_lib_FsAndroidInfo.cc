#include "org_faeris_lib_FsAndroidInfo.h"
#include "sys/platform/FsAndroidInfo.h"

NS_FS_USE

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_faeris_lib_FsAndroidInfo
 * Method:    setApkPath
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_faeris_lib_FsAndroidInfo_setApkName
  (JNIEnv* env, jclass, jstring apk_name)
  {
	  const char*  apk_name_str=env->GetStringUTFChars(apk_name,NULL);
	  AndroidInfo::setApkName(apk_name_str);
	  env->ReleaseStringUTFChars(apk_name,apk_name_str);
  }

/*
 * Class:     org_faeris_lib_FsAndroidInfo
 * Method:    setSourceDir
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_faeris_lib_FsAndroidInfo_setApkPath
  (JNIEnv* env, jclass, jstring apk_path)
  {
	  const char*  apk_path_str=env->GetStringUTFChars(apk_path,NULL);
	  AndroidInfo::setApkPath(apk_path_str);
	  env->ReleaseStringUTFChars(apk_path,apk_path_str);
  }

#ifdef __cplusplus
}
#endif

