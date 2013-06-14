#ifndef _FS_KEYPAD_DISPATCHER_H_
#define _FS_KEYPAD_DISPATCHER_H_ 

#include "FsMacros.h"
#include "event/FsTEventDispatcher.h"

NS_FS_BEGIN
class KeypadEvent 
{
	public:
		KeypadEvent(int _keycode)
		{
			keycode=_keycode;
		}
	public:
		int keycode;
};

class KeypadEventListener:public FsObject
{
	public:
		KeypadEventListener* create();

	protected:
		KeypadEventListener();
		virtual ~KeypadEventListener();
	public:
		void handleEvent(KeypadEvent* event)
		{
			onKeypadEvent(event);
		}

	public:
		virtual void onKeypadEvent(KeypadEvent* event);
		
		/* Override FsObject*/
		virtual const char* className();
};



class KeypadDispatcher:public TEventDispatcher<KeypadEvent,KeypadEventListener>
{
	public:
		enum 
		{
			KEYPAD_BACK,
			KEYPAD_MENU,
		};
	public:
		static KeypadDispatcher* create();
		const char* className();

};




NS_FS_END 


#endif /*_FS_KEYPAD_DISPATCHER_H_*/

