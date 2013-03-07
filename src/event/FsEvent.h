#ifndef _FAERIS_EVENT_H_
#define _FAERIS_EVENT_H_

#include "FsMacros.h"
NS_FS_BEGIN
class Event 
{
	public:
		enum
		{
			MOUSE_EVENT=0,
			TOUCH_EVENT,
			KEY_EVENT,
			FOCUS_EVENT,
			RESIZE_EVENT,
			MOTION_EVENT,
			QUIT_EVENT,

		};

	public:
		Event(int _type)
			:type(_type)
		{ }

	public:
		int type;
};
class FocusEvent:public Event 
{
	public:
		FocusEvent(bool _focus)
			:Event(FOCUS_EVENT)
		{
			focus=_focus;
		}
	public:
		bool focus;
};
class QuitEvent:public Event 
{
	public:
		QuitEvent()
			:Event(QUIT_EVENT)
		{}
};

class MouseEvent:public Event 
{
	public:
		MouseEvent(int _button,int _state,uint _mask,int _x,int _y)
			:Event(MOUSE_EVENT)
		{
			button=_button;
			state=_state;
			x=_x;
			y=_y;
			mask=_mask;
		}

	public:
		int button;
		int state;
		uint mask;
		int x;
		int y;

		/* used  for mouse move */
		int dx;
		int dy;
};
class MotionEvent:public Event 
{
	public:
		MotionEvent(uint _mask,int _x,int _y,int _dx,int _dy)
			:Event(MOTION_EVENT)
		{
			mask=_mask;
			x=_x;
			y=_y;
			dx=_dx;
			dy=_dy;
		}
	public:
		uint mask;
		int x,y,dx,dy;
};
class ResizeEvent:public Event
{
	public:
		ResizeEvent(int _width,int _height)
			:Event(RESIZE_EVENT)
		{
			width=_width;
			height=_height;
		}
	public:
		int width;
		int height;
};

class KeyEvent:public Event 
{
	public:
		KeyEvent(int _keycode,int _state,uint _mask)
			:Event(KEY_EVENT)
		{
			keycode=_keycode;
			state=_state;
			mask=_mask;
		}
	public:
		int keycode;
		int state;
		uint mask;
};

class TouchEvent:public Event 
{
	public:
		TouchEvent(int _x,int _y)
			:Event(TOUCH_EVENT)
		{
			x=_x;
			y=_y;
		}

	public:
		int x;
		int y;

};
NS_FS_END
#endif /*_FAERIS_EVENT_H_*/

