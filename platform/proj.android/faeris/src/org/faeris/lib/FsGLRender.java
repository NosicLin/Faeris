package org.faeris.lib;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView;
public class FsGLRender implements GLSurfaceView.Renderer
{
	private boolean m_init=false;
	@Override 
	public void onDrawFrame(final GL10 gl)
	{
		FsEngine.onUpdate(30);
	}

	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height)
	{
		FsEngine.onResize(width, height);
		
	} 

	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig config) 
	{
		if(!m_init)
		{
			FsEngine.moduleInit();
			m_init=true;
		}
	}

}
