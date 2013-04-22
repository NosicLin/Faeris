#include "FsAndroidInfo.h"

NS_FS_BEGIN

/* view size */
int AndroidInfo::m_width=0;
int AndroidInfo::m_height=0;

/* apk info */
std::string* AndroidInfo::m_apkPath=NULL;
std::string* AndroidInfo::m_apkName=NULL;
JavaVM* AndroidInfo::m_jvm=NULL;


void AndroidInfo::setJavaVM(JavaVM* vm)
{
	m_jvm=vm;
}
JavaVM* AndroidInfo::getJavaVM()
{
	return m_jvm;
}


/* view size */
int AndroidInfo::getViewWidth()
{
	return m_width;
}

int AndroidInfo::getViewHeight()
{
	return m_height;
}

int AndroidInfo::setViewSize(int width,int height)
{
	m_width=width;
	m_height=height;
}


/* apk path */
void AndroidInfo::setApkPath(const char* path)
{
	if(m_apkPath==NULL)
	{
		m_apkPath=new std::string;
	}
	*m_apkPath=path;
}
void AndroidInfo::setApkName(const char* name)
{
	if(m_apkName==NULL)
	{
		m_apkName=new std::string;
	}
	*m_apkName=name;
}

std::string AndroidInfo::getApkPath()
{
	return m_apkPath!=NULL?*m_apkPath:"";
}
std::string AndroidInfo::getApkName()
{
	return m_apkName!=NULL?*m_apkName:"";
}


NS_FS_END

