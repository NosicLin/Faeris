#ifndef _FS_SCHEDULER_H_
#define _FS_SCHEDULER_H_

#include "FsMacros.h"
#include "core/FsObject.h"
#include "util/FsSlowArray.h"

NS_FS_BEGIN
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
		const char* className()const ;

	public:
		void start();
		void stop();
		void setFps(int fps);
		void mainLoop();

	public:
		void add(SchedulerTarget* s,int priority);
		void remove(SchedulerTarget* s,int priority);

	protected:
		Scheduler();
		~Scheduler();
		void init();
		void destroy();
		void update(float dt);

	private:
		/* scheduler target */
		FsSlowArray* m_target[PRIORITY_NU];
		bool m_stop;
		int m_fps;

		Timer m_timer;

};

NS_FS_END


#endif /*_FS_SCHEDULER_H_*/























