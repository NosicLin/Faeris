#include <string.h>
#include "math/FsMathUtil.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "lua.h"
#include "lauxlib.h"
#include "tolua_event.h"
#include "tolua_ext.h"

#ifdef __cplusplus
} /* extern "C" */
#endif


#include "core/FsObject.h"

#define TOLUA_REFID_FUNCTION_MAPPING "tolua_reffunction_mapping"
#define TOLUA_REFID_TABLE_MAPPING  "tolua_table_mapping"
NS_FS_USE


static int fs_class_gc_event(lua_State* L)
{
	FsObject* u=(FsObject*)lua_touserdata(L,1);
	u->decRef();
	return 0;
}


static int toluaext_newmetatable(lua_State* L,const char* name)
{
	int r=luaL_newmetatable(L,name);
#ifdef LUA_VERSION_NUM
	if(r)
	{
		lua_pushvalue(L,-1);
		lua_pushstring(L,name);
		lua_settable(L,LUA_REGISTRYINDEX);
	};
#endif 
	if(r)
	{
		tolua_classevents(L);
		lua_pushstring(L,"__gc");
		lua_pushcfunction(L,fs_class_gc_event);
	}
	lua_pop(L,1);
	return r;
}
TOLUA_API void toluaext_open(lua_State* L)
{
	/* register function table */
	lua_pushstring(L,TOLUA_REFID_FUNCTION_MAPPING); /*statck "str"  table */
	lua_newtable(L);
	lua_rawset(L,LUA_REGISTRYINDEX);

	/* register table table */
	lua_pushstring(L,TOLUA_REFID_TABLE_MAPPING); /*statck "str"  table */
	lua_newtable(L);
	lua_rawset(L,LUA_REGISTRYINDEX);
}


TOLUA_API void toluaext_fsobject(lua_State* L,const char* type)
{
	char ctype[128]="const";
	strncat(ctype,type,120);
	if(toluaext_newmetatable(L,ctype)&&toluaext_newmetatable(L,type))
	{
		tolua_mapsuper(L,type,ctype);
	}
}

TOLUA_API void toluaext_pushfsobject(lua_State* l,Faeris::FsObject* ob)
{
	const char* name=ob->className();
	tolua_pushusertype(l,ob,name);
}

TOLUA_API int toluaext_to_luafunction(lua_State* L,int lo,int def)
{
	static int s_function_ref_id=1;
	if(!lua_isfunction(L,lo)) return 0;

	s_function_ref_id++;
	lua_pushstring(L,TOLUA_REFID_FUNCTION_MAPPING);  
	lua_rawget(L,LUA_REGISTRYINDEX);			 /* stack: fun .... mapping */
	lua_pushinteger(L,s_function_ref_id);    /* stack: fun .... mapping refid */
	lua_pushvalue(L,lo); 					 /* stack: fun .... mapping refid func */
	lua_rawset(L,-3);						 /* stack: fun .... mapping  */
	lua_pop(L,1);
	return s_function_ref_id;
}

TOLUA_API void toluaext_push_luafunction(lua_State* L,int refid)
{
	lua_pushstring(L,TOLUA_REFID_FUNCTION_MAPPING);
	lua_rawget(L,LUA_REGISTRYINDEX);			/* stack: ... mapping */
	lua_pushinteger(L,refid);			    /* stack: ... mapping refid */
	lua_rawget(L,-2);						/* stack: ... mapping func */
	lua_remove(L,-2);						/* stack: ... func */

}
TOLUA_API void toluaext_remove_luafunction(lua_State* L,int refid)
{
	lua_pushstring(L,TOLUA_REFID_FUNCTION_MAPPING);
	lua_rawget(L,LUA_REGISTRYINDEX);			/* stack: ... mapping */
	lua_pushinteger(L,refid);               /* stack: ... mapping refid */
	lua_pushnil(L);	                        /* stack: ... mapping refid nil */
	lua_rawset(L,-3);                       /* stack: ... mapping */
	lua_pop(L,1);

}


TOLUA_API int toluaext_is_luafunction(lua_State* L,int lo,const char* type,int def,tolua_Error* err)
{
	if(lua_gettop(L)>=Math::abs(lo)&&lua_isfunction(L,lo))
	{
		return 1;
	}
	err->index=lo;
	err->array=0;
	err->type="[function]";
	return 0;
}

/* lua table */
TOLUA_API int toluaext_is_luatable(lua_State* L,int lo,const char* type,int def,tolua_Error* err)
{
	if(lua_gettop(L)>=Math::abs(lo)&&lua_istable(L,lo))
	{
		return 1;
	}
	err->index=lo;
	err->array=0;
	err->type="[table]";
	return 0;
}


TOLUA_API void toluaext_remove_luatable(lua_State* L,int refid)
{
	lua_pushstring(L,TOLUA_REFID_TABLE_MAPPING);
	lua_rawget(L,LUA_REGISTRYINDEX);			/* stack: ... mapping */
	lua_pushinteger(L,refid);               /* stack: ... mapping refid */
	lua_pushnil(L);	                        /* stack: ... mapping refid nil */
	lua_rawset(L,-3);                       /* stack: ... mapping */
	lua_pop(L,1);

}

TOLUA_API void toluaext_push_luatable(lua_State* L,int refid)
{
	lua_pushstring(L,TOLUA_REFID_TABLE_MAPPING);
	lua_rawget(L,LUA_REGISTRYINDEX);			/* stack: ... mapping */
	lua_pushinteger(L,refid);			    /* stack: ... mapping refid */
	lua_rawget(L,-2);						/* stack: ... mapping t */
	lua_remove(L,-2);						/* stack: ... t */

}

TOLUA_API int toluaext_to_luatable(lua_State* L,int lo,int def)
{
	static int s_table_ref_id=1;
	if(!lua_istable(L,lo)) return -1;

	s_table_ref_id++;
	lua_pushstring(L,TOLUA_REFID_TABLE_MAPPING);  
	lua_rawget(L,LUA_REGISTRYINDEX);			 /* stack: fun .... mapping */
	lua_pushinteger(L,s_table_ref_id);    /* stack: fun .... mapping refid */
	lua_pushvalue(L,lo); 					 /* stack: fun .... mapping refid func */
	lua_rawset(L,-3);						 /* stack: fun .... mapping  */
	lua_pop(L,1);
	return s_table_ref_id;
}

