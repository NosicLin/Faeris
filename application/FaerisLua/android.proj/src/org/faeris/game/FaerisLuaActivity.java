package org.faeris.game;

import org.faeris.lib.*;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.ViewGroup;
import android.widget.FrameLayout;


public class FaerisLuaActivity extends FsActivity  
{
	@Override 
	public void onCreate(final Bundle save_state)
	{
		super.onCreate(save_state);
		setContentView(R.layout.test_ui);
	}

}
