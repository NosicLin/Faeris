#include "com_faeris_lib_Fs_Jni.h"
#include "common/FsGlobal.h"
#include "FsFaerisModule.h"

#include "io/FsVFS.h"
#include "io/FsPackage.h"

#include "sys/FsSys.h"


NS_FS_USE

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    moduleInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_moduleInit
  (JNIEnv *, jclass)
  {

	  FsFaeris_ModuleInit();

	  /* configure vfs */


	  /* set root dir */
	  std::string data_dir(Sys::currentDir());
	  VFS::setRoot(data_dir.c_str());
	  FS_TRACE_INFO("root dir(%s)",data_dir.c_str());



	  /* map apk to vfs */
	  std::string apk_path(Sys::apkPath());
	  Package* package=Package::create(apk_path.c_str(),Package::PACKAGE_ZIP);

	  FS_TRACE_INFO("apk path=%s",apk_path.c_str());


	  if(package==NULL)
	  {
		  FS_TRACE_WARN("load package %s  failed",apk_path.c_str());
	  }
	  else 
	  {
		  VFS::mapPackage("",package);
	  }
	  FS_SAFE_DEC_REF(package);


	  /* add extern filter */
	  char buf[1024];
	  sprintf(buf,"/mnt/sdcard/fgame/%s/",Sys::packageName());
	  FS_TRACE_INFO("extern read(%s)",buf);

	  VFS::PrefixNameFilter*  sdcard_filter=VFS::PrefixNameFilter::create(buf);
	  VFS::addFilter(sdcard_filter);
	  sdcard_filter->decRef();

	  /* add name filter */
	  VFS::PrefixNameFilter* assets_filter=VFS::PrefixNameFilter::create("assets/");
	  VFS::addFilter(assets_filter);
	  assets_filter->decRef();



	  /* run main.lua script */
	  ScriptEngine* sc=Global::scriptEngine();
	  sc->executeFile("main.lua");
	  sc->decRef();

  }

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    moduleExit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_moduleExit
  (JNIEnv *, jclass)
  {
	FsFaeris_ModuleExit();
  }

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onForeground
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onForeground
  (JNIEnv *, jclass)
  {
	SysDispatcher* dispatcher= Global::sysDispatcher();
	if(dispatcher)
	{
		dispatcher->dispatchSysEvent(SysDispatcher::FOREGROUND);
	}
  }

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onBackground
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onBackground
  (JNIEnv *, jclass)
  {
	SysDispatcher* dispatcher= Global::sysDispatcher();
	if(dispatcher)
	{
		dispatcher->dispatchSysEvent(SysDispatcher::BACKGROUND);
		dispatcher->update(0,0);
	}
  }

JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onKeyEventBack
  (JNIEnv *, jclass)
  {
	  

  }

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onKeyEventMenu
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onKeyEventMenu
  (JNIEnv *, jclass);

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onTouchesBegin
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onTouchesBegin
  (JNIEnv *, jclass);

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onTouchesPointerUp
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onTouchesPointerUp
  (JNIEnv *, jclass);

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onTouchesPointerDonw
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onTouchesPointerDonw
  (JNIEnv *, jclass);

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onTouchesEnd
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onTouchesEnd
  (JNIEnv *, jclass);

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onResize
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onResize
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onUpdate
 * Signature: (F)F
 */
JNIEXPORT jfloat JNICALL Java_com_faeris_lib_Fs_1Jni_onUpdate
  (JNIEnv *, jclass, jfloat);

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    onDestroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_onDestroy
  (JNIEnv *, jclass);

/*
 * Class:     com_faeris_lib_Fs_Jni
 * Method:    setEnv
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_faeris_lib_Fs_1Jni_setEnv
  (JNIEnv *, jclass, jstring, jstring);

#ifdef __cplusplus
}
#endif
