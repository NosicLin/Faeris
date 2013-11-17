package com.rThirdParty.pay;

import android.content.Context;
import android.util.Log;

import com.faeris.lib.Fs_Application;
import com.rThirdParty.Fs_r3rdPartyJni;

public class Fs_r3rdParty_Pay  {
	
	protected String payBpid = null;	
	protected int payRet = -1;
	private Context mContext = null;
	
	public Fs_r3rdParty_Pay(Context context)
	{
		mContext = context;
	}
	
	
	private void setPayCallBackResult(String bpid, int ret)
	{
		payBpid  = bpid; 
		payRet = ret;
	}
		
	public boolean game3rdPartyPay(String bpid , String price)
	{
		if( payBpid != null ) 		//防止 重复计费
		{
			 return  false;
		}
	 	Log.i("Delo", "bpid:"+bpid+"   ret:"+ price);

		setPayCallBackResult(bpid, 0);
		
		//  模拟 成功计费。 这里需要 调用计费接口 。 
		
		Fs_Application.runOnEngineThread(new Runnable() {
			@Override
			public void run() {
				// TODO Auto-generated method stub
				Fs_r3rdPartyJni.NativeBillingPointCB(payBpid, payRet);				
				setPayCallBackResult(null, -1);							
			}
		});		
		return true;
	}
	

}
