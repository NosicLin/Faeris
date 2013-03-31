/*
** Lua binding: FsFaeris
** Generated automatically by tolua++-1.0.92 on Sun Mar 31 21:36:58 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_FsFaeris_open (lua_State* tolua_S);

#include "FsLuaFaeris.h"
#include "common/FsGlobal.h"
#include "luaext/FsLuaTouchEventListener.h"
#include "luaext/FsLuaSysEventListener.h"
#include "event/FsTouchDispatcher.h"
#include "event/FsSysDispatcher.h"
#include "entity/FsEntity.h"
#include "luaext/FsLuaEntity.h"
#include "luaext/FsLuaEntity.h"
#include "entity/FsQuad2D.h"
#include "luaext/FsLuaEntity.h"
#include "entity/FsLabelTTF.h"
#include "scheduler/FsScheduler.h"
#include "luaext/FsLuaScene.h"
#include "scene/FsDirector.h"
#include "scene/FsLayer.h"
#include "luaext/FsLuaLayer.h"
#include "scene/FsLayer2D.h"
#include "luaext/FsLuaLayer.h"
#include "graphics/FsRender.h"
#include "graphics/FsColor.h"
#include "graphics/FsFontTTF.h"
#include "math/FsVector2.h"
#include "math/FsVector3.h"
#include "math/FsVector4.h"
#include "math/FsMatrix4.h"
#include "math/FsRect2D.h"
#include "sys/FsWindow.h"
#include "mgr/FsTextureMgr.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Vector4 (lua_State* tolua_S)
{
 Vector4* self = (Vector4*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vector2 (lua_State* tolua_S)
{
 Vector2* self = (Vector2*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Rect2D (lua_State* tolua_S)
{
 Rect2D* self = (Rect2D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Color (lua_State* tolua_S)
{
 Color* self = (Color*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Matrix4 (lua_State* tolua_S)
{
 Matrix4* self = (Matrix4*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vector3 (lua_State* tolua_S)
{
 Vector3* self = (Vector3*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"TextureMgr");
 tolua_usertype(tolua_S,"TouchEventListener");
 tolua_usertype(tolua_S,"FontTTF");
 tolua_usertype(tolua_S,"Scheduler");
 tolua_usertype(tolua_S,"Entity");
 tolua_usertype(tolua_S,"Vector3");
 tolua_usertype(tolua_S,"SchedulerTarget");
 tolua_usertype(tolua_S,"Director");
 tolua_usertype(tolua_S,"Scene");
 tolua_usertype(tolua_S,"Layer");
 tolua_usertype(tolua_S,"Texture2D");
 
 tolua_usertype(tolua_S,"LuaEntity");
 tolua_usertype(tolua_S,"LuaColorLayer");
 tolua_usertype(tolua_S,"Matrix4");
 tolua_usertype(tolua_S,"Render");
 tolua_usertype(tolua_S,"SysDispatcher");
 tolua_usertype(tolua_S,"Quad2D");
 tolua_usertype(tolua_S,"Color");
 tolua_usertype(tolua_S,"Window");
 tolua_usertype(tolua_S,"TouchDispatcher");
 tolua_usertype(tolua_S,"Layer2D");
 tolua_usertype(tolua_S,"LuaLayer2D");
 tolua_usertype(tolua_S,"FsObject");
 tolua_usertype(tolua_S,"ResourceMgr");
 tolua_usertype(tolua_S,"LuaScene");
 tolua_usertype(tolua_S,"FsArray");
 tolua_usertype(tolua_S,"Vector4");
 tolua_usertype(tolua_S,"Global");
 tolua_usertype(tolua_S,"Rect2D");
 tolua_usertype(tolua_S,"LuaColorQuad2D");
 tolua_usertype(tolua_S,"SysEventListener");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"LuaTouchEventListener");
 tolua_usertype(tolua_S,"LabelTTF");
 tolua_usertype(tolua_S,"LuaSysEventListener");
 tolua_usertype(tolua_S,"LuaQuad2D");
}

/* method: scheduler of class  Global */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_share_scheduler00
static int tolua_FsFaeris_share_scheduler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Global",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Scheduler* tolua_ret = (Scheduler*)  Global::scheduler();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Scheduler");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scheduler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchDispatcher of class  Global */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_share_touchDispatcher00
static int tolua_FsFaeris_share_touchDispatcher00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Global",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TouchDispatcher* tolua_ret = (TouchDispatcher*)  Global::touchDispatcher();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"TouchDispatcher");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchDispatcher'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: director of class  Global */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_share_director00
static int tolua_FsFaeris_share_director00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Global",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Director* tolua_ret = (Director*)  Global::director();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Director");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'director'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sysDispatcher of class  Global */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_share_sysDispatcher00
static int tolua_FsFaeris_share_sysDispatcher00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Global",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SysDispatcher* tolua_ret = (SysDispatcher*)  Global::sysDispatcher();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"SysDispatcher");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sysDispatcher'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: window of class  Global */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_share_window00
static int tolua_FsFaeris_share_window00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Global",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Window* tolua_ret = (Window*)  Global::window();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Window");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'window'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: render of class  Global */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_share_render00
static int tolua_FsFaeris_share_render00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Global",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Render* tolua_ret = (Render*)  Global::render();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Render");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'render'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: textureMgr of class  Global */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_share_textureMgr00
static int tolua_FsFaeris_share_textureMgr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Global",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TextureMgr* tolua_ret = (TextureMgr*)  Global::textureMgr();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"TextureMgr");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'textureMgr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: className of class  FsObject */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_FsObject_className00
static int tolua_FsFaeris_FsObject_className00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FsObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FsObject* self = (FsObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'className'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->className();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'className'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_data of class  FsObject */
#ifndef TOLUA_DISABLE_tolua_get_FsObject_data
static int tolua_get_FsObject_data(lua_State* tolua_S)
{
  FsObject* self = (FsObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_data'",NULL);
#endif
   toluaext_push_luatable(tolua_S,self->m_data);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_data of class  FsObject */
#ifndef TOLUA_DISABLE_tolua_set_FsObject_data
static int tolua_set_FsObject_data(lua_State* tolua_S)
{
  FsObject* self = (FsObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_data'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluaext_is_luatable(tolua_S,2,"LUA_TABLE",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  if(self->m_data!=-1) toluaext_remove_luatable(tolua_S,self->m_data); 
	self->m_data=toluaext_to_luatable(tolua_S,2,0)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaTouchEventListener */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_TouchEventListener_create00
static int tolua_FsFaeris_TouchEventListener_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaTouchEventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaTouchEventListener* tolua_ret = (LuaTouchEventListener*)  LuaTouchEventListener::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaTouchEventListener");
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

/* method: create of class  LuaSysEventListener */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SysEventListener_create00
static int tolua_FsFaeris_SysEventListener_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaSysEventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaSysEventListener* tolua_ret = (LuaSysEventListener*)  LuaSysEventListener::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaSysEventListener");
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

/* method: addEventListener of class  SysDispatcher */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SysDispatcher_addEventListener00
static int tolua_FsFaeris_SysDispatcher_addEventListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SysDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"SysEventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SysDispatcher* self = (SysDispatcher*)  tolua_tousertype(tolua_S,1,0);
  SysEventListener* l = ((SysEventListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addEventListener'", NULL);
#endif
  {
   self->addEventListener(l);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addEventListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeEventListener of class  SysDispatcher */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SysDispatcher_removeEventListener00
static int tolua_FsFaeris_SysDispatcher_removeEventListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SysDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"SysEventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SysDispatcher* self = (SysDispatcher*)  tolua_tousertype(tolua_S,1,0);
  SysEventListener* l = ((SysEventListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeEventListener'", NULL);
#endif
  {
   self->removeEventListener(l);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeEventListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addEventListener of class  TouchDispatcher */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_TouchDispatcher_addEventListener00
static int tolua_FsFaeris_TouchDispatcher_addEventListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TouchDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TouchEventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TouchDispatcher* self = (TouchDispatcher*)  tolua_tousertype(tolua_S,1,0);
  TouchEventListener* l = ((TouchEventListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addEventListener'", NULL);
#endif
  {
   self->addEventListener(l);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addEventListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeEventListener of class  TouchDispatcher */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_TouchDispatcher_removeEventListener00
static int tolua_FsFaeris_TouchDispatcher_removeEventListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TouchDispatcher",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TouchEventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TouchDispatcher* self = (TouchDispatcher*)  tolua_tousertype(tolua_S,1,0);
  TouchEventListener* l = ((TouchEventListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeEventListener'", NULL);
#endif
  {
   self->removeEventListener(l);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeEventListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: localToWorld of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_localToWorld00
static int tolua_FsFaeris___Entity_localToWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'localToWorld'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->localToWorld(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'localToWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: worldToLocal of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_worldToLocal00
static int tolua_FsFaeris___Entity_worldToLocal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'worldToLocal'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->worldToLocal(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'worldToLocal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addChild of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_addChild00
static int tolua_FsFaeris___Entity_addChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  Entity* n = ((Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addChild'", NULL);
#endif
  {
   self->addChild(n);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_remove00
static int tolua_FsFaeris___Entity_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  Entity* n = ((Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'", NULL);
#endif
  {
   self->remove(n);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: detach of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_detach00
static int tolua_FsFaeris___Entity_detach00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'detach'", NULL);
#endif
  {
   self->detach();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'detach'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: allChild of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_allChild00
static int tolua_FsFaeris___Entity_allChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'allChild'", NULL);
#endif
  {
   FsArray* tolua_ret = (FsArray*)  self->allChild();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"FsArray");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'allChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: childNu of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_childNu00
static int tolua_FsFaeris___Entity_childNu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'childNu'", NULL);
#endif
  {
   int tolua_ret = (int)  self->childNu();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'childNu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosition of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_getPosition00
static int tolua_FsFaeris___Entity_getPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosition'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getPosition();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScale of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_getScale00
static int tolua_FsFaeris___Entity_getScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScale'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getScale();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRotate of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_getRotate00
static int tolua_FsFaeris___Entity_getRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRotate'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getRotate();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_rotate00
static int tolua_FsFaeris___Entity_rotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotate'", NULL);
#endif
  {
   self->rotate(rx,ry,rz);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_rotateX00
static int tolua_FsFaeris___Entity_rotateX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateX'", NULL);
#endif
  {
   self->rotateX(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_rotateY00
static int tolua_FsFaeris___Entity_rotateY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateY'", NULL);
#endif
  {
   self->rotateY(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateZ of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_rotateZ00
static int tolua_FsFaeris___Entity_rotateZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateZ'", NULL);
#endif
  {
   self->rotateZ(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_scale00
static int tolua_FsFaeris___Entity_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float sx = ((float)  tolua_tonumber(tolua_S,2,0));
  float sy = ((float)  tolua_tonumber(tolua_S,3,0));
  float sz = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(sx,sy,sz);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scaleX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_scaleX00
static int tolua_FsFaeris___Entity_scaleX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleX'", NULL);
#endif
  {
   self->scaleX(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scaleX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scaleY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_scaleY00
static int tolua_FsFaeris___Entity_scaleY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleY'", NULL);
#endif
  {
   self->scaleY(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scaleY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scaleZ of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_scaleZ00
static int tolua_FsFaeris___Entity_scaleZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleZ'", NULL);
#endif
  {
   self->scaleZ(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scaleZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: move of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_move00
static int tolua_FsFaeris___Entity_move00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float tx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ty = ((float)  tolua_tonumber(tolua_S,3,0));
  float tz = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'move'", NULL);
#endif
  {
   self->move(tx,ty,tz);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'move'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_moveX00
static int tolua_FsFaeris___Entity_moveX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveX'", NULL);
#endif
  {
   self->moveX(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_moveY00
static int tolua_FsFaeris___Entity_moveY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveY'", NULL);
#endif
  {
   self->moveY(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveZ of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_moveZ00
static int tolua_FsFaeris___Entity_moveZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveZ'", NULL);
#endif
  {
   self->moveZ(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotate of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_setRotate00
static int tolua_FsFaeris___Entity_setRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotate'", NULL);
#endif
  {
   self->setRotate(rx,ry,rz);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotateX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_setRotateX00
static int tolua_FsFaeris___Entity_setRotateX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotateX'", NULL);
#endif
  {
   self->setRotateX(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotateX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotateY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_setRotateY00
static int tolua_FsFaeris___Entity_setRotateY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotateY'", NULL);
#endif
  {
   self->setRotateY(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotateY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotateZ of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_setRotateZ00
static int tolua_FsFaeris___Entity_setRotateZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotateZ'", NULL);
#endif
  {
   self->setRotateZ(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotateZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_setScale00
static int tolua_FsFaeris___Entity_setScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float sx = ((float)  tolua_tonumber(tolua_S,2,0));
  float sy = ((float)  tolua_tonumber(tolua_S,3,0));
  float sz = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'", NULL);
#endif
  {
   self->setScale(sx,sy,sz);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScaleX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_setScaleX00
static int tolua_FsFaeris___Entity_setScaleX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScaleX'", NULL);
#endif
  {
   self->setScaleX(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScaleX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScaleY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_setScaleY00
static int tolua_FsFaeris___Entity_setScaleY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScaleY'", NULL);
#endif
  {
   self->setScaleY(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScaleY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScaleZ of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_setScaleZ00
static int tolua_FsFaeris___Entity_setScaleZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScaleZ'", NULL);
#endif
  {
   self->setScaleZ(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScaleZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_setPosition00
static int tolua_FsFaeris___Entity_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float tx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ty = ((float)  tolua_tonumber(tolua_S,3,0));
  float tz = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   self->setPosition(tx,ty,tz);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPositionX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_setPositionX00
static int tolua_FsFaeris___Entity_setPositionX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPositionX'", NULL);
#endif
  {
   self->setPositionX(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPositionX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPositionY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_setPositionY00
static int tolua_FsFaeris___Entity_setPositionY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPositionY'", NULL);
#endif
  {
   self->setPositionY(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPositionY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPositionZ of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_setPositionZ00
static int tolua_FsFaeris___Entity_setPositionZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float t = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPositionZ'", NULL);
#endif
  {
   self->setPositionZ(t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPositionZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVisible of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_setVisible00
static int tolua_FsFaeris___Entity_setVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  bool visible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVisible'", NULL);
#endif
  {
   self->setVisible(visible);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visible of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Entity_visible00
static int tolua_FsFaeris___Entity_visible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visible'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->visible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaEntity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Entity_create00
static int tolua_FsFaeris_Entity_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaEntity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaEntity* tolua_ret = (LuaEntity*)  LuaEntity::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaEntity");
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

/* method: onUpdate of class  LuaEntity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Entity_onUpdate00
static int tolua_FsFaeris_Entity_onUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaEntity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaEntity* self = (LuaEntity*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onUpdate'", NULL);
#endif
  {
   self->onUpdate(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onDraw of class  LuaEntity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Entity_onDraw00
static int tolua_FsFaeris_Entity_onDraw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaEntity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaEntity* self = (LuaEntity*)  tolua_tousertype(tolua_S,1,0);
  Render* r = ((Render*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onDraw'", NULL);
#endif
  {
   self->onDraw(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onDraw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ColorQuad2D_create00
static int tolua_FsFaeris_ColorQuad2D_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaColorQuad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaColorQuad2D* tolua_ret = (LuaColorQuad2D*)  LuaColorQuad2D::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaColorQuad2D");
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

/* method: create of class  LuaColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ColorQuad2D_create01
static int tolua_FsFaeris_ColorQuad2D_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaColorQuad2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect2D",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Rect2D* rect = ((const Rect2D*)  tolua_tousertype(tolua_S,2,0));
  Color c = *((Color*)  tolua_tousertype(tolua_S,3,0));
  {
   LuaColorQuad2D* tolua_ret = (LuaColorQuad2D*)  LuaColorQuad2D::create(*rect,c);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaColorQuad2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_ColorQuad2D_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: onUpdate of class  LuaColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ColorQuad2D_onUpdate00
static int tolua_FsFaeris_ColorQuad2D_onUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorQuad2D* self = (LuaColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onUpdate'", NULL);
#endif
  {
   self->onUpdate(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onDraw of class  LuaColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ColorQuad2D_onDraw00
static int tolua_FsFaeris_ColorQuad2D_onDraw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorQuad2D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorQuad2D* self = (LuaColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
  Render* r = ((Render*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onDraw'", NULL);
#endif
  {
   self->onDraw(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onDraw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  LuaColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ColorQuad2D_setColor00
static int tolua_FsFaeris_ColorQuad2D_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorQuad2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorQuad2D* self = (LuaColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
  Color c = *((Color*)  tolua_tousertype(tolua_S,2,0));
  int vertex = ((int)  tolua_tonumber(tolua_S,3,LuaColorQuad2D::VERTEX_ALL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(c,vertex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRect of class  LuaColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ColorQuad2D_setRect00
static int tolua_FsFaeris_ColorQuad2D_setRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorQuad2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect2D",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorQuad2D* self = (LuaColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
  const Rect2D* rect = ((const Rect2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRect'", NULL);
#endif
  {
   self->setRect(*rect);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOpacity of class  LuaColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ColorQuad2D_setOpacity00
static int tolua_FsFaeris_ColorQuad2D_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorQuad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorQuad2D* self = (LuaColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
  float opacity = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOpacity'", NULL);
#endif
  {
   self->setOpacity(opacity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOpacity of class  LuaColorQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ColorQuad2D_getOpacity00
static int tolua_FsFaeris_ColorQuad2D_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorQuad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorQuad2D* self = (LuaColorQuad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOpacity'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getOpacity();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Quad2D_create00
static int tolua_FsFaeris___Quad2D_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* tex = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Quad2D* tolua_ret = (Quad2D*)  Quad2D::create(tex);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Quad2D");
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

/* method: setColor of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Quad2D_setColor00
static int tolua_FsFaeris___Quad2D_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
  Color c = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColor of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Quad2D_getColor00
static int tolua_FsFaeris___Quad2D_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->getColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOpacity of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Quad2D_setOpacity00
static int tolua_FsFaeris___Quad2D_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
  float opacity = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOpacity'", NULL);
#endif
  {
   self->setOpacity(opacity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOpacity of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Quad2D_getOpacity00
static int tolua_FsFaeris___Quad2D_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOpacity'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getOpacity();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTexture of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Quad2D_setTexture00
static int tolua_FsFaeris___Quad2D_setTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
  Texture2D* tex = ((Texture2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTexture'", NULL);
#endif
  {
   self->setTexture(tex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTexture of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Quad2D_getTexture00
static int tolua_FsFaeris___Quad2D_getTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTexture'", NULL);
#endif
  {
   Texture2D* tolua_ret = (Texture2D*)  self->getTexture();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Texture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTextureCoord of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Quad2D_setTextureCoord00
static int tolua_FsFaeris___Quad2D_setTextureCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect2D",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
  const Rect2D* coord = ((const Rect2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTextureCoord'", NULL);
#endif
  {
   self->setTextureCoord(*coord);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTextureCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTextureCoord of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Quad2D_getTextureCoord00
static int tolua_FsFaeris___Quad2D_getTextureCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTextureCoord'", NULL);
#endif
  {
   Rect2D tolua_ret = (Rect2D)  self->getTextureCoord();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Rect2D)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Rect2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Rect2D));
     tolua_pushusertype(tolua_S,tolua_obj,"Rect2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTextureCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRect2D of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Quad2D_setRect2D00
static int tolua_FsFaeris___Quad2D_setRect2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect2D",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
  const Rect2D* rect = ((const Rect2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRect2D'", NULL);
#endif
  {
   self->setRect2D(*rect);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRect2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRect2D of class  Quad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Quad2D_getRect2D00
static int tolua_FsFaeris___Quad2D_getRect2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quad2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quad2D* self = (Quad2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRect2D'", NULL);
#endif
  {
   Rect2D tolua_ret = (Rect2D)  self->getRect2D();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Rect2D)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Rect2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Rect2D));
     tolua_pushusertype(tolua_S,tolua_obj,"Rect2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRect2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaQuad2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Quad2D_create00
static int tolua_FsFaeris_Quad2D_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaQuad2D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* tex = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   LuaQuad2D* tolua_ret = (LuaQuad2D*)  LuaQuad2D::create(tex);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaQuad2D");
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

/* method: create of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_LabelTTF_create00
static int tolua_FsFaeris_LabelTTF_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"FontTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
  FontTTF* font = ((FontTTF*)  tolua_tousertype(tolua_S,3,0));
  {
   LabelTTF* tolua_ret = (LabelTTF*)  LabelTTF::create(text,font);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LabelTTF");
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

/* method: setString of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_LabelTTF_setString00
static int tolua_FsFaeris_LabelTTF_setString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setString'", NULL);
#endif
  {
   self->setString(str);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getString of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_LabelTTF_getString00
static int tolua_FsFaeris_LabelTTF_getString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getString'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getString();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFont of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_LabelTTF_setFont00
static int tolua_FsFaeris_LabelTTF_setFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FontTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
  FontTTF* font = ((FontTTF*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFont'", NULL);
#endif
  {
   self->setFont(font);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFont of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_LabelTTF_getFont00
static int tolua_FsFaeris_LabelTTF_getFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFont'", NULL);
#endif
  {
   FontTTF* tolua_ret = (FontTTF*)  self->getFont();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"FontTTF");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAlign of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_LabelTTF_setAlign00
static int tolua_FsFaeris_LabelTTF_setAlign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
  int h = ((int)  tolua_tonumber(tolua_S,2,0));
  int v = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlign'", NULL);
#endif
  {
   self->setAlign(h,v);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAlign of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_LabelTTF_getAlign00
static int tolua_FsFaeris_LabelTTF_getAlign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
  int h = ((int)  tolua_tonumber(tolua_S,2,NULL));
  int v = ((int)  tolua_tonumber(tolua_S,3,NULL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAlign'", NULL);
#endif
  {
   self->getAlign(&h,&v);
   tolua_pushnumber(tolua_S,(lua_Number)h);
   tolua_pushnumber(tolua_S,(lua_Number)v);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAlign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_LabelTTF_setColor00
static int tolua_FsFaeris_LabelTTF_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
  Color c = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColor of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_LabelTTF_getColor00
static int tolua_FsFaeris_LabelTTF_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->getColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOpacity of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_LabelTTF_setOpacity00
static int tolua_FsFaeris_LabelTTF_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
  float opacity = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOpacity'", NULL);
#endif
  {
   self->setOpacity(opacity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOpacity of class  LabelTTF */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_LabelTTF_getOpacity00
static int tolua_FsFaeris_LabelTTF_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LabelTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LabelTTF* self = (LabelTTF*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOpacity'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getOpacity();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  Scheduler */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scheduler_create00
static int tolua_FsFaeris_Scheduler_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Scheduler",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Scheduler* tolua_ret = (Scheduler*)  Scheduler::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Scheduler");
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

/* method: className of class  Scheduler */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scheduler_className00
static int tolua_FsFaeris_Scheduler_className00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scheduler",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scheduler* self = (Scheduler*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'className'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->className();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'className'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  Scheduler */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scheduler_start00
static int tolua_FsFaeris_Scheduler_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scheduler",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scheduler* self = (Scheduler*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'", NULL);
#endif
  {
   self->start();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stop of class  Scheduler */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scheduler_stop00
static int tolua_FsFaeris_Scheduler_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scheduler",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scheduler* self = (Scheduler*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setFps of class  Scheduler */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scheduler_setFps00
static int tolua_FsFaeris_Scheduler_setFps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scheduler",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scheduler* self = (Scheduler*)  tolua_tousertype(tolua_S,1,0);
  int fps = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFps'", NULL);
#endif
  {
   self->setFps(fps);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFps'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mainLoop of class  Scheduler */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scheduler_mainLoop00
static int tolua_FsFaeris_Scheduler_mainLoop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scheduler",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scheduler* self = (Scheduler*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mainLoop'", NULL);
#endif
  {
   self->mainLoop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mainLoop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Scheduler */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scheduler_add00
static int tolua_FsFaeris_Scheduler_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scheduler",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"SchedulerTarget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scheduler* self = (Scheduler*)  tolua_tousertype(tolua_S,1,0);
  SchedulerTarget* s = ((SchedulerTarget*)  tolua_tousertype(tolua_S,2,0));
  int priority = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'", NULL);
#endif
  {
   self->add(s,priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  Scheduler */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scheduler_remove00
static int tolua_FsFaeris_Scheduler_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scheduler",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"SchedulerTarget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scheduler* self = (Scheduler*)  tolua_tousertype(tolua_S,1,0);
  SchedulerTarget* s = ((SchedulerTarget*)  tolua_tousertype(tolua_S,2,0));
  int priority = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'", NULL);
#endif
  {
   self->remove(s,priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scene_create00
static int tolua_FsFaeris_Scene_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaScene* tolua_ret = (LuaScene*)  LuaScene::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaScene");
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

/* method: push of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scene_push00
static int tolua_FsFaeris_Scene_push00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  Layer* layer = ((Layer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'push'", NULL);
#endif
  {
   self->push(layer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'push'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pop of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scene_pop00
static int tolua_FsFaeris_Scene_pop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pop'", NULL);
#endif
  {
   self->pop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: insert of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scene_insert00
static int tolua_FsFaeris_Scene_insert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  int pos = ((int)  tolua_tonumber(tolua_S,2,0));
  Layer* layer = ((Layer*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'insert'", NULL);
#endif
  {
   self->insert(pos,layer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'insert'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: replace of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scene_replace00
static int tolua_FsFaeris_Scene_replace00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  int pos = ((int)  tolua_tonumber(tolua_S,2,0));
  Layer* layer = ((Layer*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'replace'", NULL);
#endif
  {
   self->replace(pos,layer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'replace'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scene_remove00
static int tolua_FsFaeris_Scene_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  Layer* layer = ((Layer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'", NULL);
#endif
  {
   self->remove(layer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onEnter of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scene_enter00
static int tolua_FsFaeris_Scene_enter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onEnter'", NULL);
#endif
  {
   self->onEnter();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onExit of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scene_exit00
static int tolua_FsFaeris_Scene_exit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onExit'", NULL);
#endif
  {
   self->onExit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'exit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onUpdate of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scene_update00
static int tolua_FsFaeris_Scene_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onUpdate'", NULL);
#endif
  {
   self->onUpdate(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onDraw of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scene_draw00
static int tolua_FsFaeris_Scene_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  Render* render = ((Render*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onDraw'", NULL);
#endif
  {
   self->onDraw(render);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchBegin of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scene_touchBegin00
static int tolua_FsFaeris_Scene_touchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchBegin'", NULL);
#endif
  {
   self->onTouchBegin(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchBegin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchEnd of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scene_touchEnd00
static int tolua_FsFaeris_Scene_touchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchEnd'", NULL);
#endif
  {
   self->onTouchEnd(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchEnd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchMove of class  LuaScene */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Scene_touchMove00
static int tolua_FsFaeris_Scene_touchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaScene",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaScene* self = (LuaScene*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchMove'", NULL);
#endif
  {
   self->onTouchMove(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchMove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: push of class  Director */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Director_push00
static int tolua_FsFaeris_Director_push00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Director",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Director* self = (Director*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'push'", NULL);
#endif
  {
   self->push();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'push'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pop of class  Director */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Director_pop00
static int tolua_FsFaeris_Director_pop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Director",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Director* self = (Director*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pop'", NULL);
#endif
  {
   self->pop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: run of class  Director */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Director_run00
static int tolua_FsFaeris_Director_run00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Director",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Director* self = (Director*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'run'", NULL);
#endif
  {
   self->run(scene);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'run'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pause of class  Director */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Director_pause00
static int tolua_FsFaeris_Director_pause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Director",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Director* self = (Director*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pause'", NULL);
#endif
  {
   self->pause();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pause'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  Director */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Director_start00
static int tolua_FsFaeris_Director_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Director",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Director* self = (Director*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'", NULL);
#endif
  {
   self->start();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isRunning of class  Director */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Director_isRunning00
static int tolua_FsFaeris_Director_isRunning00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Director",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Director* self = (Director*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isRunning'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isRunning();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isRunning'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visible of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Layer_visible00
static int tolua_FsFaeris_Layer_visible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visible'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->visible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVisible of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Layer_setVisible00
static int tolua_FsFaeris_Layer_setVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
  bool visible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVisible'", NULL);
#endif
  {
   self->setVisible(visible);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchEnabled of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Layer_touchEnabled00
static int tolua_FsFaeris_Layer_touchEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchEnabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->touchEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTouchEnabled of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Layer_setTouchEnabled00
static int tolua_FsFaeris_Layer_setTouchEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTouchEnabled'", NULL);
#endif
  {
   self->setTouchEnabled(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTouchEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Layer_add00
static int tolua_FsFaeris_Layer_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
  Entity* entity = ((Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'", NULL);
#endif
  {
   self->add(entity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  Layer */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Layer_remove00
static int tolua_FsFaeris_Layer_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer* self = (Layer*)  tolua_tousertype(tolua_S,1,0);
  Entity* entity = ((Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'", NULL);
#endif
  {
   self->remove(entity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaColorLayer */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ColorLayer_create00
static int tolua_FsFaeris_ColorLayer_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaColorLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaColorLayer* tolua_ret = (LuaColorLayer*)  LuaColorLayer::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"LuaColorLayer");
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

/* method: setColor of class  LuaColorLayer */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ColorLayer_setColor00
static int tolua_FsFaeris_ColorLayer_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorLayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorLayer* self = (LuaColorLayer*)  tolua_tousertype(tolua_S,1,0);
  Color c = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColor of class  LuaColorLayer */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ColorLayer_getColor00
static int tolua_FsFaeris_ColorLayer_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorLayer* self = (LuaColorLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->getColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onUpdate of class  LuaColorLayer */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ColorLayer_onUpdate00
static int tolua_FsFaeris_ColorLayer_onUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorLayer* self = (LuaColorLayer*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onUpdate'", NULL);
#endif
  {
   self->onUpdate(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onDraw of class  LuaColorLayer */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ColorLayer_onDraw00
static int tolua_FsFaeris_ColorLayer_onDraw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorLayer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorLayer* self = (LuaColorLayer*)  tolua_tousertype(tolua_S,1,0);
  Render* render = ((Render*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onDraw'", NULL);
#endif
  {
   self->onDraw(render);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onDraw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchBegin of class  LuaColorLayer */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ColorLayer_onTouchBegin00
static int tolua_FsFaeris_ColorLayer_onTouchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorLayer* self = (LuaColorLayer*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchBegin'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->onTouchBegin(x,y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onTouchBegin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchEnd of class  LuaColorLayer */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ColorLayer_onTouchEnd00
static int tolua_FsFaeris_ColorLayer_onTouchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorLayer* self = (LuaColorLayer*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchEnd'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->onTouchEnd(x,y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onTouchEnd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchMove of class  LuaColorLayer */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ColorLayer_onTouchMove00
static int tolua_FsFaeris_ColorLayer_onTouchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaColorLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaColorLayer* self = (LuaColorLayer*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchMove'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->onTouchMove(x,y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onTouchMove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getProjectMatrix of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Layer2D_getProjectMatrix00
static int tolua_FsFaeris___Layer2D_getProjectMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Layer2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Layer2D* self = (const Layer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProjectMatrix'", NULL);
#endif
  {
   Matrix4 tolua_ret = (Matrix4)  self->getProjectMatrix();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProjectMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewArea of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Layer2D_getViewArea00
static int tolua_FsFaeris___Layer2D_getViewArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Layer2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Layer2D* self = (const Layer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewArea'", NULL);
#endif
  {
   Rect2D tolua_ret = (Rect2D)  self->getViewArea();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Rect2D)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Rect2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Rect2D));
     tolua_pushusertype(tolua_S,tolua_obj,"Rect2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getViewArea'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toLayerCoord of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Layer2D_toLayerCoord00
static int tolua_FsFaeris___Layer2D_toLayerCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Layer2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Layer2D* self = (const Layer2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toLayerCoord'", NULL);
#endif
  {
   self->toLayerCoord(&x,&y);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toLayerCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toLayerCoord of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Layer2D_toLayerCoord01
static int tolua_FsFaeris___Layer2D_toLayerCoord01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Layer2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Layer2D* self = (const Layer2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toLayerCoord'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->toLayerCoord(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris___Layer2D_toLayerCoord00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setViewArea of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Layer2D_setViewArea00
static int tolua_FsFaeris___Layer2D_setViewArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer2D* self = (Layer2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setViewArea'", NULL);
#endif
  {
   self->setViewArea(x,y,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setViewArea'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setViewArea of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Layer2D_setViewArea01
static int tolua_FsFaeris___Layer2D_setViewArea01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect2D",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Layer2D* self = (Layer2D*)  tolua_tousertype(tolua_S,1,0);
  const Rect2D* area = ((const Rect2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setViewArea'", NULL);
#endif
  {
   self->setViewArea(*area);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsFaeris___Layer2D_setViewArea00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSortMode of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Layer2D_setSortMode00
static int tolua_FsFaeris___Layer2D_setSortMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer2D* self = (Layer2D*)  tolua_tousertype(tolua_S,1,0);
  int mode = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSortMode'", NULL);
#endif
  {
   self->setSortMode(mode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSortMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSortMode of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Layer2D_getSortMode00
static int tolua_FsFaeris___Layer2D_getSortMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer2D* self = (Layer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSortMode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getSortMode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSortMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOlderMode of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Layer2D_setOlderMode00
static int tolua_FsFaeris___Layer2D_setOlderMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer2D* self = (Layer2D*)  tolua_tousertype(tolua_S,1,0);
  int older = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOlderMode'", NULL);
#endif
  {
   self->setOlderMode(older);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOlderMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOlderMode of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Layer2D_getOlderMode00
static int tolua_FsFaeris___Layer2D_getOlderMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer2D* self = (Layer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOlderMode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getOlderMode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOlderMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEliminate of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Layer2D_setEliminate00
static int tolua_FsFaeris___Layer2D_setEliminate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer2D",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer2D* self = (Layer2D*)  tolua_tousertype(tolua_S,1,0);
  bool eliminate = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEliminate'", NULL);
#endif
  {
   self->setEliminate(eliminate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEliminate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEliminate of class  Layer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris___Layer2D_getEliminate00
static int tolua_FsFaeris___Layer2D_getEliminate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Layer2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Layer2D* self = (Layer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEliminate'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getEliminate();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEliminate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaLayer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Layer2D_create00
static int tolua_FsFaeris_Layer2D_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaLayer2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Layer2D* tolua_ret = (Layer2D*)  LuaLayer2D::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"Layer2D");
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

/* method: onUpdate of class  LuaLayer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Layer2D_onUpdate00
static int tolua_FsFaeris_Layer2D_onUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLayer2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLayer2D* self = (LuaLayer2D*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onUpdate'", NULL);
#endif
  {
   self->onUpdate(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onDraw of class  LuaLayer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Layer2D_onDraw00
static int tolua_FsFaeris_Layer2D_onDraw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLayer2D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLayer2D* self = (LuaLayer2D*)  tolua_tousertype(tolua_S,1,0);
  Render* render = ((Render*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onDraw'", NULL);
#endif
  {
   self->onDraw(render);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onDraw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchBegin of class  LuaLayer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Layer2D_onTouchBegin00
static int tolua_FsFaeris_Layer2D_onTouchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLayer2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLayer2D* self = (LuaLayer2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchBegin'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->onTouchBegin(x,y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onTouchBegin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchEnd of class  LuaLayer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Layer2D_onTouchEnd00
static int tolua_FsFaeris_Layer2D_onTouchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLayer2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLayer2D* self = (LuaLayer2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchEnd'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->onTouchEnd(x,y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onTouchEnd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTouchMove of class  LuaLayer2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Layer2D_onTouchMove00
static int tolua_FsFaeris_Layer2D_onTouchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaLayer2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaLayer2D* self = (LuaLayer2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTouchMove'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->onTouchMove(x,y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onTouchMove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setViewport of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_setViewport00
static int tolua_FsFaeris_Render_setViewport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setViewport'", NULL);
#endif
  {
   self->setViewport(x,y,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setViewport'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setClearColor of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_setClearColor00
static int tolua_FsFaeris_Render_setClearColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  Color c = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setClearColor'", NULL);
#endif
  {
   self->setClearColor(c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setClearColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setProjectionMatrix of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_setProjectionMatrix00
static int tolua_FsFaeris_Render_setProjectionMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* mat = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProjectionMatrix'", NULL);
#endif
  {
   self->setProjectionMatrix(*mat);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setProjectionMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pushMatrix of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_pushMatrix00
static int tolua_FsFaeris_Render_pushMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushMatrix'", NULL);
#endif
  {
   self->pushMatrix();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: popMatrix of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_popMatrix00
static int tolua_FsFaeris_Render_popMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'popMatrix'", NULL);
#endif
  {
   self->popMatrix();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'popMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadIdentity of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_loadIdentity00
static int tolua_FsFaeris_Render_loadIdentity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadIdentity'", NULL);
#endif
  {
   self->loadIdentity();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mulMatrix of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_mulMatrix00
static int tolua_FsFaeris_Render_mulMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mulMatrix'", NULL);
#endif
  {
   self->mulMatrix(*m);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mulMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMatrix of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_setMatrix00
static int tolua_FsFaeris_Render_setMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMatrix'", NULL);
#endif
  {
   self->setMatrix(*m);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: translate of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_translate00
static int tolua_FsFaeris_Render_translate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* t = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translate'", NULL);
#endif
  {
   self->translate(*t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'translate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_scale00
static int tolua_FsFaeris_Render_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* s = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(*s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_rotate00
static int tolua_FsFaeris_Render_rotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotate'", NULL);
#endif
  {
   self->rotate(*v,angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: drawLine of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_drawLine00
static int tolua_FsFaeris_Render_drawLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  const Vector3 start = *((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3 end = *((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  Color c = *((Color*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'drawLine'", NULL);
#endif
  {
   self->drawLine(start,end,width,c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'drawLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_COLOR of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_DEFAULT_COLOR
static int tolua_get_Color_DEFAULT_COLOR(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Color::DEFAULT_COLOR,"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: DEFAULT_COLOR of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_DEFAULT_COLOR
static int tolua_set_Color_DEFAULT_COLOR(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Color::DEFAULT_COLOR = *((Color*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: RED of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_RED
static int tolua_get_Color_RED(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Color::RED,"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: RED of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_RED
static int tolua_set_Color_RED(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Color::RED = *((Color*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: BLUE of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_BLUE
static int tolua_get_Color_BLUE(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Color::BLUE,"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: BLUE of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_BLUE
static int tolua_set_Color_BLUE(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Color::BLUE = *((Color*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: GREEN of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_GREEN
static int tolua_get_Color_GREEN(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Color::GREEN,"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: GREEN of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_GREEN
static int tolua_set_Color_GREEN(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Color::GREEN = *((Color*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WHITE of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_WHITE
static int tolua_get_Color_WHITE(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Color::WHITE,"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WHITE of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_WHITE
static int tolua_set_Color_WHITE(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Color::WHITE = *((Color*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: BLACK of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_BLACK
static int tolua_get_Color_BLACK(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Color::BLACK,"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: BLACK of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_BLACK
static int tolua_set_Color_BLACK(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Color::BLACK = *((Color*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: r of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_unsigned_r
static int tolua_get_Color_unsigned_r(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->r);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: r of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_unsigned_r
static int tolua_set_Color_unsigned_r(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->r = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: g of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_unsigned_g
static int tolua_get_Color_unsigned_g(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->g);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: g of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_unsigned_g
static int tolua_set_Color_unsigned_g(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->g = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: b of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_unsigned_b
static int tolua_get_Color_unsigned_b(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->b);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: b of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_unsigned_b
static int tolua_set_Color_unsigned_b(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->b = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: a of class  Color */
#ifndef TOLUA_DISABLE_tolua_get_Color_unsigned_a
static int tolua_get_Color_unsigned_a(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->a);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: a of class  Color */
#ifndef TOLUA_DISABLE_tolua_set_Color_unsigned_a
static int tolua_set_Color_unsigned_a(lua_State* tolua_S)
{
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->a = ((unsigned char)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Color_new00
static int tolua_FsFaeris_Color_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned char red = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
  unsigned char green = ((unsigned char)  tolua_tonumber(tolua_S,3,0));
  unsigned char blue = ((unsigned char)  tolua_tonumber(tolua_S,4,0));
  unsigned char alpha = ((unsigned char)  tolua_tonumber(tolua_S,5,0));
  {
   Color* tolua_ret = (Color*)  Mtolua_new((Color)(red,green,blue,alpha));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Color_new00_local
static int tolua_FsFaeris_Color_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned char red = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
  unsigned char green = ((unsigned char)  tolua_tonumber(tolua_S,3,0));
  unsigned char blue = ((unsigned char)  tolua_tonumber(tolua_S,4,0));
  unsigned char alpha = ((unsigned char)  tolua_tonumber(tolua_S,5,0));
  {
   Color* tolua_ret = (Color*)  Mtolua_new((Color)(red,green,blue,alpha));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Color_new01
static int tolua_FsFaeris_Color_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Color* tolua_ret = (Color*)  Mtolua_new((Color)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Color_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Color_new01_local
static int tolua_FsFaeris_Color_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Color* tolua_ret = (Color*)  Mtolua_new((Color)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Color_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Color_new02
static int tolua_FsFaeris_Color_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  unsigned char red = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
  unsigned char green = ((unsigned char)  tolua_tonumber(tolua_S,3,0));
  unsigned char blue = ((unsigned char)  tolua_tonumber(tolua_S,4,0));
  {
   Color* tolua_ret = (Color*)  Mtolua_new((Color)(red,green,blue));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Color_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Color_new02_local
static int tolua_FsFaeris_Color_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Color",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  unsigned char red = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
  unsigned char green = ((unsigned char)  tolua_tonumber(tolua_S,3,0));
  unsigned char blue = ((unsigned char)  tolua_tonumber(tolua_S,4,0));
  {
   Color* tolua_ret = (Color*)  Mtolua_new((Color)(red,green,blue));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Color_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Color__add00
static int tolua_FsFaeris_Color__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Color",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
  Color right = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->operator+(right);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Color__sub00
static int tolua_FsFaeris_Color__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Color",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
  Color right = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->operator-(right);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Color__mul00
static int tolua_FsFaeris_Color__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Color",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->operator*(s);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Color)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
     tolua_pushusertype(tolua_S,tolua_obj,"Color");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Color */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Color__eq00
static int tolua_FsFaeris_Color__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Color",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Color* self = (Color*)  tolua_tousertype(tolua_S,1,0);
  Color right = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(right);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  FontTTF */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_FontTTF_create00
static int tolua_FsFaeris_FontTTF_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FontTTF",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int size = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   FontTTF* tolua_ret = (FontTTF*)  FontTTF::create(name,size);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"FontTTF");
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

/* method: getHeight of class  FontTTF */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_FontTTF_getHeight00
static int tolua_FsFaeris_FontTTF_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FontTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FontTTF* self = (FontTTF*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAscend of class  FontTTF */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_FontTTF_getAscend00
static int tolua_FsFaeris_FontTTF_getAscend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FontTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FontTTF* self = (FontTTF*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAscend'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getAscend();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAscend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDescend of class  FontTTF */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_FontTTF_getDescend00
static int tolua_FsFaeris_FontTTF_getDescend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FontTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FontTTF* self = (FontTTF*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDescend'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getDescend();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDescend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_x
static int tolua_get_Vector2_x(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_set_Vector2_x
static int tolua_set_Vector2_x(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_y
static int tolua_get_Vector2_y(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_set_Vector2_y
static int tolua_set_Vector2_y(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector2_new00
static int tolua_FsFaeris_Vector2_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float fx = ((float)  tolua_tonumber(tolua_S,2,0));
  float fy = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)(fx,fy));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector2_new00_local
static int tolua_FsFaeris_Vector2_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float fx = ((float)  tolua_tonumber(tolua_S,2,0));
  float fy = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)(fx,fy));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector2_new01
static int tolua_FsFaeris_Vector2_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Vector2_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector2_new01_local
static int tolua_FsFaeris_Vector2_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Vector2_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector2_add00
static int tolua_FsFaeris_Vector2_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->add(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector2_sub00
static int tolua_FsFaeris_Vector2_sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sub'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->sub(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector2_scale00
static int tolua_FsFaeris_Vector2_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  float k = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->scale(k);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dot of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector2_dot00
static int tolua_FsFaeris_Vector2_dot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dot'", NULL);
#endif
  {
   float tolua_ret = (float)  self->dot(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normal of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector2_normal00
static int tolua_FsFaeris_Vector2_normal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normal'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->normal();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector2_normalize00
static int tolua_FsFaeris_Vector2_normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   self->normalize();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: proj of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector2_proj00
static int tolua_FsFaeris_Vector2_proj00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'proj'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->proj(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'proj'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: angle of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector2_angle00
static int tolua_FsFaeris_Vector2_angle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'angle'", NULL);
#endif
  {
   float tolua_ret = (float)  self->angle(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'angle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector2_length00
static int tolua_FsFaeris_Vector2_length00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length2 of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector2_length200
static int tolua_FsFaeris_Vector2_length200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length2'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length2();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equal of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector2_equal00
static int tolua_FsFaeris_Vector2_equal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equal'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equal(*v);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_x
static int tolua_get_Vector3_x(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_set_Vector3_x
static int tolua_set_Vector3_x(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_y
static int tolua_get_Vector3_y(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_set_Vector3_y
static int tolua_set_Vector3_y(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: z of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_z
static int tolua_get_Vector3_z(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_set_Vector3_z
static int tolua_set_Vector3_z(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector3_new00
static int tolua_FsFaeris_Vector3_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(x,y,z));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector3_new00_local
static int tolua_FsFaeris_Vector3_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(x,y,z));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector3_new01
static int tolua_FsFaeris_Vector3_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Vector3_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector3_new01_local
static int tolua_FsFaeris_Vector3_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Vector3_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector3_add00
static int tolua_FsFaeris_Vector3_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->add(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector3_sub00
static int tolua_FsFaeris_Vector3_sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sub'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->sub(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector3_scale00
static int tolua_FsFaeris_Vector3_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  float k = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->scale(k);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dot of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector3_dot00
static int tolua_FsFaeris_Vector3_dot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dot'", NULL);
#endif
  {
   float tolua_ret = (float)  self->dot(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cross of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector3_cross00
static int tolua_FsFaeris_Vector3_cross00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cross'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->cross(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cross'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normal of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector3_normal00
static int tolua_FsFaeris_Vector3_normal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normal'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->normal();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector3_normalize00
static int tolua_FsFaeris_Vector3_normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   self->normalize();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: proj of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector3_proj00
static int tolua_FsFaeris_Vector3_proj00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'proj'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->proj(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'proj'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: angle of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector3_angle00
static int tolua_FsFaeris_Vector3_angle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'angle'", NULL);
#endif
  {
   float tolua_ret = (float)  self->angle(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'angle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector3_length00
static int tolua_FsFaeris_Vector3_length00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length2 of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector3_length200
static int tolua_FsFaeris_Vector3_length200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length2'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length2();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equal of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector3_equal00
static int tolua_FsFaeris_Vector3_equal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equal'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equal(*v);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector3_set00
static int tolua_FsFaeris_Vector3_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_x
static int tolua_get_Vector4_x(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_set_Vector4_x
static int tolua_set_Vector4_x(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_y
static int tolua_get_Vector4_y(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_set_Vector4_y
static int tolua_set_Vector4_y(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: z of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_z
static int tolua_get_Vector4_z(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_set_Vector4_z
static int tolua_set_Vector4_z(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: w of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_w
static int tolua_get_Vector4_w(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->w);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: w of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_set_Vector4_w
static int tolua_set_Vector4_w(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->w = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector4_new00
static int tolua_FsFaeris_Vector4_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float fx = ((float)  tolua_tonumber(tolua_S,2,0));
  float fy = ((float)  tolua_tonumber(tolua_S,3,0));
  float fz = ((float)  tolua_tonumber(tolua_S,4,0));
  float fw = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(fx,fy,fz,fw));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector4_new00_local
static int tolua_FsFaeris_Vector4_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float fx = ((float)  tolua_tonumber(tolua_S,2,0));
  float fy = ((float)  tolua_tonumber(tolua_S,3,0));
  float fz = ((float)  tolua_tonumber(tolua_S,4,0));
  float fw = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(fx,fy,fz,fw));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector4_new01
static int tolua_FsFaeris_Vector4_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float fx = ((float)  tolua_tonumber(tolua_S,2,0));
  float fy = ((float)  tolua_tonumber(tolua_S,3,0));
  float fz = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(fx,fy,fz));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Vector4_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector4_new01_local
static int tolua_FsFaeris_Vector4_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float fx = ((float)  tolua_tonumber(tolua_S,2,0));
  float fy = ((float)  tolua_tonumber(tolua_S,3,0));
  float fz = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(fx,fy,fz));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Vector4_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector4_new02
static int tolua_FsFaeris_Vector4_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Vector4_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector4_new02_local
static int tolua_FsFaeris_Vector4_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Vector4_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector4_add00
static int tolua_FsFaeris_Vector4_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->add(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector4_sub00
static int tolua_FsFaeris_Vector4_sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sub'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->sub(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector4_scale00
static int tolua_FsFaeris_Vector4_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  float k = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->scale(k);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dot of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector4_dot00
static int tolua_FsFaeris_Vector4_dot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dot'", NULL);
#endif
  {
   float tolua_ret = (float)  self->dot(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normal of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector4_normal00
static int tolua_FsFaeris_Vector4_normal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normal'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->normal();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector4_normalize00
static int tolua_FsFaeris_Vector4_normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   self->normalize();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector4_length00
static int tolua_FsFaeris_Vector4_length00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length2 of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector4_length200
static int tolua_FsFaeris_Vector4_length200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length2'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length2();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equal of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Vector4_equal00
static int tolua_FsFaeris_Vector4_equal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equal'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equal(*v);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_new00
static int tolua_FsFaeris_Matrix4_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_new00_local
static int tolua_FsFaeris_Matrix4_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_new01
static int tolua_FsFaeris_Matrix4_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float v[16];
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isnumberarray(tolua_S,2,16,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<16;i++)
    v[i] = ((float)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(v));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Matrix4_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_new01_local
static int tolua_FsFaeris_Matrix4_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float v[16];
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isnumberarray(tolua_S,2,16,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<16;i++)
    v[i] = ((float)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(v));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Matrix4_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_new02
static int tolua_FsFaeris_Matrix4_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,12,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,13,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,14,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,15,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,16,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,17,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,18,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float v00 = ((float)  tolua_tonumber(tolua_S,2,0));
  float v01 = ((float)  tolua_tonumber(tolua_S,3,0));
  float v02 = ((float)  tolua_tonumber(tolua_S,4,0));
  float v03 = ((float)  tolua_tonumber(tolua_S,5,0));
  float v10 = ((float)  tolua_tonumber(tolua_S,6,0));
  float v11 = ((float)  tolua_tonumber(tolua_S,7,0));
  float v12 = ((float)  tolua_tonumber(tolua_S,8,0));
  float v13 = ((float)  tolua_tonumber(tolua_S,9,0));
  float v20 = ((float)  tolua_tonumber(tolua_S,10,0));
  float v21 = ((float)  tolua_tonumber(tolua_S,11,0));
  float v22 = ((float)  tolua_tonumber(tolua_S,12,0));
  float v23 = ((float)  tolua_tonumber(tolua_S,13,0));
  float v30 = ((float)  tolua_tonumber(tolua_S,14,0));
  float v31 = ((float)  tolua_tonumber(tolua_S,15,0));
  float v32 = ((float)  tolua_tonumber(tolua_S,16,0));
  float v33 = ((float)  tolua_tonumber(tolua_S,17,0));
  {
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(v00,v01,v02,v03,v10,v11,v12,v13,v20,v21,v22,v23,v30,v31,v32,v33));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Matrix4_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_new02_local
static int tolua_FsFaeris_Matrix4_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,12,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,13,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,14,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,15,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,16,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,17,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,18,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float v00 = ((float)  tolua_tonumber(tolua_S,2,0));
  float v01 = ((float)  tolua_tonumber(tolua_S,3,0));
  float v02 = ((float)  tolua_tonumber(tolua_S,4,0));
  float v03 = ((float)  tolua_tonumber(tolua_S,5,0));
  float v10 = ((float)  tolua_tonumber(tolua_S,6,0));
  float v11 = ((float)  tolua_tonumber(tolua_S,7,0));
  float v12 = ((float)  tolua_tonumber(tolua_S,8,0));
  float v13 = ((float)  tolua_tonumber(tolua_S,9,0));
  float v20 = ((float)  tolua_tonumber(tolua_S,10,0));
  float v21 = ((float)  tolua_tonumber(tolua_S,11,0));
  float v22 = ((float)  tolua_tonumber(tolua_S,12,0));
  float v23 = ((float)  tolua_tonumber(tolua_S,13,0));
  float v30 = ((float)  tolua_tonumber(tolua_S,14,0));
  float v31 = ((float)  tolua_tonumber(tolua_S,15,0));
  float v32 = ((float)  tolua_tonumber(tolua_S,16,0));
  float v33 = ((float)  tolua_tonumber(tolua_S,17,0));
  {
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(v00,v01,v02,v03,v10,v11,v12,v13,v20,v21,v22,v23,v30,v31,v32,v33));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Matrix4_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_add00
static int tolua_FsFaeris_Matrix4_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* n = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'", NULL);
#endif
  {
   self->add(*n);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mul of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_mul00
static int tolua_FsFaeris_Matrix4_mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* n = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mul'", NULL);
#endif
  {
   self->mul(*n);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mulScaler of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_mulScaler00
static int tolua_FsFaeris_Matrix4_mulScaler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mulScaler'", NULL);
#endif
  {
   self->mulScaler(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mulScaler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mulVector3 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_mulVector300
static int tolua_FsFaeris_Matrix4_mulVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mulVector3'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->mulVector3(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mulVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mulVector4 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_mulVector400
static int tolua_FsFaeris_Matrix4_mulVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mulVector4'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->mulVector4(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mulVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: transpose of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_transpose00
static int tolua_FsFaeris_Matrix4_transpose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'transpose'", NULL);
#endif
  {
   self->transpose();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'transpose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTranspose of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_getTranspose00
static int tolua_FsFaeris_Matrix4_getTranspose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  Matrix4* m = ((Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTranspose'", NULL);
#endif
  {
   self->getTranspose(m);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTranspose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: inverse of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_inverse00
static int tolua_FsFaeris_Matrix4_inverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'inverse'", NULL);
#endif
  {
   self->inverse();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'inverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInverse of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_getInverse00
static int tolua_FsFaeris_Matrix4_getInverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  Matrix4* m = ((Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInverse'", NULL);
#endif
  {
   self->getInverse(m);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDetermiant of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_getDetermiant00
static int tolua_FsFaeris_Matrix4_getDetermiant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDetermiant'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getDetermiant();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDetermiant'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeTranslate of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_makeTranslate00
static int tolua_FsFaeris_Matrix4_makeTranslate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeTranslate'", NULL);
#endif
  {
   self->makeTranslate(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeTranslate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeTranslate of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_makeTranslate01
static int tolua_FsFaeris_Matrix4_makeTranslate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeTranslate'", NULL);
#endif
  {
   self->makeTranslate(*v);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsFaeris_Matrix4_makeTranslate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotateX of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_makeRotateX00
static int tolua_FsFaeris_Matrix4_makeRotateX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float theta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotateX'", NULL);
#endif
  {
   self->makeRotateX(theta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRotateX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotateY of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_makeRotateY00
static int tolua_FsFaeris_Matrix4_makeRotateY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float theta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotateY'", NULL);
#endif
  {
   self->makeRotateY(theta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRotateY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotateZ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_makeRotateZ00
static int tolua_FsFaeris_Matrix4_makeRotateZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float theta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotateZ'", NULL);
#endif
  {
   self->makeRotateZ(theta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRotateZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotateAxis of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_makeRotateAxis00
static int tolua_FsFaeris_Matrix4_makeRotateAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotateAxis'", NULL);
#endif
  {
   self->makeRotateAxis(*v,angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRotateAxis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotateAxis of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_makeRotateAxis01
static int tolua_FsFaeris_Matrix4_makeRotateAxis01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float angle = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotateAxis'", NULL);
#endif
  {
   self->makeRotateAxis(x,y,z,angle);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsFaeris_Matrix4_makeRotateAxis00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotateFromEuler of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_makeRotateFromEuler00
static int tolua_FsFaeris_Matrix4_makeRotateFromEuler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  int type = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotateFromEuler'", NULL);
#endif
  {
   self->makeRotateFromEuler(x,y,z,type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRotateFromEuler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotateFromEuler of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_makeRotateFromEuler01
static int tolua_FsFaeris_Matrix4_makeRotateFromEuler01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  int type = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotateFromEuler'", NULL);
#endif
  {
   self->makeRotateFromEuler(*v,type);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsFaeris_Matrix4_makeRotateFromEuler00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeScale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_makeScale00
static int tolua_FsFaeris_Matrix4_makeScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeScale'", NULL);
#endif
  {
   self->makeScale(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeScale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_makeScale01
static int tolua_FsFaeris_Matrix4_makeScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeScale'", NULL);
#endif
  {
   self->makeScale(*v);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsFaeris_Matrix4_makeScale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeIdentity of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_makeIdentity00
static int tolua_FsFaeris_Matrix4_makeIdentity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeIdentity'", NULL);
#endif
  {
   self->makeIdentity();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeCompose of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_makeCompose00
static int tolua_FsFaeris_Matrix4_makeCompose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* t = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* r = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  int r_type = ((int)  tolua_tonumber(tolua_S,4,0));
  const Vector3* s = ((const Vector3*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeCompose'", NULL);
#endif
  {
   self->makeCompose(*t,*r,r_type,*s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeCompose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeLookAt of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_makeLookAt00
static int tolua_FsFaeris_Matrix4_makeLookAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* eye = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* target = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* up = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeLookAt'", NULL);
#endif
  {
   self->makeLookAt(*eye,*target,*up);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeLookAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeFrustum of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_makeFrustum00
static int tolua_FsFaeris_Matrix4_makeFrustum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float right = ((float)  tolua_tonumber(tolua_S,3,0));
  float bottom = ((float)  tolua_tonumber(tolua_S,4,0));
  float top = ((float)  tolua_tonumber(tolua_S,5,0));
  float n = ((float)  tolua_tonumber(tolua_S,6,0));
  float f = ((float)  tolua_tonumber(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeFrustum'", NULL);
#endif
  {
   self->makeFrustum(left,right,bottom,top,n,f);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeFrustum'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makePerspective of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_makePerspective00
static int tolua_FsFaeris_Matrix4_makePerspective00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float fov = ((float)  tolua_tonumber(tolua_S,2,0));
  float aspect = ((float)  tolua_tonumber(tolua_S,3,0));
  float n = ((float)  tolua_tonumber(tolua_S,4,0));
  float f = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makePerspective'", NULL);
#endif
  {
   self->makePerspective(fov,aspect,n,f);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makePerspective'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeOrthographic of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_makeOrthographic00
static int tolua_FsFaeris_Matrix4_makeOrthographic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float right = ((float)  tolua_tonumber(tolua_S,3,0));
  float top = ((float)  tolua_tonumber(tolua_S,4,0));
  float bottom = ((float)  tolua_tonumber(tolua_S,5,0));
  float n = ((float)  tolua_tonumber(tolua_S,6,0));
  float f = ((float)  tolua_tonumber(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeOrthographic'", NULL);
#endif
  {
   self->makeOrthographic(left,right,top,bottom,n,f);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeOrthographic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTranslate of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_setTranslate00
static int tolua_FsFaeris_Matrix4_setTranslate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTranslate'", NULL);
#endif
  {
   self->setTranslate(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTranslate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTranslate of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_setTranslate01
static int tolua_FsFaeris_Matrix4_setTranslate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTranslate'", NULL);
#endif
  {
   self->setTranslate(*v);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsFaeris_Matrix4_setTranslate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotationFromEuler of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_setRotationFromEuler00
static int tolua_FsFaeris_Matrix4_setRotationFromEuler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
  int type = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotationFromEuler'", NULL);
#endif
  {
   self->setRotationFromEuler(rx,ry,rz,type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotationFromEuler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_setScale00
static int tolua_FsFaeris_Matrix4_setScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float sx = ((float)  tolua_tonumber(tolua_S,2,0));
  float sy = ((float)  tolua_tonumber(tolua_S,3,0));
  float sz = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'", NULL);
#endif
  {
   self->setScale(sx,sy,sz);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_setScale01
static int tolua_FsFaeris_Matrix4_setScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'", NULL);
#endif
  {
   self->setScale(*v);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsFaeris_Matrix4_setScale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: translate of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_translate00
static int tolua_FsFaeris_Matrix4_translate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float vx = ((float)  tolua_tonumber(tolua_S,2,0));
  float vy = ((float)  tolua_tonumber(tolua_S,3,0));
  float vz = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translate'", NULL);
#endif
  {
   self->translate(vx,vy,vz);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'translate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: translate of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_translate01
static int tolua_FsFaeris_Matrix4_translate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translate'", NULL);
#endif
  {
   self->translate(*v);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsFaeris_Matrix4_translate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateX of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_rotateX00
static int tolua_FsFaeris_Matrix4_rotateX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateX'", NULL);
#endif
  {
   self->rotateX(angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateY of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_rotateY00
static int tolua_FsFaeris_Matrix4_rotateY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateY'", NULL);
#endif
  {
   self->rotateY(angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateZ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_rotateZ00
static int tolua_FsFaeris_Matrix4_rotateZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateZ'", NULL);
#endif
  {
   self->rotateZ(angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateByAxis of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_rotateByAxis00
static int tolua_FsFaeris_Matrix4_rotateByAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float angle = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateByAxis'", NULL);
#endif
  {
   self->rotateByAxis(x,y,z,angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateByAxis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateByAxis of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_rotateByAxis01
static int tolua_FsFaeris_Matrix4_rotateByAxis01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateByAxis'", NULL);
#endif
  {
   self->rotateByAxis(*v,angle);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsFaeris_Matrix4_rotateByAxis00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_scale00
static int tolua_FsFaeris_Matrix4_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_scale01
static int tolua_FsFaeris_Matrix4_scale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(*v);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsFaeris_Matrix4_scale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColumnX of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_getColumnX00
static int tolua_FsFaeris_Matrix4_getColumnX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColumnX'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getColumnX();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColumnX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColumnY of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_getColumnY00
static int tolua_FsFaeris_Matrix4_getColumnY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColumnY'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getColumnY();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColumnY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColumnZ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_getColumnZ00
static int tolua_FsFaeris_Matrix4_getColumnZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColumnZ'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getColumnZ();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColumnZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTranslate of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_getTranslate00
static int tolua_FsFaeris_Matrix4_getTranslate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTranslate'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getTranslate();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTranslate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Matrix4_getScale00
static int tolua_FsFaeris_Matrix4_getScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScale'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getScale();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Rect2D_new00
static int tolua_FsFaeris_Rect2D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Rect2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float _x = ((float)  tolua_tonumber(tolua_S,2,0));
  float _y = ((float)  tolua_tonumber(tolua_S,3,0));
  float _width = ((float)  tolua_tonumber(tolua_S,4,0));
  float _height = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Rect2D* tolua_ret = (Rect2D*)  Mtolua_new((Rect2D)(_x,_y,_width,_height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Rect2D_new00_local
static int tolua_FsFaeris_Rect2D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Rect2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float _x = ((float)  tolua_tonumber(tolua_S,2,0));
  float _y = ((float)  tolua_tonumber(tolua_S,3,0));
  float _width = ((float)  tolua_tonumber(tolua_S,4,0));
  float _height = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Rect2D* tolua_ret = (Rect2D*)  Mtolua_new((Rect2D)(_x,_y,_width,_height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Rect2D_new01
static int tolua_FsFaeris_Rect2D_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Rect2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector2* _start = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  float _width = ((float)  tolua_tonumber(tolua_S,3,0));
  float _height = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Rect2D* tolua_ret = (Rect2D*)  Mtolua_new((Rect2D)(*_start,_width,_height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Rect2D_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Rect2D_new01_local
static int tolua_FsFaeris_Rect2D_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Rect2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector2* _start = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  float _width = ((float)  tolua_tonumber(tolua_S,3,0));
  float _height = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Rect2D* tolua_ret = (Rect2D*)  Mtolua_new((Rect2D)(*_start,_width,_height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Rect2D_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Rect2D_new02
static int tolua_FsFaeris_Rect2D_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Rect2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Rect2D* tolua_ret = (Rect2D*)  Mtolua_new((Rect2D)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Rect2D_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Rect2D_new02_local
static int tolua_FsFaeris_Rect2D_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Rect2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Rect2D* tolua_ret = (Rect2D*)  Mtolua_new((Rect2D)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rect2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Rect2D_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Rect2D_set00
static int tolua_FsFaeris_Rect2D_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Rect2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
  float _x = ((float)  tolua_tonumber(tolua_S,2,0));
  float _y = ((float)  tolua_tonumber(tolua_S,3,0));
  float _width = ((float)  tolua_tonumber(tolua_S,4,0));
  float _height = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(_x,_y,_width,_height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_get_Rect2D_x
static int tolua_get_Rect2D_x(lua_State* tolua_S)
{
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_set_Rect2D_x
static int tolua_set_Rect2D_x(lua_State* tolua_S)
{
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_get_Rect2D_y
static int tolua_get_Rect2D_y(lua_State* tolua_S)
{
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_set_Rect2D_y
static int tolua_set_Rect2D_y(lua_State* tolua_S)
{
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_get_Rect2D_width
static int tolua_get_Rect2D_width(lua_State* tolua_S)
{
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_set_Rect2D_width
static int tolua_set_Rect2D_width(lua_State* tolua_S)
{
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_get_Rect2D_height
static int tolua_get_Rect2D_height(lua_State* tolua_S)
{
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  Rect2D */
#ifndef TOLUA_DISABLE_tolua_set_Rect2D_height
static int tolua_set_Rect2D_height(lua_State* tolua_S)
{
  Rect2D* self = (Rect2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCaption of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Window_setCaption00
static int tolua_FsFaeris_Window_setCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCaption'", NULL);
#endif
  {
   self->setCaption(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCaption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCaption of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Window_getCaption00
static int tolua_FsFaeris_Window_getCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCaption'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getCaption();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCaption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Window_setPosition00
static int tolua_FsFaeris_Window_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   self->setPosition(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSize of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Window_setSize00
static int tolua_FsFaeris_Window_setSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  unsigned int width = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int height = (( unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSize'", NULL);
#endif
  {
   self->setSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Window_show00
static int tolua_FsFaeris_Window_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'", NULL);
#endif
  {
   self->show();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Window_hide00
static int tolua_FsFaeris_Window_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'", NULL);
#endif
  {
   self->hide();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStyle of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Window_setStyle00
static int tolua_FsFaeris_Window_setStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  long flags = ((long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStyle'", NULL);
#endif
  {
   self->setStyle(flags);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFullScreen of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Window_setFullScreen00
static int tolua_FsFaeris_Window_setFullScreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  bool full = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFullScreen'", NULL);
#endif
  {
   self->setFullScreen(full);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFullScreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWidth of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Window_getWidth00
static int tolua_FsFaeris_Window_getWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHeight of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Window_getHeight00
static int tolua_FsFaeris_Window_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosX of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Window_getPosX00
static int tolua_FsFaeris_Window_getPosX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosX'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getPosX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosY of class  Window */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Window_getPosY00
static int tolua_FsFaeris_Window_getPosY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosY'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getPosY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_FsFaeris_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"share","Global","",NULL);
  tolua_beginmodule(tolua_S,"share");
   tolua_function(tolua_S,"scheduler",tolua_FsFaeris_share_scheduler00);
   tolua_function(tolua_S,"touchDispatcher",tolua_FsFaeris_share_touchDispatcher00);
   tolua_function(tolua_S,"director",tolua_FsFaeris_share_director00);
   tolua_function(tolua_S,"sysDispatcher",tolua_FsFaeris_share_sysDispatcher00);
   tolua_function(tolua_S,"window",tolua_FsFaeris_share_window00);
   tolua_function(tolua_S,"render",tolua_FsFaeris_share_render00);
   tolua_function(tolua_S,"textureMgr",tolua_FsFaeris_share_textureMgr00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"FsObject","FsObject","",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"FsObject");
   tolua_function(tolua_S,"className",tolua_FsFaeris_FsObject_className00);
   tolua_variable(tolua_S,"data",tolua_get_FsObject_data,tolua_set_FsObject_data);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__TouchEventListener","TouchEventListener","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__TouchEventListener");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TouchEventListener","LuaTouchEventListener","TouchEventListener",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"TouchEventListener");
   tolua_function(tolua_S,"create",tolua_FsFaeris_TouchEventListener_create00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__SysEventListener","SysEventListener","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__SysEventListener");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SysEventListener","LuaSysEventListener","SysEventListener",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"SysEventListener");
   tolua_function(tolua_S,"create",tolua_FsFaeris_SysEventListener_create00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SysDispatcher","SysDispatcher","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"SysDispatcher");
   tolua_function(tolua_S,"addEventListener",tolua_FsFaeris_SysDispatcher_addEventListener00);
   tolua_function(tolua_S,"removeEventListener",tolua_FsFaeris_SysDispatcher_removeEventListener00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TouchDispatcher","TouchDispatcher","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"TouchDispatcher");
   tolua_function(tolua_S,"addEventListener",tolua_FsFaeris_TouchDispatcher_addEventListener00);
   tolua_function(tolua_S,"removeEventListener",tolua_FsFaeris_TouchDispatcher_removeEventListener00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__Entity","Entity","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__Entity");
   tolua_function(tolua_S,"localToWorld",tolua_FsFaeris___Entity_localToWorld00);
   tolua_function(tolua_S,"worldToLocal",tolua_FsFaeris___Entity_worldToLocal00);
   tolua_function(tolua_S,"addChild",tolua_FsFaeris___Entity_addChild00);
   tolua_function(tolua_S,"remove",tolua_FsFaeris___Entity_remove00);
   tolua_function(tolua_S,"detach",tolua_FsFaeris___Entity_detach00);
   tolua_function(tolua_S,"allChild",tolua_FsFaeris___Entity_allChild00);
   tolua_function(tolua_S,"childNu",tolua_FsFaeris___Entity_childNu00);
   tolua_function(tolua_S,"getPosition",tolua_FsFaeris___Entity_getPosition00);
   tolua_function(tolua_S,"getScale",tolua_FsFaeris___Entity_getScale00);
   tolua_function(tolua_S,"getRotate",tolua_FsFaeris___Entity_getRotate00);
   tolua_function(tolua_S,"rotate",tolua_FsFaeris___Entity_rotate00);
   tolua_function(tolua_S,"rotateX",tolua_FsFaeris___Entity_rotateX00);
   tolua_function(tolua_S,"rotateY",tolua_FsFaeris___Entity_rotateY00);
   tolua_function(tolua_S,"rotateZ",tolua_FsFaeris___Entity_rotateZ00);
   tolua_function(tolua_S,"scale",tolua_FsFaeris___Entity_scale00);
   tolua_function(tolua_S,"scaleX",tolua_FsFaeris___Entity_scaleX00);
   tolua_function(tolua_S,"scaleY",tolua_FsFaeris___Entity_scaleY00);
   tolua_function(tolua_S,"scaleZ",tolua_FsFaeris___Entity_scaleZ00);
   tolua_function(tolua_S,"move",tolua_FsFaeris___Entity_move00);
   tolua_function(tolua_S,"moveX",tolua_FsFaeris___Entity_moveX00);
   tolua_function(tolua_S,"moveY",tolua_FsFaeris___Entity_moveY00);
   tolua_function(tolua_S,"moveZ",tolua_FsFaeris___Entity_moveZ00);
   tolua_function(tolua_S,"setRotate",tolua_FsFaeris___Entity_setRotate00);
   tolua_function(tolua_S,"setRotateX",tolua_FsFaeris___Entity_setRotateX00);
   tolua_function(tolua_S,"setRotateY",tolua_FsFaeris___Entity_setRotateY00);
   tolua_function(tolua_S,"setRotateZ",tolua_FsFaeris___Entity_setRotateZ00);
   tolua_function(tolua_S,"setScale",tolua_FsFaeris___Entity_setScale00);
   tolua_function(tolua_S,"setScaleX",tolua_FsFaeris___Entity_setScaleX00);
   tolua_function(tolua_S,"setScaleY",tolua_FsFaeris___Entity_setScaleY00);
   tolua_function(tolua_S,"setScaleZ",tolua_FsFaeris___Entity_setScaleZ00);
   tolua_function(tolua_S,"setPosition",tolua_FsFaeris___Entity_setPosition00);
   tolua_function(tolua_S,"setPositionX",tolua_FsFaeris___Entity_setPositionX00);
   tolua_function(tolua_S,"setPositionY",tolua_FsFaeris___Entity_setPositionY00);
   tolua_function(tolua_S,"setPositionZ",tolua_FsFaeris___Entity_setPositionZ00);
   tolua_function(tolua_S,"setVisible",tolua_FsFaeris___Entity_setVisible00);
   tolua_function(tolua_S,"visible",tolua_FsFaeris___Entity_visible00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Entity","LuaEntity","Entity",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Entity");
   tolua_function(tolua_S,"create",tolua_FsFaeris_Entity_create00);
   tolua_function(tolua_S,"onUpdate",tolua_FsFaeris_Entity_onUpdate00);
   tolua_function(tolua_S,"onDraw",tolua_FsFaeris_Entity_onDraw00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ColorQuad2D","LuaColorQuad2D","Entity",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"ColorQuad2D");
   tolua_constant(tolua_S,"VERTEX_A",LuaColorQuad2D::VERTEX_A);
   tolua_constant(tolua_S,"VERTEX_B",LuaColorQuad2D::VERTEX_B);
   tolua_constant(tolua_S,"VERTEX_C",LuaColorQuad2D::VERTEX_C);
   tolua_constant(tolua_S,"VERTEX_D",LuaColorQuad2D::VERTEX_D);
   tolua_constant(tolua_S,"VERTEX_ALL",LuaColorQuad2D::VERTEX_ALL);
   tolua_function(tolua_S,"create",tolua_FsFaeris_ColorQuad2D_create00);
   tolua_function(tolua_S,"create",tolua_FsFaeris_ColorQuad2D_create01);
   tolua_function(tolua_S,"onUpdate",tolua_FsFaeris_ColorQuad2D_onUpdate00);
   tolua_function(tolua_S,"onDraw",tolua_FsFaeris_ColorQuad2D_onDraw00);
   tolua_function(tolua_S,"setColor",tolua_FsFaeris_ColorQuad2D_setColor00);
   tolua_function(tolua_S,"setRect",tolua_FsFaeris_ColorQuad2D_setRect00);
   tolua_function(tolua_S,"setOpacity",tolua_FsFaeris_ColorQuad2D_setOpacity00);
   tolua_function(tolua_S,"getOpacity",tolua_FsFaeris_ColorQuad2D_getOpacity00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__Quad2D","Quad2D","Entity",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__Quad2D");
   tolua_function(tolua_S,"create",tolua_FsFaeris___Quad2D_create00);
   tolua_function(tolua_S,"setColor",tolua_FsFaeris___Quad2D_setColor00);
   tolua_function(tolua_S,"getColor",tolua_FsFaeris___Quad2D_getColor00);
   tolua_function(tolua_S,"setOpacity",tolua_FsFaeris___Quad2D_setOpacity00);
   tolua_function(tolua_S,"getOpacity",tolua_FsFaeris___Quad2D_getOpacity00);
   tolua_function(tolua_S,"setTexture",tolua_FsFaeris___Quad2D_setTexture00);
   tolua_function(tolua_S,"getTexture",tolua_FsFaeris___Quad2D_getTexture00);
   tolua_function(tolua_S,"setTextureCoord",tolua_FsFaeris___Quad2D_setTextureCoord00);
   tolua_function(tolua_S,"getTextureCoord",tolua_FsFaeris___Quad2D_getTextureCoord00);
   tolua_function(tolua_S,"setRect2D",tolua_FsFaeris___Quad2D_setRect2D00);
   tolua_function(tolua_S,"getRect2D",tolua_FsFaeris___Quad2D_getRect2D00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Quad2D","LuaQuad2D","Quad2D",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Quad2D");
   tolua_function(tolua_S,"create",tolua_FsFaeris_Quad2D_create00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"LabelTTF","LabelTTF","Entity",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"LabelTTF");
   tolua_constant(tolua_S,"ALIGN_V_CENTER",LabelTTF::ALIGN_V_CENTER);
   tolua_constant(tolua_S,"ALIGN_V_TOP",LabelTTF::ALIGN_V_TOP);
   tolua_constant(tolua_S,"ALIGN_V_BOTTOM",LabelTTF::ALIGN_V_BOTTOM);
   tolua_constant(tolua_S,"ALIGN_H_LEFT",LabelTTF::ALIGN_H_LEFT);
   tolua_constant(tolua_S,"ALIGN_H_RIGHT",LabelTTF::ALIGN_H_RIGHT);
   tolua_constant(tolua_S,"ALIGN_H_CENTER",LabelTTF::ALIGN_H_CENTER);
   tolua_function(tolua_S,"create",tolua_FsFaeris_LabelTTF_create00);
   tolua_function(tolua_S,"setString",tolua_FsFaeris_LabelTTF_setString00);
   tolua_function(tolua_S,"getString",tolua_FsFaeris_LabelTTF_getString00);
   tolua_function(tolua_S,"setFont",tolua_FsFaeris_LabelTTF_setFont00);
   tolua_function(tolua_S,"getFont",tolua_FsFaeris_LabelTTF_getFont00);
   tolua_function(tolua_S,"setAlign",tolua_FsFaeris_LabelTTF_setAlign00);
   tolua_function(tolua_S,"getAlign",tolua_FsFaeris_LabelTTF_getAlign00);
   tolua_function(tolua_S,"setColor",tolua_FsFaeris_LabelTTF_setColor00);
   tolua_function(tolua_S,"getColor",tolua_FsFaeris_LabelTTF_getColor00);
   tolua_function(tolua_S,"setOpacity",tolua_FsFaeris_LabelTTF_setOpacity00);
   tolua_function(tolua_S,"getOpacity",tolua_FsFaeris_LabelTTF_getOpacity00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Scheduler","Scheduler","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Scheduler");
   tolua_constant(tolua_S,"HIGHEST",Scheduler::HIGHEST);
   tolua_constant(tolua_S,"HIGH",Scheduler::HIGH);
   tolua_constant(tolua_S,"MIDDLE",Scheduler::MIDDLE);
   tolua_constant(tolua_S,"LOW",Scheduler::LOW);
   tolua_constant(tolua_S,"LOWEST",Scheduler::LOWEST);
   tolua_constant(tolua_S,"PRIORITY_NU",Scheduler::PRIORITY_NU);
   tolua_function(tolua_S,"create",tolua_FsFaeris_Scheduler_create00);
   tolua_function(tolua_S,"className",tolua_FsFaeris_Scheduler_className00);
   tolua_function(tolua_S,"start",tolua_FsFaeris_Scheduler_start00);
   tolua_function(tolua_S,"stop",tolua_FsFaeris_Scheduler_stop00);
   tolua_function(tolua_S,"setFps",tolua_FsFaeris_Scheduler_setFps00);
   tolua_function(tolua_S,"mainLoop",tolua_FsFaeris_Scheduler_mainLoop00);
   tolua_function(tolua_S,"add",tolua_FsFaeris_Scheduler_add00);
   tolua_function(tolua_S,"remove",tolua_FsFaeris_Scheduler_remove00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__Scene","Scene","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__Scene");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Scene","LuaScene","Scene",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Scene");
   tolua_function(tolua_S,"create",tolua_FsFaeris_Scene_create00);
   tolua_function(tolua_S,"push",tolua_FsFaeris_Scene_push00);
   tolua_function(tolua_S,"pop",tolua_FsFaeris_Scene_pop00);
   tolua_function(tolua_S,"insert",tolua_FsFaeris_Scene_insert00);
   tolua_function(tolua_S,"replace",tolua_FsFaeris_Scene_replace00);
   tolua_function(tolua_S,"remove",tolua_FsFaeris_Scene_remove00);
   tolua_function(tolua_S,"enter",tolua_FsFaeris_Scene_enter00);
   tolua_function(tolua_S,"exit",tolua_FsFaeris_Scene_exit00);
   tolua_function(tolua_S,"update",tolua_FsFaeris_Scene_update00);
   tolua_function(tolua_S,"draw",tolua_FsFaeris_Scene_draw00);
   tolua_function(tolua_S,"touchBegin",tolua_FsFaeris_Scene_touchBegin00);
   tolua_function(tolua_S,"touchEnd",tolua_FsFaeris_Scene_touchEnd00);
   tolua_function(tolua_S,"touchMove",tolua_FsFaeris_Scene_touchMove00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Director","Director","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Director");
   tolua_function(tolua_S,"push",tolua_FsFaeris_Director_push00);
   tolua_function(tolua_S,"pop",tolua_FsFaeris_Director_pop00);
   tolua_function(tolua_S,"run",tolua_FsFaeris_Director_run00);
   tolua_function(tolua_S,"pause",tolua_FsFaeris_Director_pause00);
   tolua_function(tolua_S,"start",tolua_FsFaeris_Director_start00);
   tolua_function(tolua_S,"isRunning",tolua_FsFaeris_Director_isRunning00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Layer","Layer","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Layer");
   tolua_function(tolua_S,"visible",tolua_FsFaeris_Layer_visible00);
   tolua_function(tolua_S,"setVisible",tolua_FsFaeris_Layer_setVisible00);
   tolua_function(tolua_S,"touchEnabled",tolua_FsFaeris_Layer_touchEnabled00);
   tolua_function(tolua_S,"setTouchEnabled",tolua_FsFaeris_Layer_setTouchEnabled00);
   tolua_function(tolua_S,"add",tolua_FsFaeris_Layer_add00);
   tolua_function(tolua_S,"remove",tolua_FsFaeris_Layer_remove00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ColorLayer","LuaColorLayer","Layer",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"ColorLayer");
   tolua_function(tolua_S,"create",tolua_FsFaeris_ColorLayer_create00);
   tolua_function(tolua_S,"setColor",tolua_FsFaeris_ColorLayer_setColor00);
   tolua_function(tolua_S,"getColor",tolua_FsFaeris_ColorLayer_getColor00);
   tolua_function(tolua_S,"onUpdate",tolua_FsFaeris_ColorLayer_onUpdate00);
   tolua_function(tolua_S,"onDraw",tolua_FsFaeris_ColorLayer_onDraw00);
   tolua_function(tolua_S,"onTouchBegin",tolua_FsFaeris_ColorLayer_onTouchBegin00);
   tolua_function(tolua_S,"onTouchEnd",tolua_FsFaeris_ColorLayer_onTouchEnd00);
   tolua_function(tolua_S,"onTouchMove",tolua_FsFaeris_ColorLayer_onTouchMove00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"__Layer2D","Layer2D","Layer",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"__Layer2D");
   tolua_constant(tolua_S,"SORT_NONE",Layer2D::SORT_NONE);
   tolua_constant(tolua_S,"SORT_Z",Layer2D::SORT_Z);
   tolua_constant(tolua_S,"SORT_Y",Layer2D::SORT_Y);
   tolua_constant(tolua_S,"SORT_X",Layer2D::SORT_X);
   tolua_constant(tolua_S,"DOWN_OLDER",Layer2D::DOWN_OLDER);
   tolua_constant(tolua_S,"UP_OLDER",Layer2D::UP_OLDER);
   tolua_function(tolua_S,"getProjectMatrix",tolua_FsFaeris___Layer2D_getProjectMatrix00);
   tolua_function(tolua_S,"getViewArea",tolua_FsFaeris___Layer2D_getViewArea00);
   tolua_function(tolua_S,"toLayerCoord",tolua_FsFaeris___Layer2D_toLayerCoord00);
   tolua_function(tolua_S,"toLayerCoord",tolua_FsFaeris___Layer2D_toLayerCoord01);
   tolua_function(tolua_S,"setViewArea",tolua_FsFaeris___Layer2D_setViewArea00);
   tolua_function(tolua_S,"setViewArea",tolua_FsFaeris___Layer2D_setViewArea01);
   tolua_function(tolua_S,"setSortMode",tolua_FsFaeris___Layer2D_setSortMode00);
   tolua_function(tolua_S,"getSortMode",tolua_FsFaeris___Layer2D_getSortMode00);
   tolua_function(tolua_S,"setOlderMode",tolua_FsFaeris___Layer2D_setOlderMode00);
   tolua_function(tolua_S,"getOlderMode",tolua_FsFaeris___Layer2D_getOlderMode00);
   tolua_function(tolua_S,"setEliminate",tolua_FsFaeris___Layer2D_setEliminate00);
   tolua_function(tolua_S,"getEliminate",tolua_FsFaeris___Layer2D_getEliminate00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Layer2D","LuaLayer2D","Layer2D",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Layer2D");
   tolua_function(tolua_S,"create",tolua_FsFaeris_Layer2D_create00);
   tolua_function(tolua_S,"onUpdate",tolua_FsFaeris_Layer2D_onUpdate00);
   tolua_function(tolua_S,"onDraw",tolua_FsFaeris_Layer2D_onDraw00);
   tolua_function(tolua_S,"onTouchBegin",tolua_FsFaeris_Layer2D_onTouchBegin00);
   tolua_function(tolua_S,"onTouchEnd",tolua_FsFaeris_Layer2D_onTouchEnd00);
   tolua_function(tolua_S,"onTouchMove",tolua_FsFaeris_Layer2D_onTouchMove00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Render","Render","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Render");
   tolua_function(tolua_S,"setViewport",tolua_FsFaeris_Render_setViewport00);
   tolua_function(tolua_S,"setClearColor",tolua_FsFaeris_Render_setClearColor00);
   tolua_function(tolua_S,"setProjectionMatrix",tolua_FsFaeris_Render_setProjectionMatrix00);
   tolua_function(tolua_S,"pushMatrix",tolua_FsFaeris_Render_pushMatrix00);
   tolua_function(tolua_S,"popMatrix",tolua_FsFaeris_Render_popMatrix00);
   tolua_function(tolua_S,"loadIdentity",tolua_FsFaeris_Render_loadIdentity00);
   tolua_function(tolua_S,"mulMatrix",tolua_FsFaeris_Render_mulMatrix00);
   tolua_function(tolua_S,"setMatrix",tolua_FsFaeris_Render_setMatrix00);
   tolua_function(tolua_S,"translate",tolua_FsFaeris_Render_translate00);
   tolua_function(tolua_S,"scale",tolua_FsFaeris_Render_scale00);
   tolua_function(tolua_S,"rotate",tolua_FsFaeris_Render_rotate00);
   tolua_function(tolua_S,"drawLine",tolua_FsFaeris_Render_drawLine00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Color","Color","",tolua_collect_Color);
  #else
  tolua_cclass(tolua_S,"Color","Color","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Color");
   tolua_variable(tolua_S,"DEFAULT_COLOR",tolua_get_Color_DEFAULT_COLOR,tolua_set_Color_DEFAULT_COLOR);
   tolua_variable(tolua_S,"RED",tolua_get_Color_RED,tolua_set_Color_RED);
   tolua_variable(tolua_S,"BLUE",tolua_get_Color_BLUE,tolua_set_Color_BLUE);
   tolua_variable(tolua_S,"GREEN",tolua_get_Color_GREEN,tolua_set_Color_GREEN);
   tolua_variable(tolua_S,"WHITE",tolua_get_Color_WHITE,tolua_set_Color_WHITE);
   tolua_variable(tolua_S,"BLACK",tolua_get_Color_BLACK,tolua_set_Color_BLACK);
   tolua_variable(tolua_S,"r",tolua_get_Color_unsigned_r,tolua_set_Color_unsigned_r);
   tolua_variable(tolua_S,"g",tolua_get_Color_unsigned_g,tolua_set_Color_unsigned_g);
   tolua_variable(tolua_S,"b",tolua_get_Color_unsigned_b,tolua_set_Color_unsigned_b);
   tolua_variable(tolua_S,"a",tolua_get_Color_unsigned_a,tolua_set_Color_unsigned_a);
   tolua_function(tolua_S,"new",tolua_FsFaeris_Color_new00);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Color_new00_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Color_new00_local);
   tolua_function(tolua_S,"new",tolua_FsFaeris_Color_new01);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Color_new01_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Color_new01_local);
   tolua_function(tolua_S,"new",tolua_FsFaeris_Color_new02);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Color_new02_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Color_new02_local);
   tolua_function(tolua_S,".add",tolua_FsFaeris_Color__add00);
   tolua_function(tolua_S,".sub",tolua_FsFaeris_Color__sub00);
   tolua_function(tolua_S,".mul",tolua_FsFaeris_Color__mul00);
   tolua_function(tolua_S,".eq",tolua_FsFaeris_Color__eq00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"FontTTF","FontTTF","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"FontTTF");
   tolua_function(tolua_S,"create",tolua_FsFaeris_FontTTF_create00);
   tolua_function(tolua_S,"getHeight",tolua_FsFaeris_FontTTF_getHeight00);
   tolua_function(tolua_S,"getAscend",tolua_FsFaeris_FontTTF_getAscend00);
   tolua_function(tolua_S,"getDescend",tolua_FsFaeris_FontTTF_getDescend00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Vector2","Vector2","",tolua_collect_Vector2);
  #else
  tolua_cclass(tolua_S,"Vector2","Vector2","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Vector2");
   tolua_variable(tolua_S,"x",tolua_get_Vector2_x,tolua_set_Vector2_x);
   tolua_variable(tolua_S,"y",tolua_get_Vector2_y,tolua_set_Vector2_y);
   tolua_function(tolua_S,"new",tolua_FsFaeris_Vector2_new00);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Vector2_new00_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Vector2_new00_local);
   tolua_function(tolua_S,"new",tolua_FsFaeris_Vector2_new01);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Vector2_new01_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Vector2_new01_local);
   tolua_function(tolua_S,"add",tolua_FsFaeris_Vector2_add00);
   tolua_function(tolua_S,"sub",tolua_FsFaeris_Vector2_sub00);
   tolua_function(tolua_S,"scale",tolua_FsFaeris_Vector2_scale00);
   tolua_function(tolua_S,"dot",tolua_FsFaeris_Vector2_dot00);
   tolua_function(tolua_S,"normal",tolua_FsFaeris_Vector2_normal00);
   tolua_function(tolua_S,"normalize",tolua_FsFaeris_Vector2_normalize00);
   tolua_function(tolua_S,"proj",tolua_FsFaeris_Vector2_proj00);
   tolua_function(tolua_S,"angle",tolua_FsFaeris_Vector2_angle00);
   tolua_function(tolua_S,"length",tolua_FsFaeris_Vector2_length00);
   tolua_function(tolua_S,"length2",tolua_FsFaeris_Vector2_length200);
   tolua_function(tolua_S,"equal",tolua_FsFaeris_Vector2_equal00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Vector3","Vector3","",tolua_collect_Vector3);
  #else
  tolua_cclass(tolua_S,"Vector3","Vector3","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Vector3");
   tolua_variable(tolua_S,"x",tolua_get_Vector3_x,tolua_set_Vector3_x);
   tolua_variable(tolua_S,"y",tolua_get_Vector3_y,tolua_set_Vector3_y);
   tolua_variable(tolua_S,"z",tolua_get_Vector3_z,tolua_set_Vector3_z);
   tolua_function(tolua_S,"new",tolua_FsFaeris_Vector3_new00);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Vector3_new00_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Vector3_new00_local);
   tolua_function(tolua_S,"new",tolua_FsFaeris_Vector3_new01);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Vector3_new01_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Vector3_new01_local);
   tolua_function(tolua_S,"add",tolua_FsFaeris_Vector3_add00);
   tolua_function(tolua_S,"sub",tolua_FsFaeris_Vector3_sub00);
   tolua_function(tolua_S,"scale",tolua_FsFaeris_Vector3_scale00);
   tolua_function(tolua_S,"dot",tolua_FsFaeris_Vector3_dot00);
   tolua_function(tolua_S,"cross",tolua_FsFaeris_Vector3_cross00);
   tolua_function(tolua_S,"normal",tolua_FsFaeris_Vector3_normal00);
   tolua_function(tolua_S,"normalize",tolua_FsFaeris_Vector3_normalize00);
   tolua_function(tolua_S,"proj",tolua_FsFaeris_Vector3_proj00);
   tolua_function(tolua_S,"angle",tolua_FsFaeris_Vector3_angle00);
   tolua_function(tolua_S,"length",tolua_FsFaeris_Vector3_length00);
   tolua_function(tolua_S,"length2",tolua_FsFaeris_Vector3_length200);
   tolua_function(tolua_S,"equal",tolua_FsFaeris_Vector3_equal00);
   tolua_function(tolua_S,"set",tolua_FsFaeris_Vector3_set00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Vector4","Vector4","",tolua_collect_Vector4);
  #else
  tolua_cclass(tolua_S,"Vector4","Vector4","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Vector4");
   tolua_variable(tolua_S,"x",tolua_get_Vector4_x,tolua_set_Vector4_x);
   tolua_variable(tolua_S,"y",tolua_get_Vector4_y,tolua_set_Vector4_y);
   tolua_variable(tolua_S,"z",tolua_get_Vector4_z,tolua_set_Vector4_z);
   tolua_variable(tolua_S,"w",tolua_get_Vector4_w,tolua_set_Vector4_w);
   tolua_function(tolua_S,"new",tolua_FsFaeris_Vector4_new00);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Vector4_new00_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Vector4_new00_local);
   tolua_function(tolua_S,"new",tolua_FsFaeris_Vector4_new01);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Vector4_new01_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Vector4_new01_local);
   tolua_function(tolua_S,"new",tolua_FsFaeris_Vector4_new02);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Vector4_new02_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Vector4_new02_local);
   tolua_function(tolua_S,"add",tolua_FsFaeris_Vector4_add00);
   tolua_function(tolua_S,"sub",tolua_FsFaeris_Vector4_sub00);
   tolua_function(tolua_S,"scale",tolua_FsFaeris_Vector4_scale00);
   tolua_function(tolua_S,"dot",tolua_FsFaeris_Vector4_dot00);
   tolua_function(tolua_S,"normal",tolua_FsFaeris_Vector4_normal00);
   tolua_function(tolua_S,"normalize",tolua_FsFaeris_Vector4_normalize00);
   tolua_function(tolua_S,"length",tolua_FsFaeris_Vector4_length00);
   tolua_function(tolua_S,"length2",tolua_FsFaeris_Vector4_length200);
   tolua_function(tolua_S,"equal",tolua_FsFaeris_Vector4_equal00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Matrix4","Matrix4","",tolua_collect_Matrix4);
  #else
  tolua_cclass(tolua_S,"Matrix4","Matrix4","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Matrix4");
   tolua_function(tolua_S,"new",tolua_FsFaeris_Matrix4_new00);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Matrix4_new00_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Matrix4_new00_local);
   tolua_function(tolua_S,"new",tolua_FsFaeris_Matrix4_new01);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Matrix4_new01_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Matrix4_new01_local);
   tolua_function(tolua_S,"new",tolua_FsFaeris_Matrix4_new02);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Matrix4_new02_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Matrix4_new02_local);
   tolua_function(tolua_S,"add",tolua_FsFaeris_Matrix4_add00);
   tolua_function(tolua_S,"mul",tolua_FsFaeris_Matrix4_mul00);
   tolua_function(tolua_S,"mulScaler",tolua_FsFaeris_Matrix4_mulScaler00);
   tolua_function(tolua_S,"mulVector3",tolua_FsFaeris_Matrix4_mulVector300);
   tolua_function(tolua_S,"mulVector4",tolua_FsFaeris_Matrix4_mulVector400);
   tolua_function(tolua_S,"transpose",tolua_FsFaeris_Matrix4_transpose00);
   tolua_function(tolua_S,"getTranspose",tolua_FsFaeris_Matrix4_getTranspose00);
   tolua_function(tolua_S,"inverse",tolua_FsFaeris_Matrix4_inverse00);
   tolua_function(tolua_S,"getInverse",tolua_FsFaeris_Matrix4_getInverse00);
   tolua_function(tolua_S,"getDetermiant",tolua_FsFaeris_Matrix4_getDetermiant00);
   tolua_function(tolua_S,"makeTranslate",tolua_FsFaeris_Matrix4_makeTranslate00);
   tolua_function(tolua_S,"makeTranslate",tolua_FsFaeris_Matrix4_makeTranslate01);
   tolua_function(tolua_S,"makeRotateX",tolua_FsFaeris_Matrix4_makeRotateX00);
   tolua_function(tolua_S,"makeRotateY",tolua_FsFaeris_Matrix4_makeRotateY00);
   tolua_function(tolua_S,"makeRotateZ",tolua_FsFaeris_Matrix4_makeRotateZ00);
   tolua_function(tolua_S,"makeRotateAxis",tolua_FsFaeris_Matrix4_makeRotateAxis00);
   tolua_function(tolua_S,"makeRotateAxis",tolua_FsFaeris_Matrix4_makeRotateAxis01);
   tolua_function(tolua_S,"makeRotateFromEuler",tolua_FsFaeris_Matrix4_makeRotateFromEuler00);
   tolua_function(tolua_S,"makeRotateFromEuler",tolua_FsFaeris_Matrix4_makeRotateFromEuler01);
   tolua_function(tolua_S,"makeScale",tolua_FsFaeris_Matrix4_makeScale00);
   tolua_function(tolua_S,"makeScale",tolua_FsFaeris_Matrix4_makeScale01);
   tolua_function(tolua_S,"makeIdentity",tolua_FsFaeris_Matrix4_makeIdentity00);
   tolua_function(tolua_S,"makeCompose",tolua_FsFaeris_Matrix4_makeCompose00);
   tolua_function(tolua_S,"makeLookAt",tolua_FsFaeris_Matrix4_makeLookAt00);
   tolua_function(tolua_S,"makeFrustum",tolua_FsFaeris_Matrix4_makeFrustum00);
   tolua_function(tolua_S,"makePerspective",tolua_FsFaeris_Matrix4_makePerspective00);
   tolua_function(tolua_S,"makeOrthographic",tolua_FsFaeris_Matrix4_makeOrthographic00);
   tolua_function(tolua_S,"setTranslate",tolua_FsFaeris_Matrix4_setTranslate00);
   tolua_function(tolua_S,"setTranslate",tolua_FsFaeris_Matrix4_setTranslate01);
   tolua_function(tolua_S,"setRotationFromEuler",tolua_FsFaeris_Matrix4_setRotationFromEuler00);
   tolua_function(tolua_S,"setScale",tolua_FsFaeris_Matrix4_setScale00);
   tolua_function(tolua_S,"setScale",tolua_FsFaeris_Matrix4_setScale01);
   tolua_function(tolua_S,"translate",tolua_FsFaeris_Matrix4_translate00);
   tolua_function(tolua_S,"translate",tolua_FsFaeris_Matrix4_translate01);
   tolua_function(tolua_S,"rotateX",tolua_FsFaeris_Matrix4_rotateX00);
   tolua_function(tolua_S,"rotateY",tolua_FsFaeris_Matrix4_rotateY00);
   tolua_function(tolua_S,"rotateZ",tolua_FsFaeris_Matrix4_rotateZ00);
   tolua_function(tolua_S,"rotateByAxis",tolua_FsFaeris_Matrix4_rotateByAxis00);
   tolua_function(tolua_S,"rotateByAxis",tolua_FsFaeris_Matrix4_rotateByAxis01);
   tolua_function(tolua_S,"scale",tolua_FsFaeris_Matrix4_scale00);
   tolua_function(tolua_S,"scale",tolua_FsFaeris_Matrix4_scale01);
   tolua_function(tolua_S,"getColumnX",tolua_FsFaeris_Matrix4_getColumnX00);
   tolua_function(tolua_S,"getColumnY",tolua_FsFaeris_Matrix4_getColumnY00);
   tolua_function(tolua_S,"getColumnZ",tolua_FsFaeris_Matrix4_getColumnZ00);
   tolua_function(tolua_S,"getTranslate",tolua_FsFaeris_Matrix4_getTranslate00);
   tolua_function(tolua_S,"getScale",tolua_FsFaeris_Matrix4_getScale00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Rect2D","Rect2D","",tolua_collect_Rect2D);
  #else
  tolua_cclass(tolua_S,"Rect2D","Rect2D","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Rect2D");
   tolua_function(tolua_S,"new",tolua_FsFaeris_Rect2D_new00);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Rect2D_new00_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Rect2D_new00_local);
   tolua_function(tolua_S,"new",tolua_FsFaeris_Rect2D_new01);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Rect2D_new01_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Rect2D_new01_local);
   tolua_function(tolua_S,"new",tolua_FsFaeris_Rect2D_new02);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Rect2D_new02_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Rect2D_new02_local);
   tolua_function(tolua_S,"set",tolua_FsFaeris_Rect2D_set00);
   tolua_variable(tolua_S,"x",tolua_get_Rect2D_x,tolua_set_Rect2D_x);
   tolua_variable(tolua_S,"y",tolua_get_Rect2D_y,tolua_set_Rect2D_y);
   tolua_variable(tolua_S,"width",tolua_get_Rect2D_width,tolua_set_Rect2D_width);
   tolua_variable(tolua_S,"height",tolua_get_Rect2D_height,tolua_set_Rect2D_height);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Window","Window","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"Window");
   tolua_function(tolua_S,"setCaption",tolua_FsFaeris_Window_setCaption00);
   tolua_function(tolua_S,"getCaption",tolua_FsFaeris_Window_getCaption00);
   tolua_function(tolua_S,"setPosition",tolua_FsFaeris_Window_setPosition00);
   tolua_function(tolua_S,"setSize",tolua_FsFaeris_Window_setSize00);
   tolua_function(tolua_S,"show",tolua_FsFaeris_Window_show00);
   tolua_function(tolua_S,"hide",tolua_FsFaeris_Window_hide00);
   tolua_function(tolua_S,"setStyle",tolua_FsFaeris_Window_setStyle00);
   tolua_function(tolua_S,"setFullScreen",tolua_FsFaeris_Window_setFullScreen00);
   tolua_function(tolua_S,"getWidth",tolua_FsFaeris_Window_getWidth00);
   tolua_function(tolua_S,"getHeight",tolua_FsFaeris_Window_getHeight00);
   tolua_function(tolua_S,"getPosX",tolua_FsFaeris_Window_getPosX00);
   tolua_function(tolua_S,"getPosY",tolua_FsFaeris_Window_getPosY00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TextureMgr","TextureMgr","ResourceMgr",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"TextureMgr");
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_FsFaeris (lua_State* tolua_S) {
 return tolua_FsFaeris_open(tolua_S);
};
#endif

