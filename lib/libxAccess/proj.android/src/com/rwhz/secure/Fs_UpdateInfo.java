package com.rwhz.secure;

public class Fs_UpdateInfo {
	/*
	 * 请求：
				http://host:port/apk?pn=com.huizhi.runner&ver=1
				响应：
				{
					ret:0,
					msg:'',
					url:http://host:port/apk/runner-1.0.apk,
					isForce:1
					version:12
				}
	 * *
	 */
	private  String  apkUrl; //更新地址
	private int  result; //返回结果
	private int isForce;  // 1强制更新 0 不强制
	private int version; //版本号
	
	private String msg; // 出错信息 ，result 为零

	public String getApkUrl() {
		return apkUrl;
	}

	public void setApkUrl(String apkUrl) {
		this.apkUrl = apkUrl;
	}

	public int getResult() {
		return result;
	}

	public void setResult(int result) {
		this.result = result;
	}

	public int getIsForce() {
		return isForce;
	}

	public void setIsForce(int isForce) {
		this.isForce = isForce;
	}

	public int getVersion() {
		return version;
	}

	public void setVersion(int version) {
		this.version = version;
	}

	public String getMsg() {
		return msg;
	}

	public void setMsg(String msg) {
		this.msg = msg;
	}
	

}
