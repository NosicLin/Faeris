#include "FsxAccessModule.h"
#include "FsLuaEngine.h"
#include "FsGlobal.h"
#include "FsxAccessExport.h"


NS_FS_USE;

int FsModuel_xAccessInit()
{
	LuaEngine* engine=(LuaEngine*)Global::scriptEngine();
	struct lua_State* L= engine->getLuaState();
	tolua_FslibxAccess_open(L);
	return 0;
}
