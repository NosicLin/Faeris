package com.ihuizhi.pay;

import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.ComponentName;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Handler;
import android.os.Message;
import android.text.TextUtils;
import android.util.Log;
import android.widget.Toast;

import com.faeris.lib.Fs_Application;
import com.huizhi.libpay.R;
import com.ihuizhi.android.CustomerHttpClient;
import com.ihuizhi.android.SysUtil;
import com.ihuizhi.gamesdk.HuiZhi_GameCenter;
import com.ihuizhi.gamesdk.pay.HuiZhi_PayRequest;
import com.ihuizhi.gamesdk.pay.VG_PayCallback;
import com.ihuizhi.gamesdk.utils.StringUtil;
import com.ihuizhi.gamesdk.vo.VG_PayBean;
import com.ihuizhi.minder.Fs_r3rdPartyJni;
import com.ihuizhi.vo.PhoneInfoVo;

public class Fs_r3rdParty_Pay  {
	
	public static final int PAY_CALLBACK_FAIL = 0;
	public static final int PAY_CALLBACK_SUCCES = 1;
	
	public static final int PAY_ACK_NET = 10;

	
	private String TAG = "Delo";
	protected String payBpid = null;	
	protected int payRet = -1;
	private Activity mContext = null;
	private Fs_SendShortMsg mShortMsg = null;

	
	public Fs_r3rdParty_Pay(Activity context)
	{
		mContext = context;
		
		InitPay(context);
	}
	  
	public void InitPay(Activity context)
	{
	   HuiZhi_GameCenter.getInstance().initSDK(context);
	}
	
	private void setPayCallBackResult(String bpid, int ret)
	{
		payBpid  = bpid; 
		payRet = ret;
	}
	
	
	private HuiZhi_PayRequest getPayRequest(String bpid, String price)
	{
		HuiZhi_PayRequest payRequest = new HuiZhi_PayRequest();
		Properties properties = new Properties();
		InputStream inputStream;  
        try {  
        	inputStream = mContext.getAssets().open("ihuizhiPay.properties");  
        	properties.load(inputStream);
        	payRequest.setAppId(StringUtil.getStr(properties.getProperty("appId"), ""));
        	
        	payRequest.setPartnerId(StringUtil.getStr(properties.getProperty("partnerId"), ""));
        	payRequest.setQn(StringUtil.getStr(properties.getProperty("qn"), ""));
        	payRequest.setSignType(StringUtil.getStr(properties.getProperty("signType"), ""));
        	payRequest.setRsaPrivateKey(StringUtil.getStr(properties.getProperty("privateKey"), ""));
                	
        	/********
        	 * 
        	 * 第三方请求配置,默认为""字符串
        	 * 
        	 *********/
    		payRequest.setBackEndUrl(mContext.getResources().getString(R.string.sdkNotifyUrl));
    		payRequest.setTradeDesc(mContext.getResources().getString(R.string.sdkDesc));    		
    		payRequest.setReqFee(price); // 单位元
    		payRequest.setTradeName(bpid);
        	payRequest.setPayerId("");  //玩家id值
    		         	
        } catch (IOException e) {  
        	
        	gamePayResult(Fs_r3rdParty_Pay.PAY_CALLBACK_FAIL);
        	
            e.printStackTrace();  
        }

			return payRequest;
	}
	
	private void startPay(String bPrice) {
		
		HuiZhi_PayRequest  payRequest = getPayRequest(payBpid, bPrice);
		
		HuiZhi_GameCenter.getInstance().startPay(payRequest, mContext,
				new VG_PayCallback() {
			
					@Override
					public void onPayCallback(int retCode, VG_PayBean payBean) {
						int ret = -1;
						if (retCode == 0) {
							ret = Fs_r3rdParty_Pay.PAY_CALLBACK_SUCCES;
									
							Toast.makeText(mContext, "支付成功",
									Toast.LENGTH_SHORT).show();
						}else if(retCode == -1){
							
							ret = Fs_r3rdParty_Pay.PAY_CALLBACK_FAIL;
							
							Toast.makeText(mContext, "发送请求不成功",
									Toast.LENGTH_LONG).show();
						}else if(retCode == -2){
							ret = Fs_r3rdParty_Pay.PAY_CALLBACK_FAIL;

							Toast.makeText(mContext, "请求异常",
									Toast.LENGTH_LONG).show();
						}
						else if(retCode == -999){
							ret = Fs_r3rdParty_Pay.PAY_CALLBACK_FAIL;

							Toast.makeText(mContext, "用户取消支付",
									Toast.LENGTH_LONG).show();
						}else {
							
							ret = Fs_r3rdParty_Pay.PAY_CALLBACK_FAIL;
							Toast.makeText(mContext, "支付失败",
									Toast.LENGTH_LONG).show();
						}												
						gamePayResult(ret);
						
					}
				});
				
	}
	
	public void showSetNetWorkDialog(final Context context)
	{
		 AlertDialog.Builder builder = new AlertDialog.Builder(context);
	        builder.setIcon(android.R.drawable.ic_dialog_alert);
	        builder.setTitle(R.string.netstate);
	        builder.setMessage(R.string.setnetwork);
	        builder.setPositiveButton(R.string.Set, new DialogInterface.OnClickListener() {
	            
	            @Override
	            public void onClick(DialogInterface dialog, int which) {
	                // TODO Auto-generated method stub
	                Intent intent = new Intent("/");
	                
	            	  if(android.os.Build.VERSION.SDK_INT>10){
	            		  intent = new Intent(android.provider.Settings.ACTION_WIRELESS_SETTINGS);
	            	  }else{
	            		  intent = new Intent();
	            		         ComponentName component = new ComponentName("com.android.settings","com.android.settings.WirelessSettings");
	            		         intent.setComponent(component);
	            		         intent.setAction("android.intent.action.VIEW");
	            		      }	            	  
	                context.startActivity(intent);	                
	                
	       //        Fs_Application.asynExit();	                
	            }
	        });
	        builder.setNegativeButton(R.string.Cancel, new DialogInterface.OnClickListener() {
	            
	            @Override
	            public void onClick(DialogInterface dialog, int which) {	            	
	                dialog.cancel();		                
	                
	                Toast.makeText(mContext, "购买失败！", Toast.LENGTH_LONG).show();
	         //       Fs_Application.asynExit();
	            }
	        });
	        builder.create();
	        builder.show();
	    }	    
	
	private Handler msgHandler = new Handler(){
		public void handleMessage(android.os.Message msg) {
			switch (msg.what) {
			case Fs_r3rdParty_Pay.PAY_ACK_NET:
			{
				  
				showSetNetWorkDialog(mContext);
				
				gamePayResult(Fs_r3rdParty_Pay.PAY_CALLBACK_FAIL);
				
			}
			break;
			}
			
		}
	};
	
	public void  gamePayResult(int ret)
	{
			payRet = ret;
			
			Fs_Application.runOnEngineThread(new Runnable() {
				@Override
				public void run() {
					// TODO Auto-generated method stub
					Fs_r3rdPartyJni.NativeBillingPointCB(payBpid, payRet);				
					setPayCallBackResult(null, -1);	
				}
			});				
	}

	public boolean game3rdPartyPay(String bpid , String price)
	{
		if( payBpid != null ) 		//防止 重复计费  SDK退出activity的时候不会返回结果.暂时不锁计费
		{
			Log.i("Delo","购买 冲突！ ");
			 return  false;
		}
	 	Log.i("Delo", "bpid:"+bpid+"   ret:"+ price);
	 		 	
		setPayCallBackResult(bpid, Fs_r3rdParty_Pay.PAY_CALLBACK_FAIL);
		int gamePrice = Integer.valueOf(price);
		int spType = 0;
		//  模拟 成功计费。 这里需要 调用计费接口 。
		 PhoneInfoVo phoneInfoVo = CustomerHttpClient.getPhoneInfoVo(mContext);
        /***
         * 获取手机基本信息 
         *包括手机imsi,imei,序列号
         */
     	String imsi = phoneInfoVo.getImsi();                       
        if (!SysUtil.isNetworkAvailable(mContext))
        {
        	
			if ( !TextUtils.isEmpty(phoneInfoVo.getImsi()) && StringUtil.isNotBlank(phoneInfoVo.getSimSerialNumber())&& (imsi.startsWith("46000") || imsi.startsWith("46002") )&& gamePrice <= 40)
        	{ // 移动支付
       		
        		if(mShortMsg ==null)
        			mShortMsg = new Fs_SendShortMsg(mContext , this );
        		
        		mShortMsg.doPay(payBpid, gamePrice);
        	}
        	else{
        		Message msg =msgHandler.obtainMessage();
        		msg.what = PAY_ACK_NET;
        		msgHandler.sendMessage(msg);		
        	}
        }
        else
        {    		
        	startPay(price);
        }    
		
		return true;
	}
	

}
