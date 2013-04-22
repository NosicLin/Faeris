package org.faeris.game;
import org.faeris.lib.FsActivity;

import android.os.Bundle;
import android.view.WindowManager;
public class LuaActivity  extends FsActivity
{
	@Override 
	public void onCreate(final Bundle save_state)
	{
		super.onCreate(save_state);
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON, WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

	}
	
	static {
        System.loadLibrary("faeris");
    }

}
