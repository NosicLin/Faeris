
#include "FsLuaEngine.h"
#include "FsGlobal.h"
#include "FsLibPayExport.h"

NS_FS_USE;

int FsModuel_PayInit()
{
	LuaEngine* engine=(LuaEngine*)Global::scriptEngine();
	struct lua_State* L= engine->getLuaState();
	tolua_FsLibPay_open(L);
	return 0;

}
