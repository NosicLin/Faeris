package com.ihuizhi.net;

import java.io.IOException;
import java.util.Iterator;

import org.apache.http.HttpHost;
import org.apache.http.HttpResponse;
import org.apache.http.HttpStatus;
import org.apache.http.NameValuePair;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.conn.params.ConnRoutePNames;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.params.BasicHttpParams;
import org.apache.http.params.HttpConnectionParams;

import com.ihuizhi.res.Constant;

import android.util.Log;


/**
 * http请求的处理线程�?
 * 
 * @author Bingle
 * 
 */
public class HttpThread extends Thread {
	private HttpAsync httpAsync = null;

	public HttpThread(HttpAsync httpAsync) {
		this.httpAsync = httpAsync;
	}

	@Override
	public void run() {
		Log.d("testHTTP", "HttpThread.run.start");
		if (httpAsync.getHttpCallback() == null) {
			httpAsync.setHttpCallback(new HttpCallback() {
				@Override
				public void onSuccess(HttpResponse response) {
				}

				@Override
				public void onFail(int errorCode, String errorMessage) {
				}
			});
		}
		BasicHttpParams httpParameters = new BasicHttpParams();
		HttpConnectionParams.setConnectionTimeout(httpParameters,
				httpAsync.getTimeOut());
		HttpConnectionParams.setSoTimeout(httpParameters,
				httpAsync.getTimeOut());
		HttpClient httpClient = new DefaultHttpClient(httpParameters);
		if (httpAsync.getProxyHost() != null) {
			HttpHost proxy = new HttpHost(httpAsync.getProxyHost(),
					httpAsync.getProxyPort());
			httpClient.getParams().setParameter(ConnRoutePNames.DEFAULT_PROXY,
					proxy);
		}
		HttpResponse response = null;
		try {
			if ("POST".equals(httpAsync.getMethod())) {
				HttpPost httpPost = new HttpPost(httpAsync.getUrl());
				Log.i("TestCase", "URL=" + httpAsync.getUrl());
				httpPost.setEntity(httpAsync.getEntity());

				Iterator<NameValuePair> headerIt = httpAsync.getHeaderItems()
						.iterator();
				while (headerIt.hasNext()) {
					NameValuePair headerItem = headerIt.next();
					httpPost.setHeader(headerItem.getName(),
							headerItem.getValue());
				}
				response = httpClient.execute(httpPost);
			} else {
				String url = httpAsync.getUrl();
				HttpGet httpGet = new HttpGet(url);
				Iterator<NameValuePair> headerIt = httpAsync.getHeaderItems()
						.iterator();
				while (headerIt.hasNext()) {
					NameValuePair headerItem = headerIt.next();
					httpGet.setHeader(headerItem.getName(),
							headerItem.getValue());
				}
				response = httpClient.execute(httpGet);
			}

		} catch (ClientProtocolException e) {
			e.printStackTrace();
			httpAsync.getHttpCallback().onFail(
					Constant.HTTP_ClientProtocolException, e.getMessage());
		} catch (IOException e) {
			e.printStackTrace();
			httpAsync.getHttpCallback().onFail(Constant.HTTP_IOException,
					e.getMessage());
		} finally {
			

			if (response == null ) {
				httpAsync.getHttpCallback().onFail(
						Constant.HTTP_GeneralException,
						Constant.HTTP_GeneralExceptionMessage);
				Log.d("testHTTP", "HTTP FAIL!");
			} else {
				
		        int status =  response.getStatusLine().getStatusCode();  
		        
		        if( status != HttpStatus.SC_OK)
					httpAsync.getHttpCallback().onFail(
							Constant.HTTP_GeneralException,
							Constant.HTTP_GeneralExceptionMessage);
		        	
				Log.d("testHTTP", "HTTP OK!");
				httpAsync.getHttpCallback().onSuccess(response);
			}
		}

		Log.d("testHTTP", "HttpThread.run.end");
	}
}
