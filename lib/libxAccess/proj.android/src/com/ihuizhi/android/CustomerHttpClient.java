package com.ihuizhi.android;


import java.lang.reflect.Method;

import com.ihuizhi.vo.PhoneInfoVo;

import android.content.Context;
import android.telephony.TelephonyManager;


public class CustomerHttpClient {
	
	
	
	 public static PhoneInfoVo getPhoneInfoVo(Context context) {
		 PhoneInfoVo phoneInfoVo = new PhoneInfoVo();
		 String imsi = "";
		 String imei ="";
		 String phoneModel = "";
		 String line1Number = "";
		 String simSerialNumber = "";
		 TelephonyManager telMgr = null;
		try {    //普通方法获取imsi
			telMgr = (TelephonyManager) context.
					getSystemService(Context.TELEPHONY_SERVICE);
			imsi = telMgr.getSubscriberId();
			imei = telMgr.getDeviceId();
			line1Number =telMgr.getLine1Number();
			simSerialNumber = telMgr.getSimSerialNumber();
			phoneModel = android.os.Build.MODEL;
			if (imsi==null || "".equals(imsi)) imsi = telMgr.getSimOperator();
			Class<?>[] resources = new Class<?>[] {int.class};
			Integer resourcesId = new Integer(1);
			if (null == imsi || "".equals(imsi)) {
				try {   //利用反射获取    MTK手机
					Method addMethod = telMgr.getClass().getDeclaredMethod("getSubscriberIdGemini", resources);
					addMethod.setAccessible(true);
					imsi = (String) addMethod.invoke(telMgr, resourcesId);
				} catch (Exception e) {
					imsi = null;
				}
			}
			if (imsi==null || "".equals(imsi)) {
				try {  //利用反射获取    展讯手机
					Class<?> c = Class
							.forName("com.android.internal.telephony.PhoneFactory");
					Method m = c.getMethod("getServiceName", String.class, int.class);
					String spreadTmService = (String) m.invoke(c, Context.TELEPHONY_SERVICE, 1);
					TelephonyManager tm1 = (TelephonyManager) context.getSystemService(spreadTmService);
					imsi = tm1.getSubscriberId();
				} catch (Exception e) {
					imsi = null;
				}
			}
			if (imsi==null || "".equals(imsi)) {
				try {    //利用反射获取    高通手机
					Method addMethod2 = telMgr.getClass().getDeclaredMethod("getSimSerialNumber", resources);
					addMethod2.setAccessible(true);
					imsi = (String) addMethod2.invoke(telMgr, resourcesId);
				} catch (Exception e) {
					imsi = null;
				}
			}
			if (imsi==null || "".equals(imsi)) {
				imsi = "000000";
			}
		} catch (Exception e) {
			imsi =  "000000";
		}
		phoneInfoVo.setImsi(imsi);
		phoneInfoVo.setImei(imei);
		phoneInfoVo.setPhoneModel(phoneModel);
		phoneInfoVo.setLine1Number(line1Number);
		phoneInfoVo.setSimSerialNumber(simSerialNumber);
		return phoneInfoVo;
		
	}
}
