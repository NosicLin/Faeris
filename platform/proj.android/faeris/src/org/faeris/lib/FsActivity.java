package org.faeris.lib;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.ViewGroup;
import android.widget.FrameLayout;


public abstract class FsActivity extends Activity
{
	/* attibute */
	private FsGLSurfaceView m_view;

	
	/* method */

	@Override 
	protected void onCreate(final Bundle save_state)
	{
		super.onCreate(save_state);
		this.init();
	}
	
	@Override 
	protected void onResume()
	{
		super.onResume();
		this.m_view.onResume();
	}

	@Override
	protected void onPause()
	{
		super.onPause();
		this.m_view.onPause();
	}
	
	
	protected void init()
	{

		FsEngine.moduleInit();
		m_view=new FsGLSurfaceView(this);
		FsGLRender r=new FsGLRender();
		
		m_view.setFsGLRender(r);
		this.setContentView(m_view);


	}
	
	
	protected void exit()
	{
		FsEngine.moduleExit();
	}
}
