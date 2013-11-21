package com.rwhz.net;

import org.apache.http.HttpResponse;

/**
 * 用户http请求处理完成后的回调处理�? * http协议执行post或get之后的处理，onSuccess是成功后的回调处理，onFail是失败后的回调处�? * 
 * @author Bingle
 * 
 */
public interface HttpCallback { 
	public void onSuccess(HttpResponse response);

	public void onFail(int errorCode, String errorMessage);
}
