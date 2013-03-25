#ifndef _FS_SYS_DISPATCHER_H_
#define _FS_SYS_DISPATCHER_H_

#include <vector>

#include "FsMacros.h"
#include "scheduler/FsSchedulerTarget.h"

NS_FS_BEGIN

class SysEventListener;
class FsSlowArray;
class SysDispatcher: public SchedulerTarget
{
	public:

	public:
		enum 
		{
			FOREGROUND,
			BACKGROUND,
			QUIT,
			EXIT,
		};

		class SysEvent 
		{
			public:
				SysEvent(int type)
				{
					m_type=type;
				}
			public:
				int m_type;
		};

		typedef std::vector<SysEvent*> EventQueue;

	public:
		void dispatchSysEvent(int type);
		void addEventListener(SysEventListener* l);
		void removeEventListener(SysEventListener* l);
		void clearPending();

	public:
		/* inherit SchedulerTarget*/
		virtual void update(int priority,float dt);

		/* inherit FsObject */
		virtual const char* className();

	public:
		static SysDispatcher* create();

	protected:
		SysDispatcher();
		virtual ~SysDispatcher();
		void init();
		void destroy();
		void swapEventQueue();
		void clearEvent(EventQueue* queue);

	private:
		EventQueue* m_eventPending;
		EventQueue* m_eventHandling;
		FsSlowArray* m_listenerArray;
};
NS_FS_END 

#endif /*_FS_SYS_DISPATCHER_H_*/


