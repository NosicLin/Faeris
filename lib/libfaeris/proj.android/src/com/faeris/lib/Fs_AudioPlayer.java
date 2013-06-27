package com.faeris.lib;




import android.content.Context;
import android.media.AudioManager;
import android.media.SoundPool;
import android.util.Log;

public class Fs_AudioPlayer 
{
	/* class scope attribute */
	private static final int ERR_SOUND_ID=-1;
	private static final int ERR_CHANNEL_ID=-1;
	private static final String TAG="FsAudioPlayer";


	/* instance scope attribute */
	private final Context m_context;
	private SoundPool m_soundPool;
	private float  m_volume;


	/* public method */
	public Fs_AudioPlayer(int channel_nu)
	{
		this.m_context=Fs_Application.getContext();
		this.init(channel_nu);
	}
	
	protected void init(int channel_nu)
	{
		this.m_soundPool=new SoundPool(channel_nu,AudioManager.STREAM_MUSIC,0);
		this.m_volume=1.0f;
	}


	/* create and release sound */
	public int createSound(final String path)
	{
		int id=Fs_AudioPlayer.ERR_SOUND_ID;
		try
		{
			if(path.startsWith("/"))
			{
				id=this.m_soundPool.load(path,0);
			}
			else 
			{
				id=this.m_soundPool.load(this.m_context.getAssets().openFd(path),0);
			}
		}
		catch(final Exception e)
		{
			id=Fs_AudioPlayer.ERR_SOUND_ID;
			Log.v(Fs_AudioPlayer.TAG,"error:"+e.getMessage(),e);
		}
		if(id==0)
		{
			id=Fs_AudioPlayer.ERR_SOUND_ID;
		}
		return id;

	}
	public void releaseSound(int sound)
	{
		this.m_soundPool.unload(sound);
	}

	/* play sound */
	public int playSound(int sound,int loop,int priority)
	{
		int channel=Fs_AudioPlayer.ERR_CHANNEL_ID;
		channel=m_soundPool.play(sound,this.m_volume,this.m_volume,priority,loop==-1?-1:0, 1.0f);
		return channel;

	}

	/* single channel */
	public void pauseChannel(int channel)
	{
		this.m_soundPool.pause(channel);
	}
	
	public void resumeChannel(int channel)
	{
		this.m_soundPool.resume(channel);
	}
	
	public void stopChannel(int channel)
	{
		this.m_soundPool.stop(channel);
	}
	
	public void setChannelVolume(int channel,float value)
	{
		this.m_soundPool.setVolume(channel,value*this.m_volume,value*this.m_volume);
	}
	
	public float getChannelVolume(int channel)
	{
		Log.v(Fs_AudioPlayer.TAG,"StopChannels Not Impliment");
		return this.m_volume;
	}


	/* all channel */
	public void pauseChannels() 
	{
		this.m_soundPool.autoPause();
	}
	public void resumeChannels()
	{
		this.m_soundPool.autoResume();
	}
	public void stopChannels()
	{
		Log.v(Fs_AudioPlayer.TAG,"StopChannels Not Impliment");
	}	
	public void setVolume(float value) 
	{
		Log.v(Fs_AudioPlayer.TAG,"SetVolume Not Impliment");
		this.m_volume=value;
	}


}
