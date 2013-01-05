#ifndef _FAERIS_FRAME_H_
#define _FAERIS_FRAME_H_

#include <vector>
#include "FsMacros.h"
#include "fsys/FsTimer.h"


NS_FS_BEGIN

class Frame;
class FrameListener
{
	public:
		virtual void frameBegin(FsLong diff);
		virtual void frameUpdate(FsLong diff);
		virtual void frameEnd(FsLong diff);

		FrameListener(){m_frame=NULL;}
		virtual ~FrameListener();
	private:
		Frame* m_frame;
		friend class Frame;
};

class Frame 
{
	public:
		static Frame* shareFrame();
		static void purgeShareFrame();
	public:
		void setFPS(FsInt nu);
		FsInt getFPS();
		void start();
		void stop();

		void setInstantGap(FsLong time);
		FsInt getInstantFPS();

		FsInt getAvgFPS();

		void addListener(FrameListener* l);
		void removeListener(FrameListener* l);
	protected:
		void frameBegin(FsLong diff);
		void frameUpdate(FsLong diff);
		void frameEnd(FsLong diff);
	private:
		Frame();
	private:
		bool m_stop;
		FsInt m_FPS;

		Timer m_timer;

		FsLong m_beginTime;
		FsLong m_idleTime;
		FsLong m_curTime;
		FsLong m_curFrame;
		FsLong m_frameTime;

		FsLong m_instantGap;
		FsLong m_instantFrame;
		FsLong m_instantTime;
		FsLong m_instantFPS;

		typedef std::vector<FrameListener*>::iterator Iterator;
		std::vector<FrameListener*> m_listener;
};

NS_FS_END

#endif /*_FAERIS_FRAME_H_*/

