package com.faeris.lib;


import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.view.ViewGroup;
import android.widget.FrameLayout;


public abstract class Fs_Activity extends Activity
{
	/* attibute */
	
	private Fs_GLSurfaceView m_view;

	/* method */
	
	@Override 
	protected void onCreate(final Bundle save_state)
	{
		super.onCreate(save_state);
		
		Fs_Application.setContext(this);
		this.initEnv(); 
		
		this.initView();
	}
	
	@Override 
	protected void onResume()
	{
		super.onResume();
		this.m_view.onResume();
		Fs_Jni.onForeground();
	}

	@Override
	protected void onPause()
	{
		super.onPause();
		this.m_view.onPause();
		Fs_Jni.onBackground();
	}
	
	
	
	@Override
	protected void onDestroy()
	{
		super.onDestroy();
		Fs_Jni.onDestroy();
		android.os.Process.killProcess(android.os.Process.myPid());
	}
	
	protected void initView()
	{
		m_view=new Fs_GLSurfaceView(this);
		Fs_GLRender r=new Fs_GLRender();
		
		m_view.setFsGLRender(r);
		this.setContentView(m_view);
	}
	protected void initEnv()
	{
		String os_type=Fs_Application.getOsType();
		String os_version=Fs_Application.getOsVersion();
		String package_name=Fs_Application.getPackageName();
		String device_name=Fs_Application.getDeviceName();
		String imei=Fs_Application.getIMEI();
		String imsi=Fs_Application.getIMSI();

		Fs_Jni.setEnv("os_type",os_type);
		Fs_Jni.setEnv("os_version",os_version);
		Fs_Jni.setEnv("package_name",package_name);
		Fs_Jni.setEnv("device_name",device_name);
		Fs_Jni.setEnv("imei",imei);
		Fs_Jni.setEnv("imsi",imsi);
	}
	
	
	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
	    	if (keyCode == KeyEvent.KEYCODE_BACK) {
	    		android.os.Process.killProcess(android.os.Process.myPid());
	    	}
	        return super.onKeyDown(keyCode, event);
	}
}