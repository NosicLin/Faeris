package org.faeris.lib;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.util.Log;

public class FsGLRender implements GLSurfaceView.Renderer
{
	private boolean m_init=false;
	@Override 
	public void onDrawFrame(final GL10 gl)
	{
		FsEngine.onUpdate(30);
	}
	public void setIsDraw(boolean draw)
	{
	}
	public boolean getIsDraw()
	{
		return true;
	}

	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height)
	{
		FsEngine.onResize(width, height);
		
	} 

	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig config) 
	{
		if(!this.m_init)
		{
			Log.v("key","init:"+this.m_init);
			FsEngine.moduleInit();
			this.m_init=true;
			Log.v("key","init:"+this.m_init);
		}
	}

}
