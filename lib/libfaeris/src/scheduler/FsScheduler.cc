#include "scheduler/FsScheduler.h"
#include "scheduler/FsSchedulerTarget.h"
#include "scheduler/FsTask.h"
#include "sys/FsSys.h"
#include "extends/FsScriptEngine.h"
#include "FsGlobal.h"

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
	m_intervalTime=(float)( m_fps<=0?0.0f:1000.0f/(float)m_fps);
}

void Scheduler::mainLoop()
{
	//long begin_time=m_timer.now();
	float last_time=m_timer.now();

	float diff_time,cur_time;

	while(!m_stop)
	{
		cur_time=m_timer.now();
		diff_time=cur_time-last_time;


		float sleep_time=update((float)diff_time);
		
		while(m_timer.now()-cur_time<=m_intervalTime){}
		
		
	
		/*
		if(sleep_time>0)
		{
			Sys::usleep((long)sleep_time);
		}
		*/

		
		
	
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

void Scheduler::runSyncTask(Task* t)
{
	m_taskLock->lock();
	m_taskPending->push(t);
	m_taskLock->unlock();
}


void Scheduler::init()
{
	for(int i=0;i<PRIORITY_NU;i++)
	{
		m_target[i]=FsSlowArray::create();
	}
	m_stop=false;
	m_fps=60;
	m_intervalTime=(1.0f/60.0f)*1000;

	m_taskHanding=FsArray::create();
	m_taskPending=FsArray::create();
	m_taskLock=new Mutex();
}

void Scheduler::destroy()
{
	for(int i=0;i<PRIORITY_NU;i++)
	{
		m_target[i]->decRef();
		m_target[i]=NULL;
	}
	m_taskPending->decRef();
	m_taskPending=NULL;

	m_taskHanding->decRef();
	m_taskHanding=NULL;
	delete m_taskLock;
	m_taskLock=NULL;


}

float Scheduler::update(float dt)
{

	float update_begin=m_timer.now();
	/* run sync task,
	 * swap task pending queue and handing queue 
	 * for minimize lock time 
	 */ 
	m_taskLock->lock();
	if(m_taskPending->size()!=0)
	{
		FsArray* tmp=m_taskHanding;
		m_taskHanding=m_taskPending;
		m_taskPending=tmp;
	}
	m_taskLock->unlock();

	/* running all pend task */
	int task_nu=m_taskHanding->size();
	for(int i=0;i<task_nu;i++)
	{
		Task* t=(Task*)m_taskHanding->get(i);
		t->run();
		t->decRef();
	}
	m_taskHanding->clear();


	float perframe_time=m_intervalTime;

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

	
	/*
	
	ScriptEngine* sc=Global::scriptEngine();
	if(sc)
	{

		sc->collectGarbage();
	}
	*/
	
	

	float update_end=m_timer.now();

	return (float)(perframe_time-(update_end-update_begin));
}

NS_FS_END





















