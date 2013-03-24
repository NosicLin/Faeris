#include "scheduler/FsScheduler.h"

const char* Scheduler::className()const 
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
	float perframe_time= m_fps<=0?0.0f:1.0f/(float)m_fps;

	float begin_time=m_timer.now();
	float last_time=m_timer.now();

	float diff_time,cur_time,frame_used,sleep_time;

	while(!m_stop)
	{
		cur_time=m_timer.now();
		diff_time=cur_time-last_time;
		update(diff_time);
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
	m_target[priority]->add(s);
}
void Scheduler::remove(SchedulerTarget* s,int priority)
{
	assert(priority<PRIORITY_NU&&priority>=0);
	m_target[priority]->remove(s);
}

void Scheduler::init()
{
	for(int i=0;i<PRIORITY_NU;i++)
	{
		m_target[i]=new FsSlowArray();
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
		int target_nu=m_target[i]->size();
		for(int j=0;j<target_nu;j++)
		{
			SchedulerTarget* target=m_target[i]->get(j);
			target->update(i,dt);
			target->decRef();
		}
	}
}























