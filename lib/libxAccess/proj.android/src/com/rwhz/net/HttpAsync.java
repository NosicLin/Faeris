package com.rwhz.net;

import java.util.ArrayList;
import java.util.List;

import org.apache.http.NameValuePair;
import org.apache.http.entity.AbstractHttpEntity;
import org.apache.http.message.BasicNameValuePair;

/**
 * http协议处理类，供应用直接使用�?
 * 思路：启动后台线程进行http请求，请求完成后回调HttpCallback的函数�?
 * 使用方法�? * 	HttpAsync httpAsync = new HttpAsync();
 * 	httpAsync.setUrl("http://www.baidu.com");
 * 	httpAsync.setHttpCallback(new HttpCallback(){
 *		public void onSuccess(HttpResponse response)
 *		{//...请求成功后的处理
 * 		}
 * 		public void onFail(int errorCode, String errorMessage)
 * 		{//...请求失败后的处理
 * 		}
 * 	});
 * 	//...设置表单项目和头项目
 * 	httpAsync.post();
 * 
 *@author Delo
 * 
 */
public class HttpAsync {
	private String url = null;
	private List<NameValuePair> headerItems = new ArrayList<NameValuePair>();
	private AbstractHttpEntity entity = null;
	private HttpCallback httpCallback = null;
	private String method = "GET";
	private HttpThread httpThread = null;
	private int timeOut=5000;
	private String proxyHost=null;
	private int proxyPort=0;

	public AbstractHttpEntity getEntity() {
		return entity;
	}

	public void setEntity(AbstractHttpEntity entity) {
		this.entity = entity;
	}

	public HttpThread getHttpThread() {
		return httpThread;
	}

	public void setHttpThread(HttpThread httpThread) {
		this.httpThread = httpThread;
	}

	public HttpAsync() {

	}

	public List<NameValuePair> getHeaderItems() {
		return headerItems;
	}

	public String getMethod() {
		return method;
	}

	public void setMethod(String method) {
		this.method = method;
	}

	public HttpCallback getHttpCallback() {
		return httpCallback;
	}

	public void setHttpCallback(HttpCallback httpCallback) {
		this.httpCallback = httpCallback;
	}

	public String getUrl() {
		return url;
	}

	public void setUrl(String url) {
		this.url = url;
	}

	/**
	 * 清空header
	 */
	public void clearHeaderItems() {
		headerItems.clear();
	}

	/**
	 * 添加�?��header条目
	 * 
	 * @param key
	 * @param value
	 */
	public void addHeaderItem(String key, String value) {
		headerItems.add(new BasicNameValuePair(key, value));
	}

	/**
	 * 执行http的post命令，执行完成后调用httpHandler
	 */
	public void post() {
		setMethod("POST");
		httpThread = new HttpThread(this);
		httpThread.start();
	}

	/**
	 * 执行http的get命令
	 */
	public void get() {
		setMethod("GET");
		httpThread = new HttpThread(this);
		httpThread.start();
	}

	/**
	 * 等待后台线程结束以便安全�?��
	 */
	public void stop() {
		while (getHttpThread().isAlive()) {
			try {
				Thread.sleep(1);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

	public int getTimeOut() {
		return timeOut;
	}

	public void setTimeOut(int timeOut) {
		this.timeOut = timeOut;
	}

	public String getProxyHost() {
		return proxyHost;
	}

	public void setProxyHost(String proxyHost) {
		this.proxyHost = proxyHost;
	}

	public int getProxyPort() {
		return proxyPort;
	}

	public void setProxyPort(int proxyPort) {
		this.proxyPort = proxyPort;
	}
}
