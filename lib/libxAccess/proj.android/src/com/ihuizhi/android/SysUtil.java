
package com.ihuizhi.android;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Locale;

import android.content.Context;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.content.res.AssetManager;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.Uri;
import android.telephony.TelephonyManager;

public class SysUtil {	
	
	public static String getVersionName(Context context) {
		String version = "rwhz";
		
		try {
			PackageInfo info = context.getPackageManager().getPackageInfo(
					context.getPackageName(), PackageManager.GET_ACTIVITIES);
			if (info != null) {
				version = "" + info.versionName;
				// Log.i("version", version);

				System.out.println(version);

			}
		} catch (Exception e) {
		}
		return version;
	}

	public static String getLanguage() {
		return Locale.getDefault().getLanguage();
	}
	
	public static String getPackageName(Context context)
	{		
		String packageName = "rwhz";
		
		try {
			PackageInfo info = context.getPackageManager().getPackageInfo(
					context.getPackageName(), PackageManager.GET_ACTIVITIES);
			if (info != null) {
				packageName = "" + info.packageName;
				// Log.i("version", version);
			}
		} catch (Exception e) {
		}
		
		return packageName;				
	}
	
	public static boolean isCheckSimCardState(Context context)
	{		
		return  (((TelephonyManager)context.getSystemService(Context.TELEPHONY_SERVICE)).getSimState() == TelephonyManager.SIM_STATE_READY); 
	}

	public static int getVersionCode(Context context) {
		int versionCode = 0;
		try {
			// 获取软件版本号，
			versionCode = context.getPackageManager().getPackageInfo(
					context.getPackageName(), 0).versionCode;
		} catch (NameNotFoundException e) {
			e.printStackTrace();
		}
		return versionCode;
	}


	public static void saveConfig(String filename, byte[] data, String mod) {
		saveAppFile(filename, data, "");
	}

	public static byte[] loadConfig(String filename) {
		return loadAppFile(filename);
	}

	public static byte[] GetResourceData(String filename) {
		return loadAppFile(filename);
	}

	public static byte[] GetFileData(String filename) {
		return loadAppFile(filename);
	}

	public static void WriteData2File(String filename, byte[] data, String md)
			throws IOException {
		saveAppFile(filename, data, md);
	}

	public synchronized static byte[] loadAppFile(String filename) {
		return FileUtils.read(filename);
	}

	public void WriteData2File(String fileName, String data, String md) {
		saveAppFile(fileName, data.getBytes(), md);
	}

	public synchronized static void saveAppFile(String filename, byte[] data,
			String md) {
		FileUtils.write(filename, data, md);
	}

	public static boolean fileExists(String filename) {
		return FileUtils.fileExists(filename);
	}

	public static void browserInterface(Context context,String url) {
		Intent it = new Intent(Intent.ACTION_VIEW, Uri.parse(url));
		context.startActivity(it);
	}

	public static String getAppStringMeta(Context context, String name) {

		ApplicationInfo appInfo;
		String  value = "";
		try {
			appInfo = context.getPackageManager().getApplicationInfo(
					context.getPackageName(), PackageManager.GET_META_DATA);

			value = appInfo.metaData.getString(name);

		} catch (NameNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return value;
	}
	
	public static int getAppInterMeta(Context context, String name) {

		ApplicationInfo appInfo;
		int value = 0;
		try {
			appInfo = context.getPackageManager().getApplicationInfo(
					context.getPackageName(), PackageManager.GET_META_DATA);

			value = appInfo.metaData.getInt(name);

		} catch (NameNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return value;
	}

	public static boolean TTFExists(Context context) {
		try {
			String saveFile = "data/data/" + context.getPackageName() + "/TTF/";
			File destDir = new File(saveFile);
			if (!destDir.exists())
				destDir.mkdirs();
			String ttfFile = "data/data/" + context.getPackageName()
					+ "/TTF/hkwwt.ttf";
			FileOutputStream fos = new FileOutputStream(ttfFile);
			AssetManager am = context.getAssets();
			for (int i = 1; i <= 6; i++) {
				String partFile = "hkwwt.ttf.pat" + i;
				InputStream fis = am.open(partFile);
				final int bufLen = 4 * 1024;
				byte[] buf = new byte[bufLen];
				int start = 0;
				int readLen = fis.read(buf, start, bufLen);
				while (readLen > 0) {
					fos.write(buf, 0, readLen);
					start += readLen;
					readLen = fis.read(buf, 0, bufLen);
				}
				fis.close();
			}
			fos.close();
			return true;
		} catch (IOException e1) {
			e1.printStackTrace();
			return false;
		}
	}

	public static void SysOpen(Context context, String FilePath) {
		chmod("777", FilePath);
		
		Intent intent = new Intent(Intent.ACTION_VIEW);
		intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
		intent.setDataAndType(Uri.fromFile(new File(FilePath)),
				"application/vnd.android.package-archive");
		
		context.startActivity(intent);
	}

	public static void chmod(String permission, String path) {
		try {
			String command = "chmod " + permission + " " + path;
			Runtime runtime = Runtime.getRuntime();
			runtime.exec(command);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static byte[] GetExteralPath() {
		if (android.os.Environment.getExternalStorageState().equals(
				android.os.Environment.MEDIA_MOUNTED)) {
			String SdCardPath = android.os.Environment
					.getExternalStorageDirectory().toString();
			return SdCardPath.getBytes();
		}
		return null;
	}

	public static boolean isNetworkAvailable(Context context) {
		ConnectivityManager connectivity = (ConnectivityManager) context
				.getSystemService(Context.CONNECTIVITY_SERVICE);
		if (connectivity != null) {
			NetworkInfo info = connectivity.getActiveNetworkInfo();
			if (info != null && info.isAvailable()) {
				return true;
			}
		}
		return false;
	}
	
}
