package org.faeris.lib;
import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.util.Log;

public class FsGlobal 
{
	private static String m_packageName;
	private static String m_apkPath;
	private static String m_dataDir;
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
		m_dataDir=context.getFilesDir().getAbsolutePath();
	}
	
	/* home Directory */
	public static String getDataDir()
	{
		return FsGlobal.m_dataDir;
	}
	public static void setDataDir(String path)
	{
		FsGlobal.m_dataDir=path;
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
	}
	
}
