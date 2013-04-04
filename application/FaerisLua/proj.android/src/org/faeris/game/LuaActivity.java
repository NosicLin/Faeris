package org.faeris.game;
import org.faeris.lib.FsActivity;

import android.os.Bundle;
public class LuaActivity  extends FsActivity
{
	@Override 
	public void onCreate(final Bundle save_state)
	{
		super.onCreate(save_state);
	}
	
	static {
        System.loadLibrary("faeris");
    }

}
