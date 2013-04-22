#ifndef _FS_ANDROID_INFO_H_
#define _FS_ANDROID_INFO_H_

#include <jni.h>
#include <string>
#include "FsMacros.h"

NS_FS_BEGIN

class  AndroidInfo 
{
	public:
		/* jvm */
		static void setJavaVM(JavaVM* vm); 
		static JavaVM* getJavaVM();


		/* view size */
		static int getViewWidth();
		static int getViewHeight();
		static int setViewSize(int width,int height);


		/* apk path */
		static std::string getApkPath();
		static std::string getApkName();
		static void setApkPath(const char* path);
		static void setApkName(const char* name);



	private:
		static int m_width;
		static int m_height;
		static std::string* m_apkPath;
		static std::string* m_apkName;
		static JavaVM* m_jvm;
};
NS_FS_END 

#endif /*_FS_ANDROID_INFO_H_*/


