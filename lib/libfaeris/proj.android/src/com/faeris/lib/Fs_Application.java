package com.faeris.lib;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.telephony.TelephonyManager;
import android.util.Log;
import android.os.Build;
import android.os.Message;

public class Fs_Application 
{
	private static String m_packageName;
	private static String m_apkPath;
	private static String m_dataDir;
	private static String m_externalDir;
	
	private static Fs_Activity m_context=null;
	
	private static Fs_UiEvent m_eventHandler=null;
	
	/* because get imei and imsi need permission, so give them a  init version in case of permission deny */ 
	private static String m_IMEI="0000000000"; 
	private static String m_IMSI="0000000000";
	
	/* context */
	public static Fs_Activity getContext()
	{
		return Fs_Application.m_context;
	}
	
	public static void setContext(Fs_Activity context)
	{
		final ApplicationInfo app_info=context.getApplicationInfo();
		Fs_Application.m_context=context;
		m_packageName=app_info.packageName;
		m_apkPath=app_info.sourceDir;
		m_dataDir=context.getFilesDir().getAbsolutePath();
		m_eventHandler=new Fs_UiEvent();
		m_externalDir="/mnt/sdcard/fgame/"+m_packageName+"/";
		
		/* imei and imsi */
		TelephonyManager tm=(TelephonyManager) m_context.getSystemService(Context.TELEPHONY_SERVICE);
		String imei= tm.getDeviceId();
		
		if(imei!=null)
		{
			m_IMEI=imei;
		}
		
		if (tm.getSimState()==TelephonyManager.SIM_STATE_READY) 
		{
			m_IMSI= tm.getSubscriberId();
		}
					
	}
	
	public static void asynExit()
	{
		Message msg=new Message();
		msg.what=Fs_UiEvent.UIEVENT_EXIT;
		msg.obj=null;
		m_eventHandler.handleMessage(msg);
	}
	public static void exit()
	{
		m_context.finish();
	}
	
	/* external dir */
	public static String getExternalDir()
	{
		return m_externalDir;
	}
	
	/* home Directory */
	public static String getDataDir()
	{
		return Fs_Application.m_dataDir;
	}
	public static void setDataDir(String path)
	{
		Fs_Application.m_dataDir=path;
	}
	
	/* package name */
	public static String getPackageName()
	{
		return Fs_Application.m_packageName;
	}
	public static String getApkPath()
	{
		return Fs_Application.m_apkPath;
	}
	
	public static void setPackageName(String name)
	{
		Fs_Application.m_packageName=name;
	}
	
	/* imei and imsi */
	public static String getIMEI(){

		return m_IMEI;
	}
	public static String getIMSI(){
		return m_IMSI;
	}

	/* os version */
	public static String getOsVersion()
	{
		return Build.VERSION.RELEASE;
	}

	public static String getOsType()
	{
		return "android";
	}

	/* device name */
	public static String getDeviceName()
	{
		return Build.MODEL;
	}




}
