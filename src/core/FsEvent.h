#ifndef _FAERIS_EVENT_H_
#define _FAERIS_EVENT_H_

#include "FsMacros.h"
FAERIS_NAMESPACE_BEGIN
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
		Event(FsInt _type)
			:type(_type)
		{ }

	public:
		FsInt type;
};
class FocusEvent:public Event 
{
	public:
		FocusEvent(FsBool _focus)
			:Event(FOCUS_EVENT)
		{
			focus=_focus;
		}
	public:
		FsBool focus;
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
		MouseEvent(FsInt _button,FsInt _state,FsUint _mask,FsInt _x,FsInt _y)
			:Event(MOUSE_EVENT)
		{
			button=_button;
			state=_state;
			x=_x;
			y=_y;
			mask=_mask;
		}

	public:
		FsInt button;
		FsInt state;
		FsUint mask;
		FsInt x;
		FsInt y;

		/* used  for mouse move */
		FsInt dx;
		FsInt dy;
};
class MotionEvent:public Event 
{
	public:
		MotionEvent(FsUint _mask,FsInt _x,FsInt _y,FsInt _dx,FsInt _dy)
			:Event(MOTION_EVENT)
		{
			mask=_mask;
			x=_x;
			y=_y;
			dx=_dx;
			dy=_dy;
		}
	public:
		FsUint mask;
		FsInt x,y,dx,dy;
};
class ResizeEvent:public Event
{
	public:
		ResizeEvent(FsInt _width,FsInt _height)
			:Event(RESIZE_EVENT)
		{
			width=_width;
			height=_height;
		}
	public:
		FsInt width;
		FsInt height;
};

class KeyEvent:public Event 
{
	public:
		KeyEvent(FsInt _keycode,FsInt _state,FsUint _mask)
			:Event(KEY_EVENT)
		{
			keycode=_keycode;
			state=_state;
			mask=_mask;
		}
	public:
		FsInt keycode;
		FsInt state;
		FsUint mask;
};

class TouchEvent:public Event 
{
	public:
		TouchEvent(FsInt _x,FsInt _y)
			:Event(TOUCH_EVENT)
		{
			x=_x;
			y=_y;
		}

	public:
		FsInt x;
		FsInt y;

};
FAERIS_NAMESPACE_END
#endif /*_FAERIS_EVENT_H_*/

