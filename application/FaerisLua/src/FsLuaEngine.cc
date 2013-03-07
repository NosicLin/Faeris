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

#include "FsLuaEngine.h"
#include "FsLuaFaeris.h"
#include "util/FsLog.h"
#include "io/FsVFS.h"



NS_FS_USE

static LuaEngine* s_shareEngine=NULL;

LuaEngine* LuaEngine::shareEngine()
{
	if(s_shareEngine==NULL)
	{
		s_shareEngine=new LuaEngine;
	}
	return s_shareEngine;
}

void LuaEngine::purgeShareEngine()
{
	delete s_shareEngine;
	s_shareEngine=NULL;
}

LuaEngine::LuaEngine()
{
	m_state=lua_open();
	luaL_openlibs(m_state);
	tolua_FsFaeris_open(m_state);
	tolua_fs_open(m_state);
}


LuaEngine::~LuaEngine()
{
	lua_close(m_state);
	m_state=NULL;
}


int LuaEngine::executeString(const char* codes)
{
	int ret=luaL_dostring(m_state,codes);
	if(ret!=0)
	{
		FsUtil_Log("[LUA_ERROR] %s",lua_tostring(m_state,-1));
		lua_pop(m_state,1);
		return -1;
	}
	return 0;
}



#define FS_DEFALUT_LUA_BUFFER_SIZE 2048
static  char s_buffer[FS_DEFALUT_LUA_BUFFER_SIZE];

static const char* s_file_lua_reader(lua_State* L,void* data,size_t* size) 
{
	FsFile* file=(FsFile*)data;
	int readbyte=file->read(s_buffer,FS_DEFALUT_LUA_BUFFER_SIZE);
	if(readbyte<0)
	{
		return 0;
	}

	*size=readbyte;
	return s_buffer;
}

int LuaEngine::executeFile(const char* filename)
{
	FsFile* file=VFS::open(filename);
	if(file==NULL)
	{
		FsUtil_Log("[LUA_ERROR] File Not Found %s", filename);
		return -1;
	}
	if(lua_load(m_state,s_file_lua_reader,file,filename)||lua_pcall(m_state,0,LUA_MULTRET,0))
	{
		FsUtil_Log("[LUA_ERROR] %s",lua_tostring(m_state,-1));
		lua_pop(m_state,1);
		file->decRef();
		return -1;
	}
	file->decRef();
	return 0;
}


void LuaEngine::pushInteger(int value)
{
	lua_pushinteger(m_state,value);
}
void LuaEngine::pushNumber(double value)
{
	lua_pushnumber(m_state,value);
}
void LuaEngine::pushString(const char* str)
{
	lua_pushstring(m_state,str);
}
void LuaEngine::pushUserType(void* value,const char* type)
{
	tolua_pushusertype(m_state,value,type);
}

void LuaEngine::pushCFunction(CFunction func)
{

	lua_pushcfunction(m_state,func);
}


void LuaEngine::setGlobalCFunction(const char* name,CFunction func)
{
	lua_pushcfunction(m_state,func);
	lua_setfield(m_state,LUA_GLOBALSINDEX,name);
}

void LuaEngine::setGlobalUserType(const char* name,void* data,const char* type)
{
	tolua_pushusertype(m_state,data,type);
	lua_setfield(m_state,LUA_GLOBALSINDEX,name);
}


void LuaEngine::removeRefFunction(int refid)
{
	tolua_fs_remove_reffunction(m_state,refid);
}

void LuaEngine::pushRefFunction(int refid)
{
	tolua_fs_push_reffunction(m_state,refid);
}

void LuaEngine::call(int argu,int retnu)
{
	if(lua_pcall(m_state,argu,retnu,0))
	{
		FsUtil_Log("[LUA_ERROR] %s",lua_tostring(m_state,-1));
	}
}



















