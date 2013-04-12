#include "scheduler/FsScheduler.h"
#include "scheduler/FsSchedulerTarget.h"
#include "sys/FsSys.h"
#include "common/FsScriptEngine.h"
#include "common/FsGlobal.h"

NS_FS_BEGIN
const char* Scheduler::className() 
{
	return FS_SCHEDULER_CLASS_NAME;
}

Scheduler* Scheduler::create()
{
	Scheduler* ret=new Scheduler();
	return ret;
}

void Scheduler::start()
{
	m_stop=false;
}
void Scheduler::stop()
{
	m_stop=true;
}
void Scheduler::setFps(int fps)
{
	m_fps=fps;
}

void Scheduler::mainLoop()
{
	long perframe_time=(long)( m_fps<=0?0.0f:1000.0f/(float)m_fps);

	//long begin_time=m_timer.now();
	long last_time=m_timer.now();

	long diff_time,cur_time,frame_used,sleep_time;

	while(!m_stop)
	{
		cur_time=m_timer.now();
		diff_time=cur_time-last_time;
		update((float)diff_time);


		frame_used=m_timer.now()-cur_time;
		sleep_time=perframe_time-frame_used;
		if(sleep_time>0)
		{
			Sys::usleep(sleep_time);
		}
		last_time=cur_time;
	

	}
}

void Scheduler::add(SchedulerTarget* s,int priority)
{
	assert(priority<PRIORITY_NU&&priority>=0);
	assert(!hasTarget(s,priority));
	m_target[priority]->push(s);
}
void Scheduler::remove(SchedulerTarget* s,int priority)
{
	assert(priority<PRIORITY_NU&&priority>=0);
	assert(hasTarget(s,priority));
	m_target[priority]->remove(s);

}
void Scheduler::remove(SchedulerTarget* s)
{
	for(int i=0;i<PRIORITY_NU;i++)
	{
		if(hasTarget(s,i))
		{
			m_target[i]->remove(s);
		}
	}
	assert(!hasTarget(s));
}

Scheduler::Scheduler()
{
	init();
}
Scheduler::~Scheduler()
{
	destroy();
}


bool Scheduler::hasTarget(SchedulerTarget* target,int priority)
{
	int target_nu=m_target[priority]->size();
	for(int i=0;i<target_nu;i++)
	{
		SchedulerTarget* t=(SchedulerTarget*)m_target[priority]->get(i);
		if(t==target)
		{
			t->decRef();
			return true;
		}
		t->decRef();
	}
	return false;
}
bool Scheduler::hasTarget(SchedulerTarget* target)
{
	for(int i=0;i<PRIORITY_NU;i++)
	{
		if(hasTarget(target,i))
		{
			return true;
		}
	}
	return false;
}
void Scheduler::init()
{
	for(int i=0;i<PRIORITY_NU;i++)
	{
		m_target[i]=FsSlowArray::create();
	}
	m_stop=false;
	m_fps=60;
}

void Scheduler::destroy()
{
	for(int i=0;i<PRIORITY_NU;i++)
	{
		m_target[i]->decRef();
	}
}

void Scheduler::update(float dt)
{
	for(int i=0;i<PRIORITY_NU;i++)
	{
		m_target[i]->lock();
		int target_nu=m_target[i]->size();
		for(int j=0;j<target_nu;j++)
		{
			SchedulerTarget* target=(SchedulerTarget*)m_target[i]->get(j);
			target->update(i,dt);
			target->decRef();
		}
		m_target[i]->unlock();
		m_target[i]->flush();
	}

	ScriptEngine* sc=Global::scriptEngine();
	if(sc)
	{
		sc->collectGarbage();
	}
}

NS_FS_END





















