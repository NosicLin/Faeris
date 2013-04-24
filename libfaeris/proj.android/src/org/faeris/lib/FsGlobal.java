package org.faeris.lib;
import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.util.Log;

public class FsGlobal 
{
	private static String m_packageName;
	private static String m_apkPath;
	private static String m_homeDirectoy;
	private static Context m_context=null;
	
	
	/* context */
	public static Context getContext()
	{
		return FsGlobal.m_context;
	}
	
	public static void setContext(Context context)
	{
		final ApplicationInfo app_info=context.getApplicationInfo();
		FsGlobal.m_context=context;
		m_packageName=app_info.packageName;
		m_apkPath=app_info.sourceDir;
	}
	
	/* home Directory */
	public static String getHomeDirectory()
	{
		return FsGlobal.m_homeDirectoy;
	}
	public static void setHomeDirectory(String path)
	{
		FsGlobal.m_homeDirectoy=path;
		nativeSetHomeDirectory(path);
	}
	
	/* package name */
	public static String getPackageName()
	{
		return FsGlobal.m_packageName;
	}
	public static String getApkPath()
	{
		return FsGlobal.m_apkPath;
	}
	
	public static void setPackageName(String name)
	{
		FsGlobal.m_packageName=name;
		nativeSetPackageName(name);
	}
	
	
	/* native */
	public static native void nativeSetPackageName(String name);
	public static native void nativeSetHomeDirectory(String name);
	
}
