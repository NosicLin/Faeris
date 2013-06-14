package com.faeris.lib;

public class Fs_Jni {
	
	/* Init add Exit FsEngine Module */
	public static native void moduleInit();
	public static native void moduleExit();
	
	
	
	/* sys event */
	public static native void onForeground();
	public static native void onBackground();
	
	/* touch event */
	public static native void onTouchBegin(float x,float y);
	public static native void onTouchMove(float x,float y);
	public static native void onTouchEnd(float x,float y);
	public static native void onTouchCancel(float x,float y);
	
	/* menu event */
	public static native void onKeyEventBack();
	public static native void onKeyEventMenu();
	
	/* input method */
	
	/* touches event */
	public static native void onTouchesBegin();
	public static native void onTouchesPointerUp();
	public static native void onTouchesPointerDonw();
	public static native void onTouchesEnd();
	
	/* surface event */
	public static native void onResize(int width,int height);

	/* update event */
	public static native float onUpdate(float dt);
	
	/* destory event */
	public static native void onDestroy();
	
	
	/* env */
	public static native void setEnv(String name,String value);
	
	
	
	


}
