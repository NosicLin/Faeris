#ifndef _FS_LUA_FRAME_LISTENER_H_
#define _FS_LUA_FRAME_LISTENER_H_
#include "fsys/FsFrame.h"
#include "FsLuaEngine.h"

NS_FS_USE
class LuaFrameListener:public FrameListener 
{
	public:
		virtual void frameBegin(FsLong diff);
		virtual void frameUpdate(FsLong diff);
		virtual void frameEnd(FsLong diff);
	public:
		void registerUpdateFunc(FsInt func);
		void registerBeginFunc(FsInt func);
		void registerEndFunc(FsInt func);
	public:
		LuaFrameListener();
		~LuaFrameListener();
	private:
		FsInt m_beginFunc;
		FsInt m_updateFunc;
		FsInt m_endFunc;
		LuaEngine* m_engine;
};


#endif /*_FS_LUA_FRAME_LISTENER_H_*/

