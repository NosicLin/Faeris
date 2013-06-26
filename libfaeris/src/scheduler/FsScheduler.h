#ifndef _FS_SCHEDULER_H_
#define _FS_SCHEDULER_H_

#include "FsMacros.h"
#include "core/FsObject.h"
#include "util/FsSlowArray.h"
#include "sys/FsTimer.h"

NS_FS_BEGIN
class SchedulerTarget;
class Scheduler :public FsObject
{
	public:
		enum
		{
			HIGHEST=0,
			HIGH,
			MIDDLE,
			LOW,
			LOWEST,
			PRIORITY_NU,
		};

	public:
		static Scheduler* create();

	public:
		/* inherit FsObject */
		const char* className() ;

	public:
		void start();
		void stop();
		void setFps(int fps);
		void mainLoop();
		float update(float dt);
		bool isRunning()
		{
			return !m_stop;
		}

	public:
		void add(SchedulerTarget* s,int priority);
		void remove(SchedulerTarget* s,int priority);
		void remove(SchedulerTarget* s);
		bool hasTarget(SchedulerTarget* target,int priority);
		bool hasTarget(SchedulerTarget* target);

	protected:
		Scheduler();
		~Scheduler();
		void init();
		void destroy();

	private:
		/* scheduler target */
		FsSlowArray* m_target[PRIORITY_NU];
		bool m_stop;
		int m_fps;

		Timer m_timer;

};

NS_FS_END


#endif /*_FS_SCHEDULER_H_*/























