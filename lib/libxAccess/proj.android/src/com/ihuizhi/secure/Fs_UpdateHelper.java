package com.ihuizhi.secure;

import java.io.File;
import java.text.SimpleDateFormat;
import java.util.Date;

import org.apache.http.HttpResponse;
import org.apache.http.util.EntityUtils;
import org.json.JSONObject;


import com.faeris.lib.Fs_Application;
import com.huizhi.libpay.R;
import com.ihuizhi.android.SysUtil;
import com.ihuizhi.minder.Fs_r3rdPartyJni;
import com.ihuizhi.net.HttpAsync;
import com.ihuizhi.net.HttpCallback;

import android.app.AlertDialog;
import android.content.ComponentName;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.widget.Toast;



public class Fs_UpdateHelper {
	
	public static final String TAG  = "Delo";
	
	public static final int RQF_INSTALL_CHECK = 4;
	public static final int RQF_INSTALL_FAIL = -1;
	public static final int RQF_INSTALL_SUCCESS = 1;

   private static final long mForceTimeMillis = 1385018413199l + 2592000000l ; // 2592000000;
	
//	private ProgressDialog mProgress = null;
   private  Context mContext = null;
   private Fs_UpdateInfo mInfo  = null;
   
   private boolean  mDownlock = false;
   private  long mObjADD ;
   
   private boolean mIsForceUpdate =  false;
   
	public Fs_UpdateHelper(Context context){
		mContext = context;
		mDownlock = false;
		
		mIsForceUpdate =  getForceUpdateStatus();		
	}
		
	
	public void checkUpdate( long objADD)
	{
			mObjADD = objADD;
			
			if (mIsForceUpdate && ! SysUtil.isNetworkAvailable(mContext))
			{
				showSetNetWorkDialog(mContext);
			}
			else									
				askSeverNewUpdate();								
	}
	
	private void checkUpdateCallBack(final int result)
	{
		//  模拟 成功计费。 这里需要 调用计费接口 。 		
		Fs_Application.runOnEngineThread(new Runnable() {
			@Override
			public void run() {
				// TODO Auto-generated method stub
				Fs_r3rdPartyJni.NativeCheckUpdateCB(mObjADD, result);
			}
		});
		
	}	
	
	
	public void askSeverNewUpdate()
	{		
		// 实例新线程检测是否有新版本进行下载		
		HttpAsync httpAsync = new HttpAsync();
		
		int versionCode = SysUtil.getVersionCode(mContext);
		
		int channel = SysUtil.getAppInterMeta(mContext, "CHANNEL");
		
		String packageName = SysUtil.getPackageName(mContext);
	
		String url  = mContext.getResources().getString(R.string.updateUrl);
		
		url = url + "pn="+packageName+"&ver="+ versionCode + "&platId="+channel;
		
		Log.i(TAG, "update : url :" + url);
		
		httpAsync.setUrl(url);
		
		httpAsync.setHttpCallback(new HttpCallback(){
			 		public void onSuccess(HttpResponse response)
			 		{//...请求成功后的处理
			 							 			
			 			try {
			 				
			 		       String content = EntityUtils.toString(response.getEntity(),"UTF-8");			 		       
				 			JSONObject req = new JSONObject(content);				 							 			

				 			Log.i(TAG, "update : result:" + req.toString());				 							 			

			 				Fs_UpdateInfo Info = new Fs_UpdateInfo();			 				
				 			Info.parseJson(req);
				 							 			
				 			if(  Info.getResult() == 0 )
				 			{
				 				if(Info.getApkUrl().length() > 0)
				 				{
				 					SendMessage(Fs_UpdateHelper.RQF_INSTALL_CHECK , Info);				 				
				 				}
				 				else
				 				{
				 					SendMessage(Fs_UpdateHelper.RQF_INSTALL_SUCCESS , Info);				 								 								 					
				 				}
				 			}
				 			else
					 			SendMessage(Fs_UpdateHelper.RQF_INSTALL_FAIL , Info.getMsg());	
				 			
						} catch (Exception e) {
							// TODO Auto-generated catch block							
				 			SendMessage(Fs_UpdateHelper.RQF_INSTALL_FAIL ,"获取网络数据异常");						 							  										
							e.printStackTrace();
						}			 			
			  		}
			  		public void onFail(int errorCode, String errorMessage)
			  		{//...请求失败后的处理
			 			SendMessage(Fs_UpdateHelper.RQF_INSTALL_FAIL ,errorMessage);						 							  			
			  		}
			  	});
			  	//...设置表单项目和头项目
			  	httpAsync.get();
	}
	
	//
	// the handler use to receive the install check result.
	// 此处接收安装检测结果
	private Handler mHandler = new Handler() {
		public void handleMessage(Message msg) {
			try {
				switch (msg.what) {
				
					case Fs_UpdateHelper.RQF_INSTALL_CHECK: {
						//	可以更新				
						mInfo = (Fs_UpdateInfo) msg.obj;					
						
						showInstallConfirmDialog(mContext,"");
					}
					break;
						
					case Fs_UpdateHelper.RQF_INSTALL_SUCCESS:
					{//成功
						setDownlock(false);
						
						checkUpdateCallBack(RQF_INSTALL_SUCCESS);						
					}
					break;
					case Fs_UpdateHelper.RQF_INSTALL_FAIL:{
						//有错误，或者不需要更新
						String Eerromsg = (String)msg.obj;						
						Log.i(TAG, Eerromsg);						
						if(mIsForceUpdate){
							
							Toast.makeText(mContext, "网络错误！错误代码 - "+Eerromsg, Toast.LENGTH_LONG);
							Fs_Application.asynExit();						
						}
						else{
							checkUpdateCallBack(RQF_INSTALL_FAIL);  // -- 暂时强制关掉							
						}
					}
					break;
				}				
				super.handleMessage(msg);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	};
	
	private void SendMessage(int what, Object obj)
	{
		Message msg = new Message();
		msg.what = what;
		msg.obj = obj;
		mHandler.sendMessage(msg);
	}
	
	
	/**
	 * 显示确认安装的提示
	 * 
	 * @param context
	 *            上下文环境
	 * @param cachePath
	 *            安装文件路径
	 */
	public void showInstallConfirmDialog(final Context context,
			final String cachePath) {
		AlertDialog.Builder tDialog = new AlertDialog.Builder(context);
//		tDialog.setIcon(R.drawable.info);
		tDialog.setTitle(context.getResources().getString(
				R.string.confirm_install_hint));
		tDialog.setMessage(context.getResources().getString(
				R.string.confirm_install));
		
		tDialog.setPositiveButton(R.string.Ensure,
				new DialogInterface.OnClickListener() {
					public void onClick(DialogInterface dialog, int which) {						
						//						
						SysUtil.browserInterface(mContext, mInfo.getApkUrl());
						setDownlock(true);
					}
				});

		tDialog.setNegativeButton(
				context.getResources().getString(R.string.Cancel),
				new DialogInterface.OnClickListener() {
					public void onClick(DialogInterface dialog, int which) {
						if(mInfo.getStatus() == Fs_UpdateInfo.UPDATEAPK_FORCE)
						{
								Fs_Application.asynExit();
						}						
					}
				});

		tDialog.show();
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
	                
	                Fs_Application.asynExit();	                
	            }
	        });
	        builder.setNegativeButton(R.string.Cancel, new DialogInterface.OnClickListener() {
	            
	            @Override
	            public void onClick(DialogInterface dialog, int which) {	            	
	                dialog.cancel();		                
	                
	                Fs_Application.asynExit();
	            }
	        });
	        builder.create();
	        builder.show();
	    }	    
	
	//判断是否强制更新
	public boolean getForceUpdateStatus(){
			
		return ( mForceTimeMillis < System.currentTimeMillis());					
	}

	public boolean isDownlock() {
		return mDownlock;
	}

	public void setDownlock(boolean downlock) {
		mDownlock = downlock;
	}
	

}
