#ifndef _TOLUA_HACK_H_
#define _TOLUA_HACK_H_

#include "tolua++.h"


TOLUA_API void tolua_fs_open(lua_State* L);
TOLUA_API void tolua_fs_regobject(const char* name);

TOLUA_API int tolua_fs_isfunction(lua_State* L,int lo,const char* type,int def,tolua_Error* err);
TOLUA_API int tolua_fs_to_reffunction(lua_State* L,int lo,int def);
TOLUA_API void tolua_fs_push_reffunction(lua_State* L,int refid);
TOLUA_API void tolua_fs_remove_reffunction(lua_State* L,int refid);






#endif /*_TOLUA_HACK_H_*/

