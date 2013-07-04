#include <string>

#include "tolua++.h"

#include "FsLuaExport.h"
#include "support/data/FsEncrypt.h"
#include "io/FsVFS.h"
#include "util/FsLog.h"
#include "FsLuaEngine.h"
#include "common/FsGlobal.h"
#include "sys/FsSys.h"


/* all function */
int luaf_xorstring(lua_State* l)
{
	uint32_t data_len,key_len;
	const char* data=luaL_checklstring(l,1,&data_len);
	const char* key=luaL_checklstring(l,2,&key_len);

	uint8_t* data_out=NULL;
	uint data_out_len=0;

	FsEncrypt_Xor( (uint8_t*)data,  
					data_len,

				    (uint8_t**) &data_out, 
					 &data_out_len,

				    (uint8_t*)key, 
					(uint)key_len
					);

	lua_pushlstring(l,(char*)data_out,data_out_len);
	delete[] data_out;

	return 1;
}

int luaf_escstring(lua_State* l)
{
	uint32_t data_len;
	const char* data=luaL_checklstring(l,1,&data_len);

	std::string ret;
	for(uint32_t i=0;i<data_len;i++)
	{
		uint8_t cur=data[i];
		switch(cur)
		{
			case '\a':
				ret.append("\\a");
				break;
			case  '\b':
				ret.append("\\b");
				break;
			case '\n':
				ret.append("\\n");
				break;
			case '\r':
				ret.append("\\r");
				break;
			case '\t':
				ret.append("\\t");
				break;
			case '\v':
				ret.append("\\v");
				break;
			case '\\':
				ret.append("\\\\");
				break;
			case '\"':
				ret.append("\\\"");
				break;
			case '\'':
				ret.append("\\\'");
				break;
			case '[':
				ret.append("\\[");
				break;
			case ']':
				ret.append("\\]");
				break;
			default:
				ret.append(1,cur);
		}
	}
	lua_pushlstring(l,ret.c_str(),ret.size());
	return 1;
}


int luaf_savefile(lua_State* l)
{
	uint32_t file_name_len,data_len;
	const char* file_name=luaL_checklstring(l,1,&file_name_len);
	const char* data=luaL_checklstring(l,2,&data_len);


	int ret=VFS::saveFile(file_name,(const uint8_t*)data,data_len);
	lua_pushinteger(l,ret);
	return 1;
}


int luaf_loadfile(lua_State* l)
{
	const char* file_name=luaL_checkstring(l,1);

	uint8_t* data=NULL;
	uint data_len=0;
	int ret=VFS::loadFile(file_name,&data,&data_len);
	if(ret==-1)
	{
		lua_pushnil(l);
	}
	else 
	{
		lua_pushlstring(l,(const char*) data,data_len);
		delete[] data;
	}
	return 1;
}

int luaf_log(lua_State* l)
{
	const char* info=luaL_checkstring(l,1);
	FsUtil_Log("%s",info);
	return 0;
}
int luaf_logtag(lua_State* l)
{
	const char* tag=luaL_checkstring(l,1);
	const char* info=luaL_checkstring(l,2);
	FsUtil_Log(tag,info);
	return 0;
}

int luaf_import(lua_State* l)
{
	const char* file=luaL_checkstring(l,1);

	LuaEngine* engine=(LuaEngine*)Global::scriptEngine();
	if(engine==NULL)
	{
		lua_pushboolean(l,false);
	}
	if(engine->executeFile(file)==0)
	{
		lua_pushboolean(l,true);
	}
	else 
	{
		lua_pushboolean(l,false);
	}
	return 1;
}

int luaf_exit(lua_State* l)
{
	Scheduler* s=Global::scheduler();
	s->stop();
	return 0;
}

int luaf_setenv(lua_State* l)
{
	const char* key=luaL_checkstring(l,1);
	const char* value=luaL_checkstring(l,2);

	Sys::setEnv(key,value);
	return 0;
}
int luaf_getenv(lua_State* l)
{
	const char* key=luaL_checkstring(l,1);

	const char* value=Sys::getEnv(key);
	if(value==NULL)
	{
		lua_pushnil(l);
	}
	else
	{
		lua_pushstring(l,value);
	}
	return 1;
}

static const struct luaL_reg luafuncs[]=
{
	{"f_xorstring",luaf_xorstring},
	{"f_escstring",luaf_escstring},
	{"f_savefile",luaf_savefile},
	{"f_loadfile",luaf_loadfile},
	{"f_log",luaf_log},
	{"f_logtag",luaf_logtag},
	{"f_import",luaf_import},
	{"f_exit",luaf_exit},
	{"f_getenv",luaf_getenv},
	{"f_setenv",luaf_setenv},
	{NULL,NULL},
};




int tolua_FsLuaFuncExport_open(lua_State* l)
{

	for(int i=0;luafuncs[i].name&&luafuncs[i].func;i++)
	{
		lua_pushcfunction(l, luafuncs[i].func);
		lua_setglobal(l, luafuncs[i].name);
	}
	return 0;
}

