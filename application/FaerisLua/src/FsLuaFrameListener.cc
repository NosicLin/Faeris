#include "FsLuaFrameListener.h"

LuaFrameListener::LuaFrameListener()
{
	m_beginFunc=0;
	m_updateFunc=0;
	m_endFunc=0;
	m_engine=LuaEngine::shareEngine();
}

LuaFrameListener::~LuaFrameListener()
{
	if(m_beginFunc)
	{
		m_engine->removeRefFunction(m_beginFunc);
	}
	if(m_updateFunc)
	{
		m_engine->removeRefFunction(m_updateFunc);
	}
	if(m_endFunc)
	{
		m_engine->removeRefFunction(m_endFunc);
	}
}

void LuaFrameListener::frameBegin(FsLong diff)
{
	if(m_beginFunc)
	{
		m_engine->pushRefFunction(m_beginFunc);
		m_engine->pushInteger(diff);
		m_engine->call(1,0);
	}
}
void LuaFrameListener::frameUpdate(FsLong diff)
{

	if(m_updateFunc)
	{
		m_engine->pushRefFunction(m_updateFunc);
		m_engine->pushInteger(diff);
		m_engine->call(1,0);
	}
}
void LuaFrameListener::frameEnd(FsLong diff)
{
	if(m_endFunc)
	{
		m_engine->pushRefFunction(m_endFunc);
		m_engine->pushInteger(diff);
		m_engine->call(1,0);
	}
}

void LuaFrameListener::registerBeginFunc(FsInt func)
{
	if(m_beginFunc)
	{
		m_engine->removeRefFunction(m_beginFunc);
	}
	m_beginFunc=func;
}
void LuaFrameListener::registerUpdateFunc(FsInt func)
{
	if(m_updateFunc)
	{
		m_engine->removeRefFunction(m_updateFunc);
	}
	m_updateFunc=func;
}

void LuaFrameListener::registerEndFunc(FsInt func)
{
	if(m_endFunc)
	{
		m_engine->removeRefFunction(m_endFunc);
	}
	m_endFunc=func;
}






