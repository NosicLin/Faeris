package com.ihuizhi.minder;

import android.os.Bundle;
import android.os.Message;
import android.util.Log;

public class Fs_rCallFunction {
		
	public static void BillingPointUp(String bpid, String price)
	{
		  //发送支付消息
		 	
			Bundle bundle = new Bundle();
			bundle.putString("bpid", bpid);
			bundle.putString("price",price);
			
			Message msg = Fs_rMinder.mHandler.obtainMessage();
			msg.what =Fs_rMindHandler.MIND_HANDLER_GAME_PAY;
			msg.obj = bundle;
			Fs_rMinder.mHandler.sendMessage(msg);
			
	}
	
	public static void LogTalkingData(String eventID, String eventLabel)
	{
			 	
		Bundle bundle = new Bundle();
		bundle.putString("eventID", eventID);
		bundle.putString("eventLabel",eventLabel);
		
		Message msg = Fs_rMinder.mHandler.obtainMessage();
		msg.what =Fs_rMindHandler.MIND_HANDLER_TALKINGDATA;
		msg.obj = bundle;
		Fs_rMinder.mHandler.sendMessage(msg);
	}
	
	
	public static void CheckUpdate(long objADD)
	{	
		Bundle bundle = new Bundle();
		bundle.putLong("objADD", objADD);
		Message msg = Fs_rMinder.mHandler.obtainMessage();
		msg.what =Fs_rMindHandler.MIND_HANDLER_CHECKUPDATE;
		msg.obj = bundle;
		Fs_rMinder.mHandler.sendMessage(msg);
	}
	
}
