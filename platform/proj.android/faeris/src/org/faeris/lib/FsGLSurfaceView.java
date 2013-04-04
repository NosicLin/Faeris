package org.faeris.lib;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.view.KeyEvent;
import android.view.MotionEvent;



public class FsGLSurfaceView  extends GLSurfaceView 
{
	private FsGLRender m_render;
	
	public  FsGLSurfaceView(final Context context)
	{
		super(context);
		//this.init();
	}
	
	public void setFsGLRender(FsGLRender r) 
	{
		this.m_render=r;
		this.setRenderer(this.m_render);
	}


	@Override 
	public void onResume()
	{
		super.onResume();
		this.queueEvent(new Runnable() {
			@Override 
			public void run(){
				FsEngine.onForeground();
			}
		});
	}

	@Override
	public void onPause() 
	{
		super.onPause();
		this.queueEvent(new Runnable(){
			@Override
			public void run(){
				FsEngine.onBackground();
			}
		});
	}


	@Override 
	public boolean onTouchEvent(final MotionEvent event)
	{
		int pointer_nu=event.getPointerCount();
		int[] ids=new int[pointer_nu];
		float[] xs=new float[pointer_nu];
		float[] xy=new float[pointer_nu];

		for( int i=0;i<pointer_nu;i++)
		{
			ids[i]=event.getPointerId(i);
			xs[i]=event.getX(i);
			xy[i]=event.getY(i);
		}
		return true;
	}
	@Override
	protected void onSizeChanged(final int new_width,final int new_height, final int old_width,final int old_height)
	{
		this.queueEvent(new Runnable(){
			@Override
			public void run(){
				FsEngine.onResize(new_width,new_height);
			}
		});
	}

	@Override
	public boolean onKeyDown(final int keycode,final KeyEvent event)
	{
		switch(keycode)
		{
			case KeyEvent.KEYCODE_BACK:
				return true;
			default:
				return  super.onKeyDown(keycode,event);
		}

	}




}

















