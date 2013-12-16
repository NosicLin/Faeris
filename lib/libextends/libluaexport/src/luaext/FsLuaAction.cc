#include "FsLuaMacros.h"

#include "luaext/FsLuaAction.h"
#include "FsLuaEngine.h"
#include "FsGlobal.h"

NS_FS_BEGIN


const char* LuaAction::className()
{
	return FS_LUA_ACTION_CLASS_NAME;
}



LuaAction* LuaAction::create()
{
	return new LuaAction;
}

bool LuaAction::run(ActionTarget* target,float dt)
{

	LuaEngine* se=(LuaEngine*)Global::scriptEngine();
	if(!se->callFunctionInTable(m_scriptData,"onRun",3,1,"ffn",this,target,dt))
	{
		return true;
	}

	bool ret=se->toBoolean(-1);

	se->pop();
	return ret;
}






NS_FS_END
