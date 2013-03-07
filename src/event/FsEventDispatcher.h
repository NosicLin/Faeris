#ifndef _FS_EVENT_DISPATCH_H_
#define _FS_EVENT_DISPATCH_H_ 
#include <vector>
#include "FsMacros.h"
#include "sys/FsEvent.h"
#include "sys/FsEventListener.h"
NS_FS_BEGIN
class EventDispatcher 
{
	public:
		static EventDispatcher* shareEventDispatcher();
		static void  purgeShareEventDispatcher();
	public:
		void dispatchEvent(Event* e);
		void addEventListener(EventListener* l);
		void removeEventListener(EventListener* l);
		void dropAllEventListener();
	private:
		/*FIXME(use list instead of vector)*/
		typedef std::vector<EventListener*>::iterator Iterator;
		std::vector<EventListener*> m_listeners;
};


NS_FS_END
#endif /*_FS_EVENT_DISPATCH_H_*/

