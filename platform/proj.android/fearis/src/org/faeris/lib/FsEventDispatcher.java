package org.faeris.lib;

public class FsEventDispatcher 
{
	
	public static native void onForeground();
	public static native void onBackground();
	
	public static native void onTouchBegin(int x,int y);
	public static native void onTouchMove(int x,int y);
	public static native void onTouchEnd(int x,int y);
	public static native void onTouchCanle(int x,int y);
	
	
	public static native void onResize(int width,int height);
	
	
	

}
