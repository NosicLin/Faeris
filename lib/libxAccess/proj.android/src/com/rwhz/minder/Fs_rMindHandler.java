package com.rwhz.minder;


import com.rwhz.pay.Fs_r3rdParty_Pay;
import com.rwhz.secure.Fs_UpdateHelper;
import com.tendcloud.tenddata.TCAgent;

import android.content.Context;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.style.BulletSpan;
import android.util.Log;
import android.widget.Toast;


public class Fs_rMindHandler extends Handler {
	
	public static final int MIND_HANDLER_GAME_PAY = 10;
	public static final int MIND_HANDLER_TALKINGDATA = 11;
	public static final int MIND_HANDLER_CHECKUPDATE = 12;

	
	private static Fs_r3rdParty_Pay _3rdPay =  null;
	private  Fs_UpdateHelper mHelper = null;

	private Context  mContext = null;
	
	
	public Fs_rMindHandler(Context context)
	{
		super();
		
		mContext  = context;
		
		if(_3rdPay == null)
			_3rdPay = new Fs_r3rdParty_Pay(mContext);
		
	}

	public void handleMessage(Message msg)
	{
		switch(msg.what)
		{
		
			case Fs_rMindHandler.MIND_HANDLER_GAME_PAY :{		
				
				Bundle bundle = (Bundle)msg.obj;	
				if( ! _3rdPay.game3rdPartyPay(bundle.getString("bpid"), bundle.getString("price"))){
					
					 Toast.makeText(mContext, "计费错误，请稍后重试！", Toast.LENGTH_SHORT);
				}
				break;
			}
				case Fs_rMindHandler.MIND_HANDLER_TALKINGDATA:{
					Bundle bundle = (Bundle)msg.obj;					
					logTalkingData(bundle.getString("eventID"), bundle.getString("eventLabel"));
				}				
					break;
				case Fs_rMindHandler.MIND_HANDLER_CHECKUPDATE:{
					Bundle bundle = (Bundle)msg.obj;
					if(mHelper == null)
					mHelper = new Fs_UpdateHelper(mContext);			
					
					mHelper.checkUpdate(bundle.getLong("objADD"));
					
				}					
		}
	}	

	public void onResume(Context context)
	{
		if(mHelper !=null  && mHelper.isDownlock())
		{
			mHelper.askSeverNewUpdate();
		}		
	}
	
	public void logTalkingData(String eventID, String eventLabel)
	{
	 	Log.i("Delo", "eventID"+eventID +"   eventLabel:"+ eventLabel);		
	 	
		if(eventLabel!=null && eventLabel.length()>0)
		{
			TCAgent.onEvent(mContext, "测试事件","嗯，测试的");
			//Log.e("Delo", "logTalkingData:"+eventId+" :"+label);
		}
		else
		{
			TCAgent.onEvent(mContext, eventID);
			//Log.e("Delo", "logTalkingData:"+eventId);
		}
		
	}
	
}
