#ifndef _FS_LUA_FRAME_LISTENER_H_
#define _FS_LUA_FRAME_LISTENER_H_
#include "sys/FsFrame.h"
#include "FsLuaEngine.h"

NS_FS_USE
class LuaFrameListener:public FrameListener 
{
	public:
		virtual void frameBegin(long diff);
		virtual void frameUpdate(long diff);
		virtual void frameEnd(long diff);
	public:
		void registerUpdateFunc(int func);
		void registerBeginFunc(int func);
		void registerEndFunc(int func);
	public:
		LuaFrameListener();
		~LuaFrameListener();
	private:
		int m_beginFunc;
		int m_updateFunc;
		int m_endFunc;
		LuaEngine* m_engine;
};


#endif /*_FS_LUA_FRAME_LISTENER_H_*/

