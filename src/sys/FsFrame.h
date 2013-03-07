#ifndef _FAERIS_FRAME_H_
#define _FAERIS_FRAME_H_

#include <vector>
#include "FsMacros.h"
#include "sys/FsTimer.h"


NS_FS_BEGIN

class Frame;
class FrameListener
{
	public:
		virtual void frameBegin(long diff);
		virtual void frameUpdate(long diff);
		virtual void frameEnd(long diff);

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
		void setFPS(int nu);
		int getFPS();
		void start();
		void stop();

		void setInstantGap(long time);
		int getInstantFPS();

		int getAvgFPS();

		void addListener(FrameListener* l);
		void removeListener(FrameListener* l);
	protected:
		void frameBegin(long diff);
		void frameUpdate(long diff);
		void frameEnd(long diff);
	private:
		Frame();
	private:
		bool m_stop;
		int m_FPS;

		Timer m_timer;

		long m_beginTime;
		long m_idleTime;
		long m_curTime;
		long m_curFrame;
		long m_frameTime;

		long m_instantGap;
		long m_instantFrame;
		long m_instantTime;
		long m_instantFPS;

		typedef std::vector<FrameListener*>::iterator Iterator;
		std::vector<FrameListener*> m_listener;
};

NS_FS_END

#endif /*_FAERIS_FRAME_H_*/

