package com.faeris.lib;

import android.os.Handler;
import android.os.Message;
import java.lang.ref.WeakReference;


public class Fs_UiEvent extends Handler {
	public final static int UIEVENT_EXIT=1;
	
	private WeakReference<Fs_Activity> m_activity;

	public Fs_UiEvent()
	{
		
	} 

	public void handleMessage(Message msg)
	{
		switch(msg.what)
		{
			case Fs_UiEvent.UIEVENT_EXIT:
				exit(msg);
				break;
		}
	}
	
	public void exit(Message msg)
	{
		Fs_Application.exit();
	}

}
