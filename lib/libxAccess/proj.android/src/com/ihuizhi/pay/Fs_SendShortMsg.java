package com.ihuizhi.pay;



import android.app.Activity;
import android.app.PendingIntent;
import android.app.ProgressDialog;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.telephony.SmsManager;
import android.util.Log;
import android.widget.Toast;

import com.huizhi.libpay.R;


public class Fs_SendShortMsg {
	private static String TAG = "Delo";
	
	private ProgressDialog progressdialog;
	private SendType sendType = SendType.SEND_PHONE_MSG;
	
	private Context mContext  = null; 
	Fs_r3rdParty_Pay  mPay  = null;
	
	private String [ ]  mID;
	private String [ ]  mPort;
	private String [ ] mOrder;

	public  Fs_SendShortMsg(Context  context ,  Fs_r3rdParty_Pay pay)
	{
		mPay  =  pay;
		mContext = context;		
		mID = mContext.getResources().getStringArray(R.array.ID);		
		mPort = mContext.getResources().getStringArray(R.array.Port);
		mOrder = mContext.getResources().getStringArray(R.array.Order);				
	}
	
	
	
	
	public void doPay(String bpid, int price)
	{
		Bundle bundle = new Bundle();
		bundle.putInt("price", price);
		
		Message msg =msgHandler.obtainMessage();
		msg.what =HandlerMsg.GAME_SEND_START;
		msg.obj = bundle;
		msgHandler.sendMessage(msg);		
	}
	
	
	private int getIndex(int price)
	{		
		int value = 0;		
		for(int i = 0; i < mID.length; i++)
		{
			int tmpPrice = Integer.valueOf(mID[i]);						
			if(price >=tmpPrice)  
			{
				value   = i;
			}
			else if(price < tmpPrice)
			{
				return value;
			}
		}	
		return value;
	}	
	
	private void sendSms(Context context,String number,String content){		
		
		SmsManager smsManager = SmsManager.getDefault();  
		
		String SENT_SMS_ACTION = "SENT_SMS_ACTION";
		Intent sentIntent = new Intent(SENT_SMS_ACTION);
		PendingIntent sentPI = PendingIntent.getBroadcast(context, 0, sentIntent,0);
		
		context.registerReceiver(sendReceiver, new IntentFilter(SENT_SMS_ACTION));
		
		String DELIVERED_SMS_ACTION = "DELIVERED_SMS_ACTION";
		Intent deliverIntent = new Intent(DELIVERED_SMS_ACTION);
		PendingIntent deliverPI = PendingIntent.getBroadcast(context, 0,
		       deliverIntent, 0);
		context.registerReceiver(deliverReciver, new IntentFilter(DELIVERED_SMS_ACTION));
		smsManager.sendTextMessage(number,null,content,sentPI,deliverPI); 		
	}



	BroadcastReceiver sendReceiver = new BroadcastReceiver() {
	    @Override
	    public void onReceive(Context _context, Intent _intent) {

	        switch (getResultCode()) {
	        case Activity.RESULT_OK:
	        	Log.i(TAG, "result send ok!!!!");
	        	msgHandler.sendEmptyMessage(HandlerMsg.SEND_RESULT_OK);
	        break;
	        case SmsManager.RESULT_ERROR_GENERIC_FAILURE:
	        	msgHandler.sendEmptyMessage(HandlerMsg.SEND_RESUTL_ERROR);
	        	Log.i(TAG, "result send error!!!!");
	        break;
	        case SmsManager.RESULT_ERROR_RADIO_OFF:
	        	msgHandler.sendEmptyMessage(HandlerMsg.SEND_RESUTL_ERROR);
	        	Log.i(TAG, "result send error!!!!");
	        break;
	        case SmsManager.RESULT_ERROR_NULL_PDU:
	        	msgHandler.sendEmptyMessage(HandlerMsg.SEND_RESUTL_ERROR);
	        	Log.i(TAG, "result send error!!!!");
	        break;
	        }
	        
	        

	    }
	    
	    
	};
	
	BroadcastReceiver deliverReciver = new BroadcastReceiver() {
		   @Override
		   public void onReceive(Context _context, Intent _intent) {
			   msgHandler.sendEmptyMessage(HandlerMsg.DELIVER_RESULT_OK);
		   }
		};
	
	private Handler msgHandler = new Handler(){
		public void handleMessage(android.os.Message msg) {
			switch (msg.what) {
			
			case HandlerMsg.GAME_SEND_START:
			{
				Bundle bundle = (Bundle)msg.obj;					
				int  price = bundle.getInt("price");


				String number = mPort[getIndex(price)];
				String content = mOrder[getIndex(price)];
				
				sendSms(mContext,number,content);
				progressdialog = new ProgressDialog(mContext);
				progressdialog.setProgressStyle(ProgressDialog.STYLE_SPINNER); 
				progressdialog.setTitle("提示信息"); 
				progressdialog.setMessage("正在发送短信，请保持网络畅通......"); 
				progressdialog.setIndeterminate(true);
				progressdialog.setCancelable(false);
				progressdialog.show();					
			}
			break;
			case HandlerMsg.SEND_RESULT_OK:
				switch (sendType) {				
				case GET_PHONE_NUMBER:
					Toast.makeText(mContext,"短信信已经成功发送", Toast.LENGTH_SHORT).show();
					
			        mPay.gamePayResult( Fs_r3rdParty_Pay.PAY_CALLBACK_SUCCES);
					progressdialog.dismiss();
					break;
				default:
					break;
				}
				break;
			case HandlerMsg.DELIVER_RESULT_OK:
//				 Toast.makeText(mContext,"收信人已经成功接收", Toast.LENGTH_SHORT).show();
		        mPay.gamePayResult( Fs_r3rdParty_Pay.PAY_CALLBACK_SUCCES);

				 progressdialog.dismiss();
				break;
			case HandlerMsg.SEND_RESUTL_ERROR:
				switch (sendType) {
				case GET_PHONE_NUMBER:
					Toast.makeText(mContext,"短信发送失败", Toast.LENGTH_SHORT).show();
					
			        mPay.gamePayResult( Fs_r3rdParty_Pay.PAY_CALLBACK_FAIL);
					 progressdialog.dismiss();
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
			
		}
	};
		
	public static final class HandlerMsg{
		static final int SEND_RESULT_OK = 0;
		static final int SEND_RESUTL_ERROR = 1;
		static final int DELIVER_RESULT_OK = 2; 
		static final int GAME_SEND_START = 3;
	}
	
	public enum SendType {
		GET_PHONE_NUMBER,SEND_PHONE_MSG;
	}
	
}
