package com.ihuizhi.minder;

public class Fs_r3rdPartyJni {

	public static native void onForeground();
	
	public static native void NativeBillingPointCB(String bpid, int ret);
	
	public static native void NativeCheckUpdateCB(long objAdd,  int ret);
	
}
