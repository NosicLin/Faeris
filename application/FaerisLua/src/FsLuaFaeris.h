#ifndef _FS_LUA_FAERIS_H_
#define _FS_LUA_FAERIS_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "tolua_event.h"
#include "tolua_hack.h"
#ifdef __cplusplus
} /* extern "C" */
#endif

#include "FsMacros.h"
#include "core/FsObject.h"

#pragma warning (disable:4800)
NS_FS_USE

TOLUA_API int  tolua_FsFaeris_open (lua_State* tolua_S);



#endif /*_FS_LUA_FAERIS_H_*/