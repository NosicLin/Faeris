#include "FsLuaMacros.h"
#include "FsGlobal.h"
#include "luaext/FsLuaSysEventListener.h"
#include "FsLuaEngine.h"

NS_FS_BEGIN

const char* LuaSysEventListener::className()
{
	return FS_LUA_SYS_EVENT_LISTENER_CLASS_NAME;
}


LuaSysEventListener* LuaSysEventListener::create()
{
	LuaSysEventListener* ret=new LuaSysEventListener;
	return ret;
}

void LuaSysEventListener::foreground()
{

	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onForeground",1,0,"f",this);
}

void LuaSysEventListener::background()
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onBackground",1,0,"f",this);
}

void LuaSysEventListener::exit()
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onExit",1,0,"f",this);
}

void LuaSysEventListener::quit()
{
	LuaEngine* se=(LuaEngine*) Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onQuit",1,0,"f",this);
}

LuaSysEventListener::LuaSysEventListener()
{

}
LuaSysEventListener::~LuaSysEventListener()
{

}

NS_FS_END








