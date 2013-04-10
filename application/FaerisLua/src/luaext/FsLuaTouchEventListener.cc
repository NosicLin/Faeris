#include "FsLuaMacros.h"
#include "FsLuaEngine.h"
#include "luaext/FsLuaTouchEventListener.h"
#include "common/FsGlobal.h"


NS_FS_BEGIN

const char* LuaTouchEventListener::className()
{
	return FS_LUA_TOUCH_EVENT_LISTENER_CLASS_NAME;
}


LuaTouchEventListener* LuaTouchEventListener::create()
{
	LuaTouchEventListener* ret=new LuaTouchEventListener();
	return ret;
}

/* override supper */

void LuaTouchEventListener::touchBegin(float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onTouchBegin",3,0,"fnn",this,x,y);
}

void LuaTouchEventListener::touchMove(float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onTouchMove",3,0,"fnn",this,x,y);
}

void LuaTouchEventListener::touchEnd(float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onTouchEnd",3,0,"fnn",this,x,y);
}

void LuaTouchEventListener::touchCancel(float x,float y)
{
	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	se->callFunctionInTable(m_scriptData,"onCancel",3,0,"fnn",this,x,y);
}

NS_FS_END 







