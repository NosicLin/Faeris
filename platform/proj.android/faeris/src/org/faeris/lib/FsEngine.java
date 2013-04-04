package org.faeris.lib;

public class FsEngine {
	
	/* Init add Exit FsEngine Module */
	public static native void moduleInit();
	public static native void moduleExit();
	
	
	
	/* sys event */
	public static native void onForeground();
	public static native void onBackground();
	
	/* touch event */
	public static native void onTouchBegin(int x,int y);
	public static native void onTouchMove(int x,int y);
	public static native void onTouchEnd(int x,int y);
	public static native void onTouchCancel(int x,int y);
	
	
	/* surface event */
	public static native void onResize(int width,int height);
	public static native void onViewCreated();
	
	
	public static native void onUpdate(float dt);
	
	
	


}
