/*
** Lua binding: FsLibNetwork
** Generated automatically by tolua++-1.0.92 on Tue Jul  2 00:07:13 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_FsLibNetwork_open (lua_State* tolua_S);

#include "FsLuaExport.h"
#include "FsHttpEngine.h"
#include "luaext/FsLuaHttpRequest.h"
#include "FsHttpReponse.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"LuaHttpRequest");
 toluaext_usertype(tolua_S,"FsObject");
 tolua_usertype(tolua_S,"HttpEngine");
}

/* method: create of class  HttpEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibNetwork_HttpEngine_create00
static int tolua_FsLibNetwork_HttpEngine_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HttpEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   HttpEngine* tolua_ret = (HttpEngine*)  HttpEngine::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"HttpEngine");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send of class  HttpEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibNetwork_HttpEngine_send00
static int tolua_FsLibNetwork_HttpEngine_send00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpEngine* self = (HttpEngine*)  tolua_tousertype(tolua_S,1,0);
  LuaHttpRequest* request = ((LuaHttpRequest*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send'", NULL);
#endif
  {
   self->send(request);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  HttpEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibNetwork_HttpEngine_clear00
static int tolua_FsLibNetwork_HttpEngine_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpEngine* self = (HttpEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'", NULL);
#endif
  {
   self->clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stop of class  HttpEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibNetwork_HttpEngine_stop00
static int tolua_FsLibNetwork_HttpEngine_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpEngine* self = (HttpEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibNetwork_HttpRequest_create00
static int tolua_FsLibNetwork_HttpRequest_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaHttpRequest* tolua_ret = (LuaHttpRequest*)  LuaHttpRequest::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaHttpRequest");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUrl of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibNetwork_HttpRequest_setUrl00
static int tolua_FsLibNetwork_HttpRequest_setUrl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* url = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUrl'", NULL);
#endif
  {
   self->setUrl(url);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUrl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getUrl of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibNetwork_HttpRequest_getUrl00
static int tolua_FsLibNetwork_HttpRequest_getUrl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUrl'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getUrl();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUrl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMethod of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibNetwork_HttpRequest_setMethod00
static int tolua_FsLibNetwork_HttpRequest_setMethod00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  int method = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMethod'", NULL);
#endif
  {
   self->setMethod(method);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMethod'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMethod of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibNetwork_HttpRequest_getMethod00
static int tolua_FsLibNetwork_HttpRequest_getMethod00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMethod'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getMethod();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMethod'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVersion of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibNetwork_HttpRequest_setVersion00
static int tolua_FsLibNetwork_HttpRequest_setVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  int version = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVersion'", NULL);
#endif
  {
   self->setVersion(version);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVersion of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibNetwork_HttpRequest_getVersion00
static int tolua_FsLibNetwork_HttpRequest_getVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVersion'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getVersion();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addHeader of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibNetwork_HttpRequest_addHeader00
static int tolua_FsLibNetwork_HttpRequest_addHeader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* header = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addHeader'", NULL);
#endif
  {
   self->addHeader(header);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addHeader'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeHeader of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibNetwork_HttpRequest_removeHeader00
static int tolua_FsLibNetwork_HttpRequest_removeHeader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* header = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeHeader'", NULL);
#endif
  {
   self->removeHeader(header);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeHeader'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearHeader of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibNetwork_HttpRequest_clearHeader00
static int tolua_FsLibNetwork_HttpRequest_clearHeader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearHeader'", NULL);
#endif
  {
   self->clearHeader();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearHeader'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHeaderNu of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibNetwork_HttpRequest_getHeaderNu00
static int tolua_FsLibNetwork_HttpRequest_getHeaderNu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeaderNu'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getHeaderNu();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeaderNu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setData of class  LuaHttpRequest */
#ifndef TOLUA_DISABLE_tolua_FsLibNetwork_HttpRequest_setData00
static int tolua_FsLibNetwork_HttpRequest_setData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaHttpRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaHttpRequest* self = (LuaHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* data = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setData'", NULL);
#endif
  {
   self->setData(data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_FsLibNetwork_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"HttpEngine","HttpEngine","FsObject",NULL);
  tolua_beginmodule(tolua_S,"HttpEngine");
   tolua_function(tolua_S,"create",tolua_FsLibNetwork_HttpEngine_create00);
   tolua_function(tolua_S,"send",tolua_FsLibNetwork_HttpEngine_send00);
   tolua_function(tolua_S,"clear",tolua_FsLibNetwork_HttpEngine_clear00);
   tolua_function(tolua_S,"stop",tolua_FsLibNetwork_HttpEngine_stop00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"HttpRequest","LuaHttpRequest","FsObject",NULL);
  tolua_beginmodule(tolua_S,"HttpRequest");
   tolua_constant(tolua_S,"VERSION_1_0",LuaHttpRequest::VERSION_1_0);
   tolua_constant(tolua_S,"VERSION_1_1",LuaHttpRequest::VERSION_1_1);
   tolua_constant(tolua_S,"METHOD_GET",LuaHttpRequest::METHOD_GET);
   tolua_constant(tolua_S,"METHOD_POST",LuaHttpRequest::METHOD_POST);
   tolua_function(tolua_S,"create",tolua_FsLibNetwork_HttpRequest_create00);
   tolua_function(tolua_S,"setUrl",tolua_FsLibNetwork_HttpRequest_setUrl00);
   tolua_function(tolua_S,"getUrl",tolua_FsLibNetwork_HttpRequest_getUrl00);
   tolua_function(tolua_S,"setMethod",tolua_FsLibNetwork_HttpRequest_setMethod00);
   tolua_function(tolua_S,"getMethod",tolua_FsLibNetwork_HttpRequest_getMethod00);
   tolua_function(tolua_S,"setVersion",tolua_FsLibNetwork_HttpRequest_setVersion00);
   tolua_function(tolua_S,"getVersion",tolua_FsLibNetwork_HttpRequest_getVersion00);
   tolua_function(tolua_S,"addHeader",tolua_FsLibNetwork_HttpRequest_addHeader00);
   tolua_function(tolua_S,"removeHeader",tolua_FsLibNetwork_HttpRequest_removeHeader00);
   tolua_function(tolua_S,"clearHeader",tolua_FsLibNetwork_HttpRequest_clearHeader00);
   tolua_function(tolua_S,"getHeaderNu",tolua_FsLibNetwork_HttpRequest_getHeaderNu00);
   tolua_function(tolua_S,"setData",tolua_FsLibNetwork_HttpRequest_setData00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_FsLibNetwork (lua_State* tolua_S) {
 return tolua_FsLibNetwork_open(tolua_S);
};
#endif

