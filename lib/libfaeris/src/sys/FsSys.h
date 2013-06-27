#ifndef _FS_SYS_H_
#define _FS_SYS_H_

#include "FsMacros.h"
#define FS_SYS_TEMP_BUF_SIZE 2048

#if FS_PLATFORM_OS(FS_OS_ANDROID)
	#include <jni.h>
#endif 


NS_FS_BEGIN 
class FsDict;
class Sys
{
	public:
		static bool moduleInit();
		static bool moduleExit();

		/* common */
		static void usleep(long time);
		static const char* currentDir();

		static const char* deviceName();
		static const char* imei();
		static const char* getEnv(const char* key);
		static void setEnv(const char* key,const char* value); 

		/* io function */
		static int mkdir(const char* name);
		static bool isDir(const char* name);


	private:
		static FsDict* m_env;
		static char m_tempBuf[FS_SYS_TEMP_BUF_SIZE];



		/*  android interface  */
#if FS_PLATFORM_OS(FS_OS_ANDROID)
	public:
		static void setJavaVM(JavaVM* jvm);
		static JavaVM* getJavaVM();
		static const char* packageName();
		static const char* apkPath();
	private:
		static JavaVM* m_jvm;
#endif 

};

NS_FS_END 
#endif /* _FS_SYS_H_ */




