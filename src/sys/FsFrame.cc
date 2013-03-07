#include "sys/FsFrame.h"
#include "sys/FsSys.h"

NS_FS_BEGIN
static Frame* s_shareFrame=NULL;
Frame* Frame::shareFrame()
{
	if(s_shareFrame==NULL)
	{
		s_shareFrame=new Frame;
	}
	return s_shareFrame;
}
void Frame::purgeShareFrame()
{
	if(s_shareFrame)
	{
		delete s_shareFrame;
		s_shareFrame=NULL;
	}
}


Frame::Frame()
{
	m_stop=true;
	m_FPS=0;
	m_timer.reset();
	m_beginTime=m_timer.now();
	m_idleTime=0;
	m_curTime=m_timer.now();
	m_curFrame=0;
	m_frameTime=0;

	m_instantGap=1000;
	m_instantFrame=0;
	m_instantTime=0;
	m_instantFPS=0;
}


void Frame::setFPS(int fps)
{
	m_FPS=fps;
	if(m_FPS==0)
	{
		m_frameTime=0;
	}
	else
	{
		m_frameTime=1000/m_FPS;
	}
}

int Frame::getFPS()
{
	return m_FPS;
}

void Frame::start()
{
	long lastframe_time,diff_time,frame_used;
	long sleep_time;
	m_beginTime=m_timer.now();
	m_idleTime=0;
	m_curFrame=0;

	m_instantFPS=0;

	m_stop=false;
	m_curTime=m_timer.now();
	lastframe_time=m_curTime;

	m_instantTime=0;
	m_instantFrame=0;

	while(!m_stop)
	{

		m_curTime=m_timer.now();
		diff_time=m_curTime-lastframe_time;

		frameBegin(diff_time);
		frameUpdate(diff_time);
		frameEnd(diff_time);

		frame_used=m_timer.now()-m_curTime;
		sleep_time=m_frameTime-frame_used;
		if(sleep_time>0)
		{
			m_idleTime+=sleep_time;
			Sys::usleep(sleep_time);

		}

		m_instantTime+=diff_time;
		m_curFrame++;
		m_instantFrame++;

		if(m_instantTime>m_instantGap)
		{
			m_instantFrame=0;
			m_instantFPS=m_instantFrame;
		}
		lastframe_time=m_curTime;

	}
}
void Frame::frameBegin(long diff)
{
	Iterator iter;
	for(iter=m_listener.begin();iter<m_listener.end();++iter)
	{
		if(*iter)
		{
			(*iter)->frameBegin(diff);
		}
	}
}
void Frame::frameUpdate(long diff)
{
	Iterator iter;
	for(iter=m_listener.begin();iter<m_listener.end();++iter)
	{
		(*iter)->frameUpdate(diff);
	}
}
void Frame::frameEnd(long diff)
{
	Iterator iter;
	for(iter=m_listener.begin();iter<m_listener.end();++iter)
	{
		(*iter)->frameEnd(diff);
	}
}

void Frame::addListener(FrameListener* l)
{
	if(l->m_frame!=NULL)
	{
		FS_TRACE_WARN("FrameListener Already Add");
		return;
	}
	m_listener.push_back(l);
	l->m_frame=this;
}

void Frame::removeListener(FrameListener* l)
{
	if(l->m_frame==NULL)
	{
		FS_TRACE_WARN("FrameListener Not Add");
		return;
	}
	Iterator iter;
	for(iter=m_listener.begin();iter<m_listener.end();++iter)
	{
		if(*iter==l)
		{
			m_listener.erase(iter);
			l->m_frame=NULL;
			return;
		}
	}
	FS_TRACE_WARN("Can't Find Listener In Frame");
}


void Frame::stop()
{
	m_stop=true;
}
void Frame::setInstantGap(long time)
{
	m_instantGap=time;
}
int Frame::getInstantFPS()
{
	return m_instantFPS;
}
int Frame::getAvgFPS()
{
	int seconds=(m_curTime-m_beginTime)/1000;
	if(seconds==0)
	{
		return 0;
	}
	else
	{
		return m_curFrame/seconds;
	}
}

void FrameListener::frameBegin(long diff){}
void FrameListener::frameUpdate(long diff){}
void FrameListener::frameEnd(long diff){}
FrameListener::~FrameListener()
{
	if(m_frame)
	{
		m_frame->removeListener(this);
		m_frame=NULL;
	}
}


NS_FS_END

