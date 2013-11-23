package com.ihuizhi.android;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import android.content.Context;
import android.util.Log;


public class FileUtils
{
	public final static String TAG = "Delo";
	public static Context mContent = null;
	
	public final static boolean deleteFile(String fileName)
	{
		boolean ret = false;
		
		if (pathSplitExists(fileName))
		{
			File fp = new File(fileName);
			if (fp.exists())
			{
				ret = fp.delete();
			}
		}
		else
		{			
			ret = mContent.deleteFile(fileName);
		}
		return ret;
	}
	
	public final static void init(Context context)
	{
		mContent = context;
	}	
	
	public final static boolean fileExists(String fileName)
	{
		boolean ret = false;
		InputStream is = null;
		try
		{
			is = getInputStream(fileName);
			if (is != null)
			{
				ret = true;
			}
		}
		catch(Exception e)
		{
			
		}
		finally
		{
			if (is != null)
			{
				try
				{
					is.close();
				}
				catch(IOException e)
				{
					Log.i(TAG, e.getMessage());
				}
			}			
		}
				
		return ret;
	}
	
	public final static byte[] read(String fileName)
	{
		byte[] data = null;
		InputStream is = null;
		try
		{
			is = getInputStream(fileName);
			if (is != null) {
				int len = is.available();
				data = new byte[len];
				is.read(data);
			}
		}
		catch(Exception e)
		{
			
		}
		finally
		{
			if (is != null)
			{
				try
				{
					is.close();
				}
				catch(IOException e)
				{
					Log.i(TAG, e.getMessage());
				}
			}			
		}
		
		return data;
	}
	
	private final static boolean isAppend(String mode)
	{
		boolean append = false;
		if (mode != null && mode.indexOf('a') != -1)
		{
			append = true;
		}
		return append;
	}
	public final static boolean write(String fileName, byte[] data, String mode)
	{
		boolean ret = false;
		OutputStream os = null;
		try
		{
			os = getOutputStream(fileName, mode);
			os.write(data);
			ret = true;
		}
		catch(Exception e)
		{
			
		}
		finally
		{
			if (os != null)
			{
				try
				{
					os.close();
				}
				catch(IOException e)
				{
					Log.i(TAG, e.getMessage());
				}
			}			
		}
		return ret;
	}
	
	public final static int getFileLength(String fileName)
	{
		int ret = -1;
		InputStream is = null;
		try
		{
			is = getInputStream(fileName);
			ret = is.available();
		}
		catch(Exception e)
		{
			
		}
		finally
		{
			if (is != null)
			{
				try
				{
					is.close();
				}
				catch(IOException e)
				{
					Log.i(TAG, e.getMessage());
				}
			}			
		}
		
		return ret;
	}
	
	public final static boolean makeDir(String filePath)
	{
		boolean ret = false;
		File file = new File (filePath);
		if (!file.exists())
		{
			ret = file.mkdirs();
		}		
		return ret;
	}
	
	public final static boolean rename(String oldName, String newName)
	{
		boolean ret = false;
		try
		{
			if (pathSplitExists(oldName))
			{
				File oldFile = new File(oldName);
				File newFile = new File(newName);
				ret = oldFile.renameTo(newFile);
			}
		}
		catch(Exception e)
		{
			
		}
		return ret;
	}	
	
	private final static boolean pathSplitExists(String fileName)
	{
		boolean ret = false;
		if (fileName != null)
		{
			ret = fileName.indexOf("\\") >= 0 || fileName.indexOf("/") >= 0;
		}
		return ret;
	}
	
//	private static String getFileOutputDir(Context context) {
//		File file = context.getFilesDir();
//		if (file != null)
//			return file.getAbsolutePath();
//		
//		return null;
//	}
//	
//	private static String getResourcesPath(Context context) {
//		return (context).getPackageResourcePath();
//	}
//	
	private final static OutputStream getOutputStream(String fileName, String mode)
	{
		OutputStream is = null;
		try
		{
			boolean append = isAppend(mode);
			if (pathSplitExists(fileName))
			{
				File fp = new File(fileName);
				is = new FileOutputStream(fp, append);
			}
			else
			{
				int openMode = append ? Context.MODE_APPEND : Context.MODE_PRIVATE;
				is = mContent.openFileOutput(fileName, openMode);
			}
		}
		catch(Exception e)
		{
		}			
		return is;
	}
	private final static InputStream getInputStream(String fileName)
	{
		InputStream is = null;
		try
		{
			if (pathSplitExists(fileName))
			{
				File fp = new File(fileName);
				is = new FileInputStream(fp);
			}
			else
			{
				try
				{
					is = mContent.openFileInput(fileName);
				}
				catch(Exception e)
				{
					
				}
				if (is == null)
				{
					is = mContent.getAssets().open(fileName);
				}
			}
		}
		catch(Exception e)
		{
		}			
		return is;
		
	}
}
