package org.faeris.lib;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.util.Log;



public class FsGLSurfaceView  extends GLSurfaceView 
{
	private FsGLRender m_render;
	private float m_width;
	private float m_height;
	
	public  FsGLSurfaceView(final Context context)
	{
		super(context);
		setEGLContextClientVersion(2);
	}
	
	public void setFsGLRender(FsGLRender r) 
	{

		this.m_render=r;
		this.setRenderer(this.m_render);
		setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY);

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
		//super.onPause();
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
	//	Log.v("key","onKeyBack,pointer_nu"+pointer_nu);
		int[] ids=new int[pointer_nu];
		float[] sx=new float[pointer_nu];
		float[] sy=new float[pointer_nu];

		for( int i=0;i<pointer_nu;i++)
		{
			ids[i]=event.getPointerId(i);
			sx[i]=event.getX(i);
			sy[i]=event.getY(i);

		}
		for(int i=0;i<pointer_nu;i++)
		{
			sx[i]=sx[i]/m_width;
			sy[i]=1-sy[i]/m_height;
		//	Log.v("key","x:"+sx[i]+" y:"+sy[i]);
			
		}
		if(pointer_nu==1)
		{
			final float x0=sx[0];
			final float y0=sy[0];
			switch(event.getAction())
			{
				case MotionEvent.ACTION_DOWN:
					this.queueEvent(new Runnable(){
						@Override
						public void run()
						{
							FsEngine.onTouchBegin(x0,y0);
						}
					});

					break;
				case MotionEvent.ACTION_MOVE:
					this.queueEvent(new Runnable(){
						@Override
						public void run()
						{
							FsEngine.onTouchMove(x0,y0);
						}
					});
					break;
				case MotionEvent.ACTION_UP:
					this.queueEvent(new Runnable(){
						@Override
						public void run()
						{
							FsEngine.onTouchEnd(x0,y0);
						}
					});
					break;
				case MotionEvent.ACTION_CANCEL:
					this.queueEvent(new Runnable(){
						@Override
						public void run()
						{
							FsEngine.onTouchCancel(x0,y0);
						}
					});
					break;

			}
		}
		return true;
	}
	@Override
	protected void onSizeChanged(final int new_width,final int new_height, final int old_width,final int old_height)
	{
		m_width=new_width;
		m_height=new_height;
		this.queueEvent(new Runnable(){
			@Override
			public void run(){
				FsEngine.onResize(new_width,new_height);
			}
		});
	}

	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
	    	// exit program when key back is entered
			Log.v("key","onKeyEvent");
	    	if (keyCode == KeyEvent.KEYCODE_BACK) {
	    		android.os.Process.killProcess(android.os.Process.myPid());
	    	}
	        return super.onKeyDown(keyCode, event);
	}




}

















