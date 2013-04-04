#include "org_faeris_lib_FsEngine.h"
#include "common/FsGlobal.h"

#include "io/FsVFS.h"
#include "io/FsPackage.h"

#include "sys/platform/FsAndroidInfo.h"

NS_FS_USE

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_faeris_lib_FsEngine
 * Method:    moduleInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_faeris_lib_FsEngine_moduleInit
  (JNIEnv *, jclass)
  {
	  Global::moduleInit();

	  int width=AndroidInfo::getViewWidth();
	  int height=AndroidInfo::getViewHeight();


	  /* configure vfs */

	  /* map apk to vfs */
	  std::string apk_path=AndroidInfo::getApkPath();
	  std::string apk_name=AndroidInfo::getApkName();

	  //VFS::setRoot(apk_path.c_str());

	  Package* package=Package::create(apk_path.c_str(),Package::PACKAGE_ZIP);

	  FS_TRACE_INFO("apk path=%s",apk_path.c_str());
	  FS_TRACE_INFO("apk name=%s",apk_name.c_str());


	  if(package==NULL)
	  {
		  FS_TRACE_WARN("load package %s  failed",apk_path.c_str());
	  }
	  else 
	  {
		  VFS::mapPackage("",package);
	  }
	  FS_SAFE_DEC_REF(package);


	  /* add name filter */
	  VFS::PrefixNameFilter* filter=VFS::PrefixNameFilter::create("assets/");
	  VFS::addFilter(filter);
	  filter->decRef();

	  /* set render viewport */
	  Render* render=Global::render();
	  render->setViewport(0,0,width,height);

	  /* run main.lua script */
	  ScriptEngine* sc=Global::scriptEngine();
	  sc->executeFile("main.lua");
	  sc->decRef();


  }

/*
 * Class:     org_faeris_lib_FsEngine
 * Method:    moduleExit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_faeris_lib_FsEngine_moduleExit
  (JNIEnv *, jclass)
{
	Global::moduleExit();
}

/*
 * Class:     org_faeris_lib_FsEngine
 * Method:    onForeground
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_faeris_lib_FsEngine_onForeground
  (JNIEnv *, jclass)
{
	SysDispatcher* dispatcher= Global::sysDispatcher();
	if(dispatcher)
	{
		dispatcher->dispatchSysEvent(SysDispatcher::FOREGROUND);
	}
}

/*
 * Class:     org_faeris_lib_FsEngine
 * Method:    onBackground
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_faeris_lib_FsEngine_onBackground
  (JNIEnv *, jclass)
{
	SysDispatcher* dispatcher= Global::sysDispatcher();
	if(dispatcher)
	{
		dispatcher->dispatchSysEvent(SysDispatcher::BACKGROUND);
	}
}

/*
 * Class:     org_faeris_lib_FsEngine
 * Method:    onTouchBegin
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_org_faeris_lib_FsEngine_onTouchBegin
  (JNIEnv *, jclass, jint x, jint y)
{
	TouchDispatcher* dispatcher=Global::touchDispatcher();
	if(dispatcher)
	{
		dispatcher->dispatchTouchEvent(TouchDispatcher::TOUCH_BEGIN,x,y);
	}

}

/*
 * Class:     org_faeris_lib_FsEngine
 * Method:    onTouchMove
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_org_faeris_lib_FsEngine_onTouchMove
  (JNIEnv *, jclass, jint x, jint y)
{
	TouchDispatcher* dispatcher=Global::touchDispatcher();
	if(dispatcher)
	{
		dispatcher->dispatchTouchEvent(TouchDispatcher::TOUCH_MOVE,x,y);
	}
}

/*
 * Class:     org_faeris_lib_FsEngine
 * Method:    onTouchEnd
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_org_faeris_lib_FsEngine_onTouchEnd
  (JNIEnv *, jclass, jint x, jint y)
{
	TouchDispatcher* dispatcher=Global::touchDispatcher();
	if(dispatcher)
	{
		dispatcher->dispatchTouchEvent(TouchDispatcher::TOUCH_END,x,y);
	}
}

/*
 * Class:     org_faeris_lib_FsEngine
 * Method:    onTouchCancel
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_org_faeris_lib_FsEngine_onTouchCancel
  (JNIEnv *, jclass, jint x, jint y)
{
	TouchDispatcher* dispatcher=Global::touchDispatcher();
	if(dispatcher)
	{
		dispatcher->dispatchTouchEvent(TouchDispatcher::TOUCH_CANCEL,x,y);
	}
}

/*
 * Class:     org_faeris_lib_FsEngine
 * Method:    onResize
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_org_faeris_lib_FsEngine_onResize
  (JNIEnv *, jclass, jint width, jint height)
{
	AndroidInfo::setViewSize(width,height);
	Render* render=Global::render();
	if(render)
	{
		render->setViewport(0,0,width,height);
	}
}


/*
 * Class:     org_faeris_lib_FsEngine
 * Method:    onViewCreated
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_faeris_lib_FsEngine_onViewCreated
  (JNIEnv *, jclass)
{

}

/*
 * Class:     org_faeris_lib_FsEngine
 * Method:    onUpdate
 * Signature: (F)V
 */
JNIEXPORT void JNICALL Java_org_faeris_lib_FsEngine_onUpdate
  (JNIEnv *, jclass, jfloat dt)
{
	Global::scheduler()->update(dt);
}

#ifdef __cplusplus
}
#endif





