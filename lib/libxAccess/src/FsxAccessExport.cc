/*
** Lua binding: FslibxAccess
** Generated automatically by tolua++-1.0.92 on 11/20/13 19:41:52.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_FslibxAccess_open (lua_State* tolua_S);

#include "FsxAccessExport.h"
#include "FsxAccessFuc.h"
#include"FsUpdateApk.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 toluaext_usertype(tolua_S,"UpdateApk");
 tolua_usertype(tolua_S,"FsObject");
}

/* function: f_BillingPointUp */
#ifndef TOLUA_DISABLE_tolua_FslibxAccess_f_BillingPointUp00
static int tolua_FslibxAccess_f_BillingPointUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* bpid = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* price = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   f_BillingPointUp(bpid,price);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'f_BillingPointUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: f_LogTalkingData */
#ifndef TOLUA_DISABLE_tolua_FslibxAccess_f_LogTalkingData00
static int tolua_FslibxAccess_f_LogTalkingData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* eventID = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* eventLabel = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   f_LogTalkingData(eventID,eventLabel);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'f_LogTalkingData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  UpdateApk */
#ifndef TOLUA_DISABLE_tolua_FslibxAccess_UpdateApk_create00
static int tolua_FslibxAccess_UpdateApk_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UpdateApk",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UpdateApk* tolua_ret = (UpdateApk*)  UpdateApk::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"UpdateApk");
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

/* method: checkUpdate of class  UpdateApk */
#ifndef TOLUA_DISABLE_tolua_FslibxAccess_UpdateApk_checkUpdate00
static int tolua_FslibxAccess_UpdateApk_checkUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UpdateApk",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UpdateApk* self = (UpdateApk*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkUpdate'", NULL);
#endif
  {
   self->checkUpdate();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_FslibxAccess_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_function(tolua_S,"f_BillingPointUp",tolua_FslibxAccess_f_BillingPointUp00);
  tolua_function(tolua_S,"f_LogTalkingData",tolua_FslibxAccess_f_LogTalkingData00);
  tolua_cclass(tolua_S,"UpdateApk","UpdateApk","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"UpdateApk");
   tolua_function(tolua_S,"create",tolua_FslibxAccess_UpdateApk_create00);
   tolua_function(tolua_S,"checkUpdate",tolua_FslibxAccess_UpdateApk_checkUpdate00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_FslibxAccess (lua_State* tolua_S) {
 return tolua_FslibxAccess_open(tolua_S);
};
#endif

