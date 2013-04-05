package org.faeris.lib;
import android.content.Context;
import android.content.pm.ApplicationInfo;


public class FsAndroidInfo 
{
	
	public static void init(final Context context)
	{
		final ApplicationInfo app_info= context.getApplicationInfo();
		String apk_name=app_info.packageName;
		String source_dir=app_info.sourceDir;
		setApkName(apk_name);
		setApkPath(source_dir);
	}
	
	
	private static native void setApkName(final String apk_path);
	private static native void setApkPath(final String source_dir);

}
