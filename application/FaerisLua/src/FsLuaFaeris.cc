/*
** Lua binding: FsFaeris
** Generated automatically by tolua++-1.0.92 on 01/22/13 00:05:39.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_FsFaeris_open (lua_State* tolua_S);

#include "FsLuaFaeris.h"
#include "core/FsObject.h"
#include "util/FsResource.h"
#include "fsys/FsWindow.h"
#include "fsys/FsFrame.h"
#include "FsLuaFrameListener.h"
#include "math/FsVector2.h"
#include "math/FsVector3.h"
#include "math/FsVector4.h"
#include "math/FsMatrix4.h"
#include "loader/FsMeshLoader.h"
#include "loader/FsGeometryLoader.h"
#include "loader/FsMaterialLoader.h"
#include "loader/FsProgramLoader.h"
#include "loader/FsTextureLoader.h"
#include "graphics/FsRender.h"
#include "model/FsMesh.h"
#include "material/FsMaterial.h"
#include "material/FsShaderMaterial.h"
#include "scene/FsSceneNode.h"
#include "scene/FsEntity.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_SceneNode (lua_State* tolua_S)
{
 SceneNode* self = (SceneNode*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Color (lua_State* tolua_S)
{
 Color* self = (Color*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ShaderMaterial__Uniform (lua_State* tolua_S)
{
 ShaderMaterial::Uniform* self = (ShaderMaterial::Uniform*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vector4 (lua_State* tolua_S)
{
 Vector4* self = (Vector4*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ShaderMaterial (lua_State* tolua_S)
{
 ShaderMaterial* self = (ShaderMaterial*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vector2 (lua_State* tolua_S)
{
 Vector2* self = (Vector2*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Entity (lua_State* tolua_S)
{
 Entity* self = (Entity*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_LuaFrameListener (lua_State* tolua_S)
{
 LuaFrameListener* self = (LuaFrameListener*) tolua_tousertype(tolua_S,1,0);
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
 tolua_usertype(tolua_S,"Render");
 tolua_usertype(tolua_S,"Resource");
 tolua_usertype(tolua_S,"FsDict");
 tolua_usertype(tolua_S,"Color");
 tolua_usertype(tolua_S,"Window");
 tolua_usertype(tolua_S,"MaterialLoader");
 tolua_usertype(tolua_S,"RenderTarget");
 tolua_usertype(tolua_S,"SceneNode");
 tolua_usertype(tolua_S,"TextureLoader");
 tolua_usertype(tolua_S,"FsObject");
 tolua_usertype(tolua_S,"ShaderMaterial");
 tolua_usertype(tolua_S,"Entity");
 tolua_usertype(tolua_S,"LuaFrameListener");
 tolua_usertype(tolua_S,"Mesh");
 tolua_usertype(tolua_S,"Vector3");
 tolua_usertype(tolua_S,"ShaderMaterial::Uniform");
 tolua_usertype(tolua_S,"Face3");
 tolua_usertype(tolua_S,"Program");
 tolua_usertype(tolua_S,"Material");
 tolua_usertype(tolua_S,"GeometryLoader");
 tolua_usertype(tolua_S,"TexCoord2");
 tolua_usertype(tolua_S,"MeshLoader");
 tolua_usertype(tolua_S,"Geometry");
 tolua_usertype(tolua_S,"ProgramLoader");
 tolua_usertype(tolua_S,"Texture2D");
 tolua_usertype(tolua_S,"FsString");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"Frame");
 tolua_usertype(tolua_S,"Matrix4");
 tolua_usertype(tolua_S,"Vector4");
}

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
   int x = ((  int)  tolua_tonumber(tolua_S,2,0));
   int y = ((  int)  tolua_tonumber(tolua_S,3,0));
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
    int tolua_ret = (  int)  self->getWidth();
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
    int tolua_ret = (  int)  self->getHeight();
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
    int tolua_ret = (  int)  self->getPosX();
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
    int tolua_ret = (  int)  self->getPosY();
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

/* method: setFPS of class  Frame */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Frame_setFPS00
static int tolua_FsFaeris_Frame_setFPS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Frame",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Frame* self = (Frame*)  tolua_tousertype(tolua_S,1,0);
   int nu = ((  int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFPS'", NULL);
#endif
  {
   self->setFPS(nu);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFPS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFPS of class  Frame */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Frame_getFPS00
static int tolua_FsFaeris_Frame_getFPS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Frame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Frame* self = (Frame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFPS'", NULL);
#endif
  {
    int tolua_ret = (  int)  self->getFPS();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFPS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  Frame */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Frame_start00
static int tolua_FsFaeris_Frame_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Frame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Frame* self = (Frame*)  tolua_tousertype(tolua_S,1,0);
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

/* method: stop of class  Frame */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Frame_stop00
static int tolua_FsFaeris_Frame_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Frame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Frame* self = (Frame*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setInstantGap of class  Frame */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Frame_setInstantGap00
static int tolua_FsFaeris_Frame_setInstantGap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Frame",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Frame* self = (Frame*)  tolua_tousertype(tolua_S,1,0);
   long time = ((  long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setInstantGap'", NULL);
#endif
  {
   self->setInstantGap(time);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setInstantGap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstantFPS of class  Frame */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Frame_getInstantFPS00
static int tolua_FsFaeris_Frame_getInstantFPS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Frame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Frame* self = (Frame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInstantFPS'", NULL);
#endif
  {
    int tolua_ret = (  int)  self->getInstantFPS();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstantFPS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAvgFPS of class  Frame */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Frame_getAvgFPS00
static int tolua_FsFaeris_Frame_getAvgFPS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Frame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Frame* self = (Frame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAvgFPS'", NULL);
#endif
  {
    int tolua_ret = (  int)  self->getAvgFPS();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAvgFPS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addListener of class  Frame */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Frame_addListener00
static int tolua_FsFaeris_Frame_addListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Frame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"LuaFrameListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Frame* self = (Frame*)  tolua_tousertype(tolua_S,1,0);
  LuaFrameListener* l = ((LuaFrameListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addListener'", NULL);
#endif
  {
   self->addListener(l);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeListener of class  Frame */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Frame_removeListener00
static int tolua_FsFaeris_Frame_removeListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Frame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"LuaFrameListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Frame* self = (Frame*)  tolua_tousertype(tolua_S,1,0);
  LuaFrameListener* l = ((LuaFrameListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeListener'", NULL);
#endif
  {
   self->removeListener(l);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerUpdateFunc of class  LuaFrameListener */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_FrameListener_registerUpdateFunc00
static int tolua_FsFaeris_FrameListener_registerUpdateFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaFrameListener",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_fs_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaFrameListener* self = (LuaFrameListener*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION refid = ((LUA_FUNCTION)  tolua_fs_to_reffunction(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerUpdateFunc'", NULL);
#endif
  {
   self->registerUpdateFunc(refid);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerUpdateFunc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerBeginFunc of class  LuaFrameListener */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_FrameListener_registerBeginFunc00
static int tolua_FsFaeris_FrameListener_registerBeginFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaFrameListener",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_fs_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaFrameListener* self = (LuaFrameListener*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION refid = ((LUA_FUNCTION)  tolua_fs_to_reffunction(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerBeginFunc'", NULL);
#endif
  {
   self->registerBeginFunc(refid);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerBeginFunc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerEndFunc of class  LuaFrameListener */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_FrameListener_registerEndFunc00
static int tolua_FsFaeris_FrameListener_registerEndFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaFrameListener",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_fs_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaFrameListener* self = (LuaFrameListener*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION refid = ((LUA_FUNCTION)  tolua_fs_to_reffunction(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerEndFunc'", NULL);
#endif
  {
   self->registerEndFunc(refid);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerEndFunc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  LuaFrameListener */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_FrameListener_new00
static int tolua_FsFaeris_FrameListener_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaFrameListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaFrameListener* tolua_ret = (LuaFrameListener*)  Mtolua_new((LuaFrameListener)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaFrameListener");
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

/* method: new_local of class  LuaFrameListener */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_FrameListener_new00_local
static int tolua_FsFaeris_FrameListener_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaFrameListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaFrameListener* tolua_ret = (LuaFrameListener*)  Mtolua_new((LuaFrameListener)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaFrameListener");
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
  self->x = ((  float)  tolua_tonumber(tolua_S,2,0))
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
  self->y = ((  float)  tolua_tonumber(tolua_S,2,0))
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
   float fx = ((  float)  tolua_tonumber(tolua_S,2,0));
   float fy = ((  float)  tolua_tonumber(tolua_S,3,0));
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
   float fx = ((  float)  tolua_tonumber(tolua_S,2,0));
   float fy = ((  float)  tolua_tonumber(tolua_S,3,0));
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
   float k = ((  float)  tolua_tonumber(tolua_S,2,0));
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
    float tolua_ret = (  float)  self->dot(*v);
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
    float tolua_ret = (  float)  self->angle(*v);
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
    float tolua_ret = (  float)  self->length();
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
    float tolua_ret = (  float)  self->length2();
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
    bool tolua_ret = (  bool)  self->equal(*v);
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
  self->x = ((  float)  tolua_tonumber(tolua_S,2,0))
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
  self->y = ((  float)  tolua_tonumber(tolua_S,2,0))
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
  self->z = ((  float)  tolua_tonumber(tolua_S,2,0))
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
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
   float z = ((  float)  tolua_tonumber(tolua_S,4,0));
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
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
   float z = ((  float)  tolua_tonumber(tolua_S,4,0));
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
   float k = ((  float)  tolua_tonumber(tolua_S,2,0));
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
    float tolua_ret = (  float)  self->dot(*v);
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
    float tolua_ret = (  float)  self->angle(*v);
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
    float tolua_ret = (  float)  self->length();
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
    float tolua_ret = (  float)  self->length2();
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
    bool tolua_ret = (  bool)  self->equal(*v);
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
  self->x = ((  float)  tolua_tonumber(tolua_S,2,0))
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
  self->y = ((  float)  tolua_tonumber(tolua_S,2,0))
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
  self->z = ((  float)  tolua_tonumber(tolua_S,2,0))
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
  self->w = ((  float)  tolua_tonumber(tolua_S,2,0))
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
   float fx = ((  float)  tolua_tonumber(tolua_S,2,0));
   float fy = ((  float)  tolua_tonumber(tolua_S,3,0));
   float fz = ((  float)  tolua_tonumber(tolua_S,4,0));
   float fw = ((  float)  tolua_tonumber(tolua_S,5,0));
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
   float fx = ((  float)  tolua_tonumber(tolua_S,2,0));
   float fy = ((  float)  tolua_tonumber(tolua_S,3,0));
   float fz = ((  float)  tolua_tonumber(tolua_S,4,0));
   float fw = ((  float)  tolua_tonumber(tolua_S,5,0));
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
   float fx = ((  float)  tolua_tonumber(tolua_S,2,0));
   float fy = ((  float)  tolua_tonumber(tolua_S,3,0));
   float fz = ((  float)  tolua_tonumber(tolua_S,4,0));
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
   float fx = ((  float)  tolua_tonumber(tolua_S,2,0));
   float fy = ((  float)  tolua_tonumber(tolua_S,3,0));
   float fz = ((  float)  tolua_tonumber(tolua_S,4,0));
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
   float k = ((  float)  tolua_tonumber(tolua_S,2,0));
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
    float tolua_ret = (  float)  self->dot(*v);
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
    float tolua_ret = (  float)  self->length();
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
    float tolua_ret = (  float)  self->length2();
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
    bool tolua_ret = (  bool)  self->equal(*v);
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

/* function: Math::radianToAngle */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Math_radianToAngle00
static int tolua_FsFaeris_Math_radianToAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float radian = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   float tolua_ret = (float)  Math::radianToAngle(radian);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'radianToAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Math::angleToRadian */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Math_angleToRadian00
static int tolua_FsFaeris_Math_angleToRadian00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float angle = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   float tolua_ret = (float)  Math::angleToRadian(angle);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'angleToRadian'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Math::cosr */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Math_cosr00
static int tolua_FsFaeris_Math_cosr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float radian = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   float tolua_ret = (float)  Math::cosr(radian);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cosr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Math::sinr */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Math_sinr00
static int tolua_FsFaeris_Math_sinr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float radian = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   float tolua_ret = (float)  Math::sinr(radian);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sinr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Math::tanr */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Math_tanr00
static int tolua_FsFaeris_Math_tanr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float radian = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   float tolua_ret = (float)  Math::tanr(radian);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tanr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Math::acosr */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Math_acosr00
static int tolua_FsFaeris_Math_acosr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float radian = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   float tolua_ret = (float)  Math::acosr(radian);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'acosr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Math::cosa */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Math_cosa00
static int tolua_FsFaeris_Math_cosa00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float angle = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   float tolua_ret = (float)  Math::cosa(angle);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cosa'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Math::sina */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Math_sina00
static int tolua_FsFaeris_Math_sina00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float angle = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   float tolua_ret = (float)  Math::sina(angle);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sina'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Math::tana */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Math_tana00
static int tolua_FsFaeris_Math_tana00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float angle = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   float tolua_ret = (float)  Math::tana(angle);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tana'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Math::acosa */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Math_acosa00
static int tolua_FsFaeris_Math_acosa00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float angle = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   float tolua_ret = (float)  Math::acosa(angle);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'acosa'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Math::sqrt */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Math_sqrt00
static int tolua_FsFaeris_Math_sqrt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float v = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   float tolua_ret = (float)  Math::sqrt(v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sqrt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Math::abs */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Math_abs00
static int tolua_FsFaeris_Math_abs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float v = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   float tolua_ret = (float)  Math::abs(v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'abs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Math::srand */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Math_srand00
static int tolua_FsFaeris_Math_srand00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned long s = (( unsigned long)  tolua_tonumber(tolua_S,1,0));
  {
   Math::srand(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'srand'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Math::random */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Math_random00
static int tolua_FsFaeris_Math_random00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
    int tolua_ret = (  int)  Math::random();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'random'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Math::random */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Math_random01
static int tolua_FsFaeris_Math_random01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
   int begin = ((  int)  tolua_tonumber(tolua_S,1,0));
   int end = ((  int)  tolua_tonumber(tolua_S,2,0));
  {
    int tolua_ret = (  int)  Math::random(begin,end);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Math_random00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadFromMgr of class  MeshLoader */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_MeshLoader_loadFromMgr00
static int tolua_FsFaeris_MeshLoader_loadFromMgr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MeshLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Mesh* tolua_ret = (Mesh*)  MeshLoader::loadFromMgr(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Mesh");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadFromMgr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadFromMgr of class  GeometryLoader */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_GeometryLoader_loadFromMgr00
static int tolua_FsFaeris_GeometryLoader_loadFromMgr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GeometryLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Geometry* tolua_ret = (Geometry*)  GeometryLoader::loadFromMgr(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Geometry");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadFromMgr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadFromMgr of class  MaterialLoader */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_MaterialLoader_loadFromMgr00
static int tolua_FsFaeris_MaterialLoader_loadFromMgr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MaterialLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Material* tolua_ret = (Material*)  MaterialLoader::loadFromMgr(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Material");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadFromMgr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadFromMgr of class  ProgramLoader */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ProgramLoader_loadFromMgr00
static int tolua_FsFaeris_ProgramLoader_loadFromMgr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ProgramLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Program* tolua_ret = (Program*)  ProgramLoader::loadFromMgr(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Program");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadFromMgr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadFromMgr of class  TextureLoader */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_TextureLoader_loadFromMgr00
static int tolua_FsFaeris_TextureLoader_loadFromMgr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TextureLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Texture2D* tolua_ret = (Texture2D*)  TextureLoader::loadFromMgr(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Texture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadFromMgr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaterial of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_setMaterial00
static int tolua_FsFaeris_Render_setMaterial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Material",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  Material* m = ((Material*)  tolua_tousertype(tolua_S,2,0));
   bool force = ((  bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaterial'", NULL);
#endif
  {
   self->setMaterial(m,force);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaterial'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setProgram of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_setProgram00
static int tolua_FsFaeris_Render_setProgram00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Program",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  Program* prog = ((Program*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProgram'", NULL);
#endif
  {
   self->setProgram(prog);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setProgram'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRenderTarget of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_setRenderTarget00
static int tolua_FsFaeris_Render_setRenderTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  RenderTarget* target = ((RenderTarget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRenderTarget'", NULL);
#endif
  {
   self->setRenderTarget(target);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRenderTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: swapBuffers of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_swapBuffers00
static int tolua_FsFaeris_Render_swapBuffers00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'swapBuffers'", NULL);
#endif
  {
   self->swapBuffers();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'swapBuffers'.",&tolua_err);
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

/* method: getClearColor of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_getClearColor00
static int tolua_FsFaeris_Render_getClearColor00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getClearColor'", NULL);
#endif
  {
   Color tolua_ret = (Color)  self->getClearColor();
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
 tolua_error(tolua_S,"#ferror in function 'getClearColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_clear00
static int tolua_FsFaeris_Render_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
   bool color = ((  bool)  tolua_toboolean(tolua_S,2,true));
   bool depth = ((  bool)  tolua_toboolean(tolua_S,3,true));
   bool stencil = ((  bool)  tolua_toboolean(tolua_S,4,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'", NULL);
#endif
  {
   self->clear(color,depth,stencil);
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
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProjectionMatrix'", NULL);
#endif
  {
   self->setProjectionMatrix(*m);
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
   float angle = ((  float)  tolua_tonumber(tolua_S,3,0));
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

/* method: setVVertexPointer of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_setVVertexPointer00
static int tolua_FsFaeris_Render_setVVertexPointer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  Vector3* v = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  unsigned int num = (( unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVVertexPointer'", NULL);
#endif
  {
   self->setVVertexPointer(v,num);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVVertexPointer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVColorPointer of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_setVColorPointer00
static int tolua_FsFaeris_Render_setVColorPointer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  Color* c = ((Color*)  tolua_tousertype(tolua_S,2,0));
  unsigned int num = (( unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVColorPointer'", NULL);
#endif
  {
   self->setVColorPointer(c,num);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVColorPointer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVNormalPointer of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_setVNormalPointer00
static int tolua_FsFaeris_Render_setVNormalPointer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  Vector3* n = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  unsigned int num = (( unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVNormalPointer'", NULL);
#endif
  {
   self->setVNormalPointer(n,num);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVNormalPointer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVTexCoordPointer of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_setVTexCoordPointer00
static int tolua_FsFaeris_Render_setVTexCoordPointer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TexCoord2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  TexCoord2* t = ((TexCoord2*)  tolua_tousertype(tolua_S,2,0));
  unsigned int num = (( unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVTexCoordPointer'", NULL);
#endif
  {
   self->setVTexCoordPointer(t,num);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVTexCoordPointer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enableClientArray of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_enableClientArray00
static int tolua_FsFaeris_Render_enableClientArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  unsigned long flags = (( unsigned long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enableClientArray'", NULL);
#endif
  {
   self->enableClientArray(flags);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enableClientArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: disableClientArray of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_disableClientArray00
static int tolua_FsFaeris_Render_disableClientArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  unsigned long flags = (( unsigned long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'disableClientArray'", NULL);
#endif
  {
   self->disableClientArray(flags);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'disableClientArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: disableAllClientArray of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_disableAllClientArray00
static int tolua_FsFaeris_Render_disableAllClientArray00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'disableAllClientArray'", NULL);
#endif
  {
   self->disableAllClientArray();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'disableAllClientArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: disableAllAttrArray of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_disableAllAttrArray00
static int tolua_FsFaeris_Render_disableAllAttrArray00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'disableAllAttrArray'", NULL);
#endif
  {
   self->disableAllAttrArray();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'disableAllAttrArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enableAttrArray of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_enableAttrArray00
static int tolua_FsFaeris_Render_enableAttrArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enableAttrArray'", NULL);
#endif
  {
   self->enableAttrArray(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enableAttrArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enableAttrArray of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_enableAttrArray01
static int tolua_FsFaeris_Render_enableAttrArray01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FsString",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  FsString* name = ((FsString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enableAttrArray'", NULL);
#endif
  {
   self->enableAttrArray(name);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsFaeris_Render_enableAttrArray00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: disableAttrArray of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_disableAttrArray00
static int tolua_FsFaeris_Render_disableAttrArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'disableAttrArray'", NULL);
#endif
  {
   self->disableAttrArray(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'disableAttrArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: disableAttrArray of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_disableAttrArray01
static int tolua_FsFaeris_Render_disableAttrArray01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FsString",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  FsString* name = ((FsString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'disableAttrArray'", NULL);
#endif
  {
   self->disableAttrArray(name);
  }
 }
 return 0;
tolua_lerror:
 return tolua_FsFaeris_Render_disableAttrArray00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: drawFace3 of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_drawFace300
static int tolua_FsFaeris_Render_drawFace300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Face3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
  Face3* f = ((Face3*)  tolua_tousertype(tolua_S,2,0));
  unsigned int num = (( unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'drawFace3'", NULL);
#endif
  {
   self->drawFace3(f,num);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'drawFace3'.",&tolua_err);
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
   int x = ((  int)  tolua_tonumber(tolua_S,2,0));
   int y = ((  int)  tolua_tonumber(tolua_S,3,0));
   int width = ((  int)  tolua_tonumber(tolua_S,4,0));
   int height = ((  int)  tolua_tonumber(tolua_S,5,0));
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

/* method: setScissor of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_setScissor00
static int tolua_FsFaeris_Render_setScissor00(lua_State* tolua_S)
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
   int x = ((  int)  tolua_tonumber(tolua_S,2,0));
   int y = ((  int)  tolua_tonumber(tolua_S,3,0));
   int width = ((  int)  tolua_tonumber(tolua_S,4,0));
   int height = ((  int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScissor'", NULL);
#endif
  {
   self->setScissor(x,y,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScissor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enableScissorTest of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_enableScissorTest00
static int tolua_FsFaeris_Render_enableScissorTest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
   bool enable = ((  bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enableScissorTest'", NULL);
#endif
  {
   self->enableScissorTest(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enableScissorTest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enableDepthTest of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_enableDepthTest00
static int tolua_FsFaeris_Render_enableDepthTest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
   bool enable = ((  bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enableDepthTest'", NULL);
#endif
  {
   self->enableDepthTest(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enableDepthTest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDepthMask of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_setDepthMask00
static int tolua_FsFaeris_Render_setDepthMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
   bool enable = ((  bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDepthMask'", NULL);
#endif
  {
   self->setDepthMask(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDepthMask'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLineWidth of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_setLineWidth00
static int tolua_FsFaeris_Render_setLineWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
   float width = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLineWidth'", NULL);
#endif
  {
   self->setLineWidth(width);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLineWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enableFog of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_enableFog00
static int tolua_FsFaeris_Render_enableFog00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
   bool enable = ((  bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enableFog'", NULL);
#endif
  {
   self->enableFog(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enableFog'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setShadeMode of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_setShadeMode00
static int tolua_FsFaeris_Render_setShadeMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
   int mode = ((  int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setShadeMode'", NULL);
#endif
  {
   self->setShadeMode(mode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setShadeMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOpacity of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_setOpacity00
static int tolua_FsFaeris_Render_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
   float value = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOpacity'", NULL);
#endif
  {
   self->setOpacity(value);
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

/* method: setBlend of class  Render */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Render_setBlend00
static int tolua_FsFaeris_Render_setBlend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Render",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Render* self = (Render*)  tolua_tousertype(tolua_S,1,0);
   int blend_eq = ((  int)  tolua_tonumber(tolua_S,2,0));
   int factor_src = ((  int)  tolua_tonumber(tolua_S,3,0));
   int factor_dst = ((  int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBlend'", NULL);
#endif
  {
   self->setBlend(blend_eq,factor_src,factor_dst);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBlend'.",&tolua_err);
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
   float width = ((  float)  tolua_tonumber(tolua_S,4,0));
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
  unsigned char red = (( unsigned char)  tolua_tonumber(tolua_S,2,0));
  unsigned char green = (( unsigned char)  tolua_tonumber(tolua_S,3,0));
  unsigned char blue = (( unsigned char)  tolua_tonumber(tolua_S,4,0));
  unsigned char alpha = (( unsigned char)  tolua_tonumber(tolua_S,5,0));
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
  unsigned char red = (( unsigned char)  tolua_tonumber(tolua_S,2,0));
  unsigned char green = (( unsigned char)  tolua_tonumber(tolua_S,3,0));
  unsigned char blue = (( unsigned char)  tolua_tonumber(tolua_S,4,0));
  unsigned char alpha = (( unsigned char)  tolua_tonumber(tolua_S,5,0));
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
  unsigned char red = (( unsigned char)  tolua_tonumber(tolua_S,2,0));
  unsigned char green = (( unsigned char)  tolua_tonumber(tolua_S,3,0));
  unsigned char blue = (( unsigned char)  tolua_tonumber(tolua_S,4,0));
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
  unsigned char red = (( unsigned char)  tolua_tonumber(tolua_S,2,0));
  unsigned char green = (( unsigned char)  tolua_tonumber(tolua_S,3,0));
  unsigned char blue = (( unsigned char)  tolua_tonumber(tolua_S,4,0));
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
   float s = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: draw of class  Mesh */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Mesh_draw00
static int tolua_FsFaeris_Mesh_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mesh",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mesh* self = (Mesh*)  tolua_tousertype(tolua_S,1,0);
  Render* r = ((Render*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw(r);
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

/* method: getName of class  Material */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Material_getName00
static int tolua_FsFaeris_Material_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Material",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Material* self = (Material*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'", NULL);
#endif
  {
   const void* tolua_ret = (const void*)  self->getName();
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBlend of class  Material */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Material_setBlend00
static int tolua_FsFaeris_Material_setBlend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Material",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Material* self = (Material*)  tolua_tousertype(tolua_S,1,0);
   int equation = ((  int)  tolua_tonumber(tolua_S,2,0));
   int src = ((  int)  tolua_tonumber(tolua_S,3,0));
   int dst = ((  int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBlend'", NULL);
#endif
  {
   self->setBlend(equation,src,dst);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBlend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBlendEquation of class  Material */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Material_getBlendEquation00
static int tolua_FsFaeris_Material_getBlendEquation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Material",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Material* self = (Material*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBlendEquation'", NULL);
#endif
  {
    int tolua_ret = (  int)  self->getBlendEquation();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBlendEquation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBlendSrc of class  Material */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Material_getBlendSrc00
static int tolua_FsFaeris_Material_getBlendSrc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Material",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Material* self = (Material*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBlendSrc'", NULL);
#endif
  {
    int tolua_ret = (  int)  self->getBlendSrc();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBlendSrc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBlendDst of class  Material */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Material_getBlendDst00
static int tolua_FsFaeris_Material_getBlendDst00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Material",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Material* self = (Material*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBlendDst'", NULL);
#endif
  {
    int tolua_ret = (  int)  self->getBlendDst();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBlendDst'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setShadeMode of class  Material */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Material_setShadeMode00
static int tolua_FsFaeris_Material_setShadeMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Material",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Material* self = (Material*)  tolua_tousertype(tolua_S,1,0);
   int mode = ((  int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setShadeMode'", NULL);
#endif
  {
   self->setShadeMode(mode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setShadeMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getShadeMode of class  Material */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Material_getShadeMode00
static int tolua_FsFaeris_Material_getShadeMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Material",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Material* self = (Material*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getShadeMode'", NULL);
#endif
  {
    int tolua_ret = (  int)  self->getShadeMode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getShadeMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOpacity of class  Material */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Material_setOpacity00
static int tolua_FsFaeris_Material_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Material",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Material* self = (Material*)  tolua_tousertype(tolua_S,1,0);
   float opacity = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: getOpacity of class  Material */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Material_getOpacity00
static int tolua_FsFaeris_Material_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Material",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Material* self = (Material*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOpacity'", NULL);
#endif
  {
    float tolua_ret = (  float)  self->getOpacity();
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

/* method: setDepthTest of class  Material */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Material_setDepthTest00
static int tolua_FsFaeris_Material_setDepthTest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Material",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Material* self = (Material*)  tolua_tousertype(tolua_S,1,0);
   bool enable = ((  bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDepthTest'", NULL);
#endif
  {
   self->setDepthTest(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDepthTest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDepthTest of class  Material */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Material_getDepthTest00
static int tolua_FsFaeris_Material_getDepthTest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Material",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Material* self = (Material*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDepthTest'", NULL);
#endif
  {
    bool tolua_ret = (  bool)  self->getDepthTest();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDepthTest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDepthMask of class  Material */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Material_setDepthMask00
static int tolua_FsFaeris_Material_setDepthMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Material",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Material* self = (Material*)  tolua_tousertype(tolua_S,1,0);
   bool enable = ((  bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDepthMask'", NULL);
#endif
  {
   self->setDepthMask(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDepthMask'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDepthMask of class  Material */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Material_getDepthMask00
static int tolua_FsFaeris_Material_getDepthMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Material",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Material* self = (Material*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDepthMask'", NULL);
#endif
  {
    bool tolua_ret = (  bool)  self->getDepthMask();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDepthMask'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFrontSide of class  Material */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Material_setFrontSide00
static int tolua_FsFaeris_Material_setFrontSide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Material",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Material* self = (Material*)  tolua_tousertype(tolua_S,1,0);
   int type = ((  int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFrontSide'", NULL);
#endif
  {
   self->setFrontSide(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFrontSide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrontSide of class  Material */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Material_getFrontSide00
static int tolua_FsFaeris_Material_getFrontSide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Material",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Material* self = (Material*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrontSide'", NULL);
#endif
  {
    int tolua_ret = (  int)  self->getFrontSide();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFrontSide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: load of class  Material */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Material_load00
static int tolua_FsFaeris_Material_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Material",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Material* self = (Material*)  tolua_tousertype(tolua_S,1,0);
  Render* r = ((Render*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'load'", NULL);
#endif
  {
   self->load(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unload of class  Material */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Material_unload00
static int tolua_FsFaeris_Material_unload00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Material",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Material* self = (Material*)  tolua_tousertype(tolua_S,1,0);
  Render* r = ((Render*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unload'", NULL);
#endif
  {
   self->unload(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unload'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Uniform */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_Uniform_new00
static int tolua_FsFaeris_ShaderMaterial_Uniform_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ShaderMaterial::Uniform",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FsString",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FsString* name = ((FsString*)  tolua_tousertype(tolua_S,2,0));
  int type = ((int)  tolua_tonumber(tolua_S,3,0));
  int count = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   ShaderMaterial::Uniform* tolua_ret = (ShaderMaterial::Uniform*)  Mtolua_new((ShaderMaterial::Uniform)(name,type,count));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ShaderMaterial::Uniform");
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

/* method: new_local of class  Uniform */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_Uniform_new00_local
static int tolua_FsFaeris_ShaderMaterial_Uniform_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ShaderMaterial::Uniform",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FsString",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FsString* name = ((FsString*)  tolua_tousertype(tolua_S,2,0));
  int type = ((int)  tolua_tonumber(tolua_S,3,0));
  int count = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   ShaderMaterial::Uniform* tolua_ret = (ShaderMaterial::Uniform*)  Mtolua_new((ShaderMaterial::Uniform)(name,type,count));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ShaderMaterial::Uniform");
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

/* method: setShadeMode of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setShadeMode00
static int tolua_FsFaeris_ShaderMaterial_setShadeMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  int mode = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setShadeMode'", NULL);
#endif
  {
   self->setShadeMode(mode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setShadeMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enableWireFrame of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_enableWireFrame00
static int tolua_FsFaeris_ShaderMaterial_enableWireFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
   bool enable = ((  bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enableWireFrame'", NULL);
#endif
  {
   self->enableWireFrame(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enableWireFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWireFrameWidth of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setWireFrameWidth00
static int tolua_FsFaeris_ShaderMaterial_setWireFrameWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWireFrameWidth'", NULL);
#endif
  {
   self->setWireFrameWidth(width);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWireFrameWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setProgram of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setProgram00
static int tolua_FsFaeris_ShaderMaterial_setProgram00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Program",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  Program* prog = ((Program*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProgram'", NULL);
#endif
  {
   self->setProgram(prog);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setProgram'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setProgramSourceName of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setProgramSourceName00
static int tolua_FsFaeris_ShaderMaterial_setProgramSourceName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FsString",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  FsString* name = ((FsString*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProgramSourceName'", NULL);
#endif
  {
   self->setProgramSourceName(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setProgramSourceName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getProgramSourceName of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_getProgramSourceName00
static int tolua_FsFaeris_ShaderMaterial_getProgramSourceName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProgramSourceName'", NULL);
#endif
  {
   FsString* tolua_ret = (FsString*)  self->getProgramSourceName();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FsString");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProgramSourceName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform1i of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform1i00
static int tolua_FsFaeris_ShaderMaterial_setUniform1i00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int v = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform1i'", NULL);
#endif
  {
   self->setUniform1i(name,v);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform1i'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform2i of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform2i00
static int tolua_FsFaeris_ShaderMaterial_setUniform2i00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int v1 = ((int)  tolua_tonumber(tolua_S,3,0));
  int v2 = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform2i'", NULL);
#endif
  {
   self->setUniform2i(name,v1,v2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform2i'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform3i of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform3i00
static int tolua_FsFaeris_ShaderMaterial_setUniform3i00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int v1 = ((int)  tolua_tonumber(tolua_S,3,0));
  int v2 = ((int)  tolua_tonumber(tolua_S,4,0));
  int v3 = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform3i'", NULL);
#endif
  {
   self->setUniform3i(name,v1,v2,v3);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform3i'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform4i of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform4i00
static int tolua_FsFaeris_ShaderMaterial_setUniform4i00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int v1 = ((int)  tolua_tonumber(tolua_S,3,0));
  int v2 = ((int)  tolua_tonumber(tolua_S,4,0));
  int v3 = ((int)  tolua_tonumber(tolua_S,5,0));
  int v4 = ((int)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform4i'", NULL);
#endif
  {
   self->setUniform4i(name,v1,v2,v3,v4);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform4i'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform1f of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform1f00
static int tolua_FsFaeris_ShaderMaterial_setUniform1f00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  float v = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform1f'", NULL);
#endif
  {
   self->setUniform1f(name,v);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform1f'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform2f of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform2f00
static int tolua_FsFaeris_ShaderMaterial_setUniform2f00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  float v1 = ((float)  tolua_tonumber(tolua_S,3,0));
  float v2 = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform2f'", NULL);
#endif
  {
   self->setUniform2f(name,v1,v2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform2f'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform3f of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform3f00
static int tolua_FsFaeris_ShaderMaterial_setUniform3f00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  float v1 = ((float)  tolua_tonumber(tolua_S,3,0));
  float v2 = ((float)  tolua_tonumber(tolua_S,4,0));
  float v3 = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform3f'", NULL);
#endif
  {
   self->setUniform3f(name,v1,v2,v3);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform3f'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform4f of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform4f00
static int tolua_FsFaeris_ShaderMaterial_setUniform4f00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  float v1 = ((float)  tolua_tonumber(tolua_S,3,0));
  float v2 = ((float)  tolua_tonumber(tolua_S,4,0));
  float v3 = ((float)  tolua_tonumber(tolua_S,5,0));
  float v4 = ((float)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform4f'", NULL);
#endif
  {
   self->setUniform4f(name,v1,v2,v3,v4);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform4f'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform1ui of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform1ui00
static int tolua_FsFaeris_ShaderMaterial_setUniform1ui00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned int v = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform1ui'", NULL);
#endif
  {
   self->setUniform1ui(name,v);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform1ui'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform2ui of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform2ui00
static int tolua_FsFaeris_ShaderMaterial_setUniform2ui00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned int v1 = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int v2 = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform2ui'", NULL);
#endif
  {
   self->setUniform2ui(name,v1,v2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform2ui'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform3ui of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform3ui00
static int tolua_FsFaeris_ShaderMaterial_setUniform3ui00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned int v1 = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int v2 = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  unsigned int v3 = ((unsigned int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform3ui'", NULL);
#endif
  {
   self->setUniform3ui(name,v1,v2,v3);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform3ui'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform4ui of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform4ui00
static int tolua_FsFaeris_ShaderMaterial_setUniform4ui00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned int v1 = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int v2 = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  unsigned int v3 = ((unsigned int)  tolua_tonumber(tolua_S,5,0));
  unsigned int v4 = ((unsigned int)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform4ui'", NULL);
#endif
  {
   self->setUniform4ui(name,v1,v2,v3,v4);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform4ui'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform1iv of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform1iv00
static int tolua_FsFaeris_ShaderMaterial_setUniform1iv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_istable(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int count = ((int)  tolua_tonumber(tolua_S,3,0));
#ifdef __cplusplus
  int* v = Mtolua_new_dim(int, count);
#else
  int* v = (int*) malloc((count)*sizeof(int));
#endif
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform1iv'", NULL);
#endif
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isnumberarray(tolua_S,4,count,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<count;i++)
    v[i] = ((int)  tolua_tofieldnumber(tolua_S,4,i+1,0));
   }
  }
  {
   self->setUniform1iv(name,count,v);
  }
#ifdef __cplusplus
  Mtolua_delete_dim(v);
#else
  free(v);
#endif
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform1iv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform2iv of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform2iv00
static int tolua_FsFaeris_ShaderMaterial_setUniform2iv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_istable(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int count = ((int)  tolua_tonumber(tolua_S,3,0));
#ifdef __cplusplus
  int* v = Mtolua_new_dim(int, count*2);
#else
  int* v = (int*) malloc((count*2)*sizeof(int));
#endif
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform2iv'", NULL);
#endif
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isnumberarray(tolua_S,4,count*2,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<count*2;i++)
    v[i] = ((int)  tolua_tofieldnumber(tolua_S,4,i+1,0));
   }
  }
  {
   self->setUniform2iv(name,count,v);
  }
#ifdef __cplusplus
  Mtolua_delete_dim(v);
#else
  free(v);
#endif
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform2iv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform3iv of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform3iv00
static int tolua_FsFaeris_ShaderMaterial_setUniform3iv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_istable(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int count = ((int)  tolua_tonumber(tolua_S,3,0));
#ifdef __cplusplus
  int* v = Mtolua_new_dim(int, count*3);
#else
  int* v = (int*) malloc((count*3)*sizeof(int));
#endif
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform3iv'", NULL);
#endif
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isnumberarray(tolua_S,4,count*3,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<count*3;i++)
    v[i] = ((int)  tolua_tofieldnumber(tolua_S,4,i+1,0));
   }
  }
  {
   self->setUniform3iv(name,count,v);
  }
#ifdef __cplusplus
  Mtolua_delete_dim(v);
#else
  free(v);
#endif
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform3iv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform4iv of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform4iv00
static int tolua_FsFaeris_ShaderMaterial_setUniform4iv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_istable(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int count = ((int)  tolua_tonumber(tolua_S,3,0));
#ifdef __cplusplus
  int* v = Mtolua_new_dim(int, count*4);
#else
  int* v = (int*) malloc((count*4)*sizeof(int));
#endif
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform4iv'", NULL);
#endif
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isnumberarray(tolua_S,4,count*4,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<count*4;i++)
    v[i] = ((int)  tolua_tofieldnumber(tolua_S,4,i+1,0));
   }
  }
  {
   self->setUniform4iv(name,count,v);
  }
#ifdef __cplusplus
  Mtolua_delete_dim(v);
#else
  free(v);
#endif
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform4iv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform1fv of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform1fv00
static int tolua_FsFaeris_ShaderMaterial_setUniform1fv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_istable(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int count = ((int)  tolua_tonumber(tolua_S,3,0));
#ifdef __cplusplus
  float* v = Mtolua_new_dim(float, count);
#else
  float* v = (float*) malloc((count)*sizeof(float));
#endif
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform1fv'", NULL);
#endif
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isnumberarray(tolua_S,4,count,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<count;i++)
    v[i] = ((float)  tolua_tofieldnumber(tolua_S,4,i+1,0));
   }
  }
  {
   self->setUniform1fv(name,count,v);
  }
#ifdef __cplusplus
  Mtolua_delete_dim(v);
#else
  free(v);
#endif
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform1fv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform2fv of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform2fv00
static int tolua_FsFaeris_ShaderMaterial_setUniform2fv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_istable(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int count = ((int)  tolua_tonumber(tolua_S,3,0));
#ifdef __cplusplus
  float* v = Mtolua_new_dim(float, count*2);
#else
  float* v = (float*) malloc((count*2)*sizeof(float));
#endif
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform2fv'", NULL);
#endif
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isnumberarray(tolua_S,4,count*2,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<count*2;i++)
    v[i] = ((float)  tolua_tofieldnumber(tolua_S,4,i+1,0));
   }
  }
  {
   self->setUniform2fv(name,count,v);
  }
#ifdef __cplusplus
  Mtolua_delete_dim(v);
#else
  free(v);
#endif
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform2fv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform3fv of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform3fv00
static int tolua_FsFaeris_ShaderMaterial_setUniform3fv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_istable(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int count = ((int)  tolua_tonumber(tolua_S,3,0));
#ifdef __cplusplus
  float* v = Mtolua_new_dim(float, count*3);
#else
  float* v = (float*) malloc((count*3)*sizeof(float));
#endif
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform3fv'", NULL);
#endif
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isnumberarray(tolua_S,4,count*3,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<count*3;i++)
    v[i] = ((float)  tolua_tofieldnumber(tolua_S,4,i+1,0));
   }
  }
  {
   self->setUniform3fv(name,count,v);
  }
#ifdef __cplusplus
  Mtolua_delete_dim(v);
#else
  free(v);
#endif
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform3fv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform4fv of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform4fv00
static int tolua_FsFaeris_ShaderMaterial_setUniform4fv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_istable(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int count = ((int)  tolua_tonumber(tolua_S,3,0));
#ifdef __cplusplus
  float* v = Mtolua_new_dim(float, count*4);
#else
  float* v = (float*) malloc((count*4)*sizeof(float));
#endif
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform4fv'", NULL);
#endif
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isnumberarray(tolua_S,4,count*4,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<count*4;i++)
    v[i] = ((float)  tolua_tofieldnumber(tolua_S,4,i+1,0));
   }
  }
  {
   self->setUniform4fv(name,count,v);
  }
#ifdef __cplusplus
  Mtolua_delete_dim(v);
#else
  free(v);
#endif
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform4fv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform1uiv of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform1uiv00
static int tolua_FsFaeris_ShaderMaterial_setUniform1uiv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_istable(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int count = ((int)  tolua_tonumber(tolua_S,3,0));
#ifdef __cplusplus
  unsigned int* v = Mtolua_new_dim(unsigned int, count);
#else
  unsigned int* v = (int*) malloc((count)*sizeof(int));
#endif
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform1uiv'", NULL);
#endif
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isnumberarray(tolua_S,4,count,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<count;i++)
    v[i] = ((int)  tolua_tofieldnumber(tolua_S,4,i+1,0));
   }
  }
  {
   self->setUniform1uiv(name,count,v);
  }
#ifdef __cplusplus
  Mtolua_delete_dim(v);
#else
  free(v);
#endif
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform1uiv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform2uiv of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform2uiv00
static int tolua_FsFaeris_ShaderMaterial_setUniform2uiv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_istable(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int count = ((int)  tolua_tonumber(tolua_S,3,0));
#ifdef __cplusplus
  unsigned int* v = Mtolua_new_dim(unsigned int, count*2);
#else
  unsigned int* v = (int*) malloc((count*2)*sizeof(int));
#endif
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform2uiv'", NULL);
#endif
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isnumberarray(tolua_S,4,count*2,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<count*2;i++)
    v[i] = ((int)  tolua_tofieldnumber(tolua_S,4,i+1,0));
   }
  }
  {
   self->setUniform2uiv(name,count,v);
  }
#ifdef __cplusplus
  Mtolua_delete_dim(v);
#else
  free(v);
#endif
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform2uiv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform3uiv of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform3uiv00
static int tolua_FsFaeris_ShaderMaterial_setUniform3uiv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_istable(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int count = ((int)  tolua_tonumber(tolua_S,3,0));
#ifdef __cplusplus
  unsigned int* v = Mtolua_new_dim(unsigned int, count*3);
#else
  unsigned int* v = (int*) malloc((count*3)*sizeof(int));
#endif
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform3uiv'", NULL);
#endif
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isnumberarray(tolua_S,4,count*3,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<count*3;i++)
    v[i] = ((int)  tolua_tofieldnumber(tolua_S,4,i+1,0));
   }
  }
  {
   self->setUniform3uiv(name,count,v);
  }
#ifdef __cplusplus
  Mtolua_delete_dim(v);
#else
  free(v);
#endif
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform3uiv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUniform4uiv of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_setUniform4uiv00
static int tolua_FsFaeris_ShaderMaterial_setUniform4uiv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_istable(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int count = ((int)  tolua_tonumber(tolua_S,3,0));
#ifdef __cplusplus
  unsigned int* v = Mtolua_new_dim(unsigned int, count*4);
#else
  unsigned int* v = (int*) malloc((count*4)*sizeof(int));
#endif
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUniform4uiv'", NULL);
#endif
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isnumberarray(tolua_S,4,count*4,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<count*4;i++)
    v[i] = ((int)  tolua_tofieldnumber(tolua_S,4,i+1,0));
   }
  }
  {
   self->setUniform4uiv(name,count,v);
  }
#ifdef __cplusplus
  Mtolua_delete_dim(v);
#else
  free(v);
#endif
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUniform4uiv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addUniform of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_addUniform00
static int tolua_FsFaeris_ShaderMaterial_addUniform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ShaderMaterial::Uniform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  ShaderMaterial::Uniform* u = ((ShaderMaterial::Uniform*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addUniform'", NULL);
#endif
  {
   self->addUniform(u);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addUniform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getUniforms of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_getUniforms00
static int tolua_FsFaeris_ShaderMaterial_getUniforms00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUniforms'", NULL);
#endif
  {
   FsDict* tolua_ret = (FsDict*)  self->getUniforms();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FsDict");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUniforms'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_new00
static int tolua_FsFaeris_ShaderMaterial_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ShaderMaterial* tolua_ret = (ShaderMaterial*)  Mtolua_new((ShaderMaterial)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ShaderMaterial");
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

/* method: new_local of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_new00_local
static int tolua_FsFaeris_ShaderMaterial_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ShaderMaterial* tolua_ret = (ShaderMaterial*)  Mtolua_new((ShaderMaterial)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ShaderMaterial");
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

/* method: delete of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_delete00
static int tolua_FsFaeris_ShaderMaterial_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getName of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_getName00
static int tolua_FsFaeris_ShaderMaterial_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getName();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: load of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_load00
static int tolua_FsFaeris_ShaderMaterial_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  Render* r = ((Render*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'load'", NULL);
#endif
  {
   self->load(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unload of class  ShaderMaterial */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_ShaderMaterial_unload00
static int tolua_FsFaeris_ShaderMaterial_unload00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShaderMaterial",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShaderMaterial* self = (ShaderMaterial*)  tolua_tousertype(tolua_S,1,0);
  Render* r = ((Render*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unload'", NULL);
#endif
  {
   self->unload(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unload'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_new00
static int tolua_FsFaeris_SceneNode_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SceneNode* tolua_ret = (SceneNode*)  Mtolua_new((SceneNode)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneNode");
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

/* method: new_local of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_new00_local
static int tolua_FsFaeris_SceneNode_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SceneNode* tolua_ret = (SceneNode*)  Mtolua_new((SceneNode)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneNode");
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

/* method: update of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_update00
static int tolua_FsFaeris_SceneNode_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   long msec = ((  long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(msec);
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

/* method: updateSelf of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_updateSelf00
static int tolua_FsFaeris_SceneNode_updateSelf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   long mesc = ((  long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateSelf'", NULL);
#endif
  {
   self->updateSelf(mesc);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateSelf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_draw00
static int tolua_FsFaeris_SceneNode_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
  Render* r = ((Render*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw(r);
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

/* method: drawSelf of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_drawSelf00
static int tolua_FsFaeris_SceneNode_drawSelf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Render",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
  Render* r = ((Render*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'drawSelf'", NULL);
#endif
  {
   self->drawSelf(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'drawSelf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: localToWorld of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_localToWorld00
static int tolua_FsFaeris_SceneNode_localToWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: worldToLocal of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_worldToLocal00
static int tolua_FsFaeris_SceneNode_worldToLocal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: addChild of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_addChild00
static int tolua_FsFaeris_SceneNode_addChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
  SceneNode* n = ((SceneNode*)  tolua_tousertype(tolua_S,2,0));
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

/* method: remove of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_remove00
static int tolua_FsFaeris_SceneNode_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
  SceneNode* n = ((SceneNode*)  tolua_tousertype(tolua_S,2,0));
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

/* method: updateLocalMatrix of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_updateLocalMatrix00
static int tolua_FsFaeris_SceneNode_updateLocalMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateLocalMatrix'", NULL);
#endif
  {
   self->updateLocalMatrix();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateLocalMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateWorldMatrix of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_updateWorldMatrix00
static int tolua_FsFaeris_SceneNode_updateWorldMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateWorldMatrix'", NULL);
#endif
  {
   self->updateWorldMatrix();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateWorldMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateAllWorldMatrix of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_updateAllWorldMatrix00
static int tolua_FsFaeris_SceneNode_updateAllWorldMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateAllWorldMatrix'", NULL);
#endif
  {
   self->updateAllWorldMatrix();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateAllWorldMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosition of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_getPosition00
static int tolua_FsFaeris_SceneNode_getPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getScale of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_getScale00
static int tolua_FsFaeris_SceneNode_getScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getRotate of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_getRotate00
static int tolua_FsFaeris_SceneNode_getRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: rotate of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_rotate00
static int tolua_FsFaeris_SceneNode_rotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float rx = ((  float)  tolua_tonumber(tolua_S,2,0));
   float ry = ((  float)  tolua_tonumber(tolua_S,3,0));
   float rz = ((  float)  tolua_tonumber(tolua_S,4,0));
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

/* method: rotateX of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_rotateX00
static int tolua_FsFaeris_SceneNode_rotateX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float r = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: rotateY of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_rotateY00
static int tolua_FsFaeris_SceneNode_rotateY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float r = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: rotateZ of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_rotateZ00
static int tolua_FsFaeris_SceneNode_rotateZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float r = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: scale of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_scale00
static int tolua_FsFaeris_SceneNode_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float sx = ((  float)  tolua_tonumber(tolua_S,2,0));
   float sy = ((  float)  tolua_tonumber(tolua_S,3,0));
   float sz = ((  float)  tolua_tonumber(tolua_S,4,0));
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

/* method: scaleX of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_scaleX00
static int tolua_FsFaeris_SceneNode_scaleX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float s = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: scaleY of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_scaleY00
static int tolua_FsFaeris_SceneNode_scaleY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float s = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: scaleZ of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_scaleZ00
static int tolua_FsFaeris_SceneNode_scaleZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float s = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: move of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_move00
static int tolua_FsFaeris_SceneNode_move00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float tx = ((  float)  tolua_tonumber(tolua_S,2,0));
   float ty = ((  float)  tolua_tonumber(tolua_S,3,0));
   float tz = ((  float)  tolua_tonumber(tolua_S,4,0));
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

/* method: moveX of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_moveX00
static int tolua_FsFaeris_SceneNode_moveX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float t = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: moveY of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_moveY00
static int tolua_FsFaeris_SceneNode_moveY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float t = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: moveZ of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_moveZ00
static int tolua_FsFaeris_SceneNode_moveZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float t = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: setRotate of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_setRotate00
static int tolua_FsFaeris_SceneNode_setRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float rx = ((  float)  tolua_tonumber(tolua_S,2,0));
   float ry = ((  float)  tolua_tonumber(tolua_S,3,0));
   float rz = ((  float)  tolua_tonumber(tolua_S,4,0));
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

/* method: setRotateX of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_setRotateX00
static int tolua_FsFaeris_SceneNode_setRotateX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float r = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: setRotateY of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_setRotateY00
static int tolua_FsFaeris_SceneNode_setRotateY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float r = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: setRotateZ of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_setRotateZ00
static int tolua_FsFaeris_SceneNode_setRotateZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float r = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: setScale of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_setScale00
static int tolua_FsFaeris_SceneNode_setScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float sx = ((  float)  tolua_tonumber(tolua_S,2,0));
   float sy = ((  float)  tolua_tonumber(tolua_S,3,0));
   float sz = ((  float)  tolua_tonumber(tolua_S,4,0));
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

/* method: setScaleX of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_setScaleX00
static int tolua_FsFaeris_SceneNode_setScaleX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float s = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: setScaleY of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_setScaleY00
static int tolua_FsFaeris_SceneNode_setScaleY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float s = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: setScaleZ of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_setScaleZ00
static int tolua_FsFaeris_SceneNode_setScaleZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float s = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: setPosition of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_setPosition00
static int tolua_FsFaeris_SceneNode_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float tx = ((  float)  tolua_tonumber(tolua_S,2,0));
   float ty = ((  float)  tolua_tonumber(tolua_S,3,0));
   float tz = ((  float)  tolua_tonumber(tolua_S,4,0));
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

/* method: setPositionX of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_setPositionX00
static int tolua_FsFaeris_SceneNode_setPositionX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float t = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: setPositionY of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_setPositionY00
static int tolua_FsFaeris_SceneNode_setPositionY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float t = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: setPositionZ of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_setPositionZ00
static int tolua_FsFaeris_SceneNode_setPositionZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float t = ((  float)  tolua_tonumber(tolua_S,2,0));
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

/* method: hide of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_hide00
static int tolua_FsFaeris_SceneNode_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: show of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_show00
static int tolua_FsFaeris_SceneNode_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getVisible of class  SceneNode */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_SceneNode_getVisible00
static int tolua_FsFaeris_SceneNode_getVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneNode* self = (SceneNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVisible'", NULL);
#endif
  {
    bool tolua_ret = (  bool)  self->getVisible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Entity_new00
static int tolua_FsFaeris_Entity_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Mesh",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mesh* m = ((Mesh*)  tolua_tousertype(tolua_S,2,0));
  {
   Entity* tolua_ret = (Entity*)  Mtolua_new((Entity)(m));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Entity");
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

/* method: new_local of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Entity_new00_local
static int tolua_FsFaeris_Entity_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Mesh",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mesh* m = ((Mesh*)  tolua_tousertype(tolua_S,2,0));
  {
   Entity* tolua_ret = (Entity*)  Mtolua_new((Entity)(m));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Entity");
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

/* method: new of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Entity_new01
static int tolua_FsFaeris_Entity_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Entity* tolua_ret = (Entity*)  Mtolua_new((Entity)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Entity");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Entity_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Entity_new01_local
static int tolua_FsFaeris_Entity_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Entity* tolua_ret = (Entity*)  Mtolua_new((Entity)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Entity");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsFaeris_Entity_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMesh of class  Entity */
#ifndef TOLUA_DISABLE_tolua_FsFaeris_Entity_setMesh00
static int tolua_FsFaeris_Entity_setMesh00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Mesh",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  Mesh* m = ((Mesh*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMesh'", NULL);
#endif
  {
   self->setMesh(m);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMesh'.",&tolua_err);
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
  tolua_cclass(tolua_S,"FsObject","FsObject","",NULL);
  tolua_beginmodule(tolua_S,"FsObject");
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"FS",0);
  tolua_beginmodule(tolua_S,"FS");
   tolua_constant(tolua_S,"EULER_XYZ",FS_EULER_XYZ);
   tolua_constant(tolua_S,"EULER_XZY",FS_EULER_XZY);
   tolua_constant(tolua_S,"EULER_YXZ",FS_EULER_YXZ);
   tolua_constant(tolua_S,"EULER_YZX",FS_EULER_YZX);
   tolua_constant(tolua_S,"EULER_ZXY",FS_EULER_ZXY);
   tolua_constant(tolua_S,"EULER_ZYX",FS_EULER_ZYX);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Resource","Resource","FsObject",NULL);
  tolua_beginmodule(tolua_S,"Resource");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Window","Window","FsObject",NULL);
  tolua_beginmodule(tolua_S,"Window");
   tolua_constant(tolua_S,"STYLE_MAXBOX",Window::STYLE_MAXBOX);
   tolua_constant(tolua_S,"STYLE_MINBOX",Window::STYLE_MINBOX);
   tolua_constant(tolua_S,"STYLE_CLOSEBOX",Window::STYLE_CLOSEBOX);
   tolua_function(tolua_S,"setCaption",tolua_FsFaeris_Window_setCaption00);
   tolua_function(tolua_S,"getCaption",tolua_FsFaeris_Window_getCaption00);
   tolua_function(tolua_S,"setPosition",tolua_FsFaeris_Window_setPosition00);
   tolua_function(tolua_S,"setSize",tolua_FsFaeris_Window_setSize00);
   tolua_function(tolua_S,"show",tolua_FsFaeris_Window_show00);
   tolua_function(tolua_S,"hide",tolua_FsFaeris_Window_hide00);
   tolua_function(tolua_S,"getWidth",tolua_FsFaeris_Window_getWidth00);
   tolua_function(tolua_S,"getHeight",tolua_FsFaeris_Window_getHeight00);
   tolua_function(tolua_S,"getPosX",tolua_FsFaeris_Window_getPosX00);
   tolua_function(tolua_S,"getPosY",tolua_FsFaeris_Window_getPosY00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Frame","Frame","",NULL);
  tolua_beginmodule(tolua_S,"Frame");
   tolua_function(tolua_S,"setFPS",tolua_FsFaeris_Frame_setFPS00);
   tolua_function(tolua_S,"getFPS",tolua_FsFaeris_Frame_getFPS00);
   tolua_function(tolua_S,"start",tolua_FsFaeris_Frame_start00);
   tolua_function(tolua_S,"stop",tolua_FsFaeris_Frame_stop00);
   tolua_function(tolua_S,"setInstantGap",tolua_FsFaeris_Frame_setInstantGap00);
   tolua_function(tolua_S,"getInstantFPS",tolua_FsFaeris_Frame_getInstantFPS00);
   tolua_function(tolua_S,"getAvgFPS",tolua_FsFaeris_Frame_getAvgFPS00);
   tolua_function(tolua_S,"addListener",tolua_FsFaeris_Frame_addListener00);
   tolua_function(tolua_S,"removeListener",tolua_FsFaeris_Frame_removeListener00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"FrameListener","LuaFrameListener","",tolua_collect_LuaFrameListener);
  #else
  tolua_cclass(tolua_S,"FrameListener","LuaFrameListener","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"FrameListener");
   tolua_function(tolua_S,"registerUpdateFunc",tolua_FsFaeris_FrameListener_registerUpdateFunc00);
   tolua_function(tolua_S,"registerBeginFunc",tolua_FsFaeris_FrameListener_registerBeginFunc00);
   tolua_function(tolua_S,"registerEndFunc",tolua_FsFaeris_FrameListener_registerEndFunc00);
   tolua_function(tolua_S,"new",tolua_FsFaeris_FrameListener_new00);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_FrameListener_new00_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_FrameListener_new00_local);
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
  tolua_module(tolua_S,"Math",0);
  tolua_beginmodule(tolua_S,"Math");
   tolua_function(tolua_S,"radianToAngle",tolua_FsFaeris_Math_radianToAngle00);
   tolua_function(tolua_S,"angleToRadian",tolua_FsFaeris_Math_angleToRadian00);
   tolua_function(tolua_S,"cosr",tolua_FsFaeris_Math_cosr00);
   tolua_function(tolua_S,"sinr",tolua_FsFaeris_Math_sinr00);
   tolua_function(tolua_S,"tanr",tolua_FsFaeris_Math_tanr00);
   tolua_function(tolua_S,"acosr",tolua_FsFaeris_Math_acosr00);
   tolua_function(tolua_S,"cosa",tolua_FsFaeris_Math_cosa00);
   tolua_function(tolua_S,"sina",tolua_FsFaeris_Math_sina00);
   tolua_function(tolua_S,"tana",tolua_FsFaeris_Math_tana00);
   tolua_function(tolua_S,"acosa",tolua_FsFaeris_Math_acosa00);
   tolua_function(tolua_S,"sqrt",tolua_FsFaeris_Math_sqrt00);
   tolua_function(tolua_S,"abs",tolua_FsFaeris_Math_abs00);
   tolua_function(tolua_S,"srand",tolua_FsFaeris_Math_srand00);
   tolua_function(tolua_S,"random",tolua_FsFaeris_Math_random00);
   tolua_function(tolua_S,"random",tolua_FsFaeris_Math_random01);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MeshLoader","MeshLoader","",NULL);
  tolua_beginmodule(tolua_S,"MeshLoader");
   tolua_function(tolua_S,"loadFromMgr",tolua_FsFaeris_MeshLoader_loadFromMgr00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"GeometryLoader","GeometryLoader","",NULL);
  tolua_beginmodule(tolua_S,"GeometryLoader");
   tolua_function(tolua_S,"loadFromMgr",tolua_FsFaeris_GeometryLoader_loadFromMgr00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MaterialLoader","MaterialLoader","",NULL);
  tolua_beginmodule(tolua_S,"MaterialLoader");
   tolua_function(tolua_S,"loadFromMgr",tolua_FsFaeris_MaterialLoader_loadFromMgr00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ProgramLoader","ProgramLoader","",NULL);
  tolua_beginmodule(tolua_S,"ProgramLoader");
   tolua_function(tolua_S,"loadFromMgr",tolua_FsFaeris_ProgramLoader_loadFromMgr00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TextureLoader","TextureLoader","",NULL);
  tolua_beginmodule(tolua_S,"TextureLoader");
   tolua_function(tolua_S,"loadFromMgr",tolua_FsFaeris_TextureLoader_loadFromMgr00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Render","Render","",NULL);
  tolua_beginmodule(tolua_S,"Render");
   tolua_constant(tolua_S,"VERTEX_ARRAY",Render::VERTEX_ARRAY);
   tolua_constant(tolua_S,"COLOR_ARRAY",Render::COLOR_ARRAY);
   tolua_constant(tolua_S,"NORMAL_ARRAY",Render::NORMAL_ARRAY);
   tolua_constant(tolua_S,"TEXTURE_COORD_ARRAY",Render::TEXTURE_COORD_ARRAY);
   tolua_constant(tolua_S,"ALL_ARRAY",Render::ALL_ARRAY);
   tolua_constant(tolua_S,"U_F_1",Render::U_F_1);
   tolua_constant(tolua_S,"U_F_2",Render::U_F_2);
   tolua_constant(tolua_S,"U_F_3",Render::U_F_3);
   tolua_constant(tolua_S,"U_F_4",Render::U_F_4);
   tolua_constant(tolua_S,"U_I_1",Render::U_I_1);
   tolua_constant(tolua_S,"U_I_2",Render::U_I_2);
   tolua_constant(tolua_S,"U_I_3",Render::U_I_3);
   tolua_constant(tolua_S,"U_I_4",Render::U_I_4);
   tolua_constant(tolua_S,"U_UI_1",Render::U_UI_1);
   tolua_constant(tolua_S,"U_UI_2",Render::U_UI_2);
   tolua_constant(tolua_S,"U_UI_3",Render::U_UI_3);
   tolua_constant(tolua_S,"U_UI_4",Render::U_UI_4);
   tolua_constant(tolua_S,"U_M_2",Render::U_M_2);
   tolua_constant(tolua_S,"U_M_3",Render::U_M_3);
   tolua_constant(tolua_S,"U_M_4",Render::U_M_4);
   tolua_constant(tolua_S,"U_S_1D",Render::U_S_1D);
   tolua_constant(tolua_S,"U_S_2D",Render::U_S_2D);
   tolua_constant(tolua_S,"U_S_3D",Render::U_S_3D);
   tolua_constant(tolua_S,"U_S_CUBE",Render::U_S_CUBE);
   tolua_constant(tolua_S,"U_S_1D_SHADOW",Render::U_S_1D_SHADOW);
   tolua_constant(tolua_S,"U_S_2D_SHADOW",Render::U_S_2D_SHADOW);
   tolua_constant(tolua_S,"U_MAX_NU",Render::U_MAX_NU);
   tolua_constant(tolua_S,"FRONT_CCW",Render::FRONT_CCW);
   tolua_constant(tolua_S,"FRONT_CW",Render::FRONT_CW);
   tolua_constant(tolua_S,"SHADE_MODE_SMOOTH",Render::SHADE_MODE_SMOOTH);
   tolua_constant(tolua_S,"SHADE_MODE_FLAT",Render::SHADE_MODE_FLAT);
   tolua_constant(tolua_S,"SIDE_FRONT",Render::SIDE_FRONT);
   tolua_constant(tolua_S,"SIDE_BACK",Render::SIDE_BACK);
   tolua_constant(tolua_S,"SIDE_FRONT_AND_BACK",Render::SIDE_FRONT_AND_BACK);
   tolua_constant(tolua_S,"SIDE_NONE",Render::SIDE_NONE);
   tolua_constant(tolua_S,"EQUATION_NONE",Render::EQUATION_NONE);
   tolua_constant(tolua_S,"EQUATION_ADD",Render::EQUATION_ADD);
   tolua_constant(tolua_S,"EQUATION_SUBTRACT",Render::EQUATION_SUBTRACT);
   tolua_constant(tolua_S,"EQUATION_REVERSE_SUBTRACT",Render::EQUATION_REVERSE_SUBTRACT);
   tolua_constant(tolua_S,"EQUATION_MIN",Render::EQUATION_MIN);
   tolua_constant(tolua_S,"EQUATION_MAX",Render::EQUATION_MAX);
   tolua_constant(tolua_S,"EQUATION_LOGIC_OP",Render::EQUATION_LOGIC_OP);
   tolua_constant(tolua_S,"FACTOR_ZERO",Render::FACTOR_ZERO);
   tolua_constant(tolua_S,"FACTOR_ONE",Render::FACTOR_ONE);
   tolua_constant(tolua_S,"FACTOR_SRC_COLOR",Render::FACTOR_SRC_COLOR);
   tolua_constant(tolua_S,"FACTOR_ONE_MINUS_SRC_COLOR",Render::FACTOR_ONE_MINUS_SRC_COLOR);
   tolua_constant(tolua_S,"FACTOR_DST_COLOR",Render::FACTOR_DST_COLOR);
   tolua_constant(tolua_S,"FACTOR_ONE_MINUS_DST_COLOR",Render::FACTOR_ONE_MINUS_DST_COLOR);
   tolua_constant(tolua_S,"FACTOR_SRC_ALPHA",Render::FACTOR_SRC_ALPHA);
   tolua_constant(tolua_S,"FACTOR_ONE_MINUS_SRC_ALPHA",Render::FACTOR_ONE_MINUS_SRC_ALPHA);
   tolua_constant(tolua_S,"FACTOR_DST_ALPHA",Render::FACTOR_DST_ALPHA);
   tolua_constant(tolua_S,"FACTOR_ONE_MINUS_DST_ALPHA",Render::FACTOR_ONE_MINUS_DST_ALPHA);
   tolua_constant(tolua_S,"FACTOR_SRC_ALPHA_SATURATE",Render::FACTOR_SRC_ALPHA_SATURATE);
   tolua_function(tolua_S,"setMaterial",tolua_FsFaeris_Render_setMaterial00);
   tolua_function(tolua_S,"setProgram",tolua_FsFaeris_Render_setProgram00);
   tolua_function(tolua_S,"setRenderTarget",tolua_FsFaeris_Render_setRenderTarget00);
   tolua_function(tolua_S,"swapBuffers",tolua_FsFaeris_Render_swapBuffers00);
   tolua_function(tolua_S,"setClearColor",tolua_FsFaeris_Render_setClearColor00);
   tolua_function(tolua_S,"getClearColor",tolua_FsFaeris_Render_getClearColor00);
   tolua_function(tolua_S,"clear",tolua_FsFaeris_Render_clear00);
   tolua_function(tolua_S,"pushMatrix",tolua_FsFaeris_Render_pushMatrix00);
   tolua_function(tolua_S,"popMatrix",tolua_FsFaeris_Render_popMatrix00);
   tolua_function(tolua_S,"loadIdentity",tolua_FsFaeris_Render_loadIdentity00);
   tolua_function(tolua_S,"setProjectionMatrix",tolua_FsFaeris_Render_setProjectionMatrix00);
   tolua_function(tolua_S,"mulMatrix",tolua_FsFaeris_Render_mulMatrix00);
   tolua_function(tolua_S,"setMatrix",tolua_FsFaeris_Render_setMatrix00);
   tolua_function(tolua_S,"translate",tolua_FsFaeris_Render_translate00);
   tolua_function(tolua_S,"scale",tolua_FsFaeris_Render_scale00);
   tolua_function(tolua_S,"rotate",tolua_FsFaeris_Render_rotate00);
   tolua_function(tolua_S,"setVVertexPointer",tolua_FsFaeris_Render_setVVertexPointer00);
   tolua_function(tolua_S,"setVColorPointer",tolua_FsFaeris_Render_setVColorPointer00);
   tolua_function(tolua_S,"setVNormalPointer",tolua_FsFaeris_Render_setVNormalPointer00);
   tolua_function(tolua_S,"setVTexCoordPointer",tolua_FsFaeris_Render_setVTexCoordPointer00);
   tolua_function(tolua_S,"enableClientArray",tolua_FsFaeris_Render_enableClientArray00);
   tolua_function(tolua_S,"disableClientArray",tolua_FsFaeris_Render_disableClientArray00);
   tolua_function(tolua_S,"disableAllClientArray",tolua_FsFaeris_Render_disableAllClientArray00);
   tolua_function(tolua_S,"disableAllAttrArray",tolua_FsFaeris_Render_disableAllAttrArray00);
   tolua_function(tolua_S,"enableAttrArray",tolua_FsFaeris_Render_enableAttrArray00);
   tolua_function(tolua_S,"enableAttrArray",tolua_FsFaeris_Render_enableAttrArray01);
   tolua_function(tolua_S,"disableAttrArray",tolua_FsFaeris_Render_disableAttrArray00);
   tolua_function(tolua_S,"disableAttrArray",tolua_FsFaeris_Render_disableAttrArray01);
   tolua_function(tolua_S,"drawFace3",tolua_FsFaeris_Render_drawFace300);
   tolua_function(tolua_S,"setViewport",tolua_FsFaeris_Render_setViewport00);
   tolua_function(tolua_S,"setScissor",tolua_FsFaeris_Render_setScissor00);
   tolua_function(tolua_S,"enableScissorTest",tolua_FsFaeris_Render_enableScissorTest00);
   tolua_function(tolua_S,"enableDepthTest",tolua_FsFaeris_Render_enableDepthTest00);
   tolua_function(tolua_S,"setDepthMask",tolua_FsFaeris_Render_setDepthMask00);
   tolua_function(tolua_S,"setLineWidth",tolua_FsFaeris_Render_setLineWidth00);
   tolua_function(tolua_S,"enableFog",tolua_FsFaeris_Render_enableFog00);
   tolua_function(tolua_S,"setShadeMode",tolua_FsFaeris_Render_setShadeMode00);
   tolua_function(tolua_S,"setOpacity",tolua_FsFaeris_Render_setOpacity00);
   tolua_function(tolua_S,"setBlend",tolua_FsFaeris_Render_setBlend00);
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
  tolua_cclass(tolua_S,"Mesh","Mesh","Resource",NULL);
  tolua_beginmodule(tolua_S,"Mesh");
   tolua_constant(tolua_S,"TYPE_STATIC",Mesh::TYPE_STATIC);
   tolua_constant(tolua_S,"TYPE_SHAPE",Mesh::TYPE_SHAPE);
   tolua_constant(tolua_S,"TYPE_SKELETON",Mesh::TYPE_SKELETON);
   tolua_function(tolua_S,"draw",tolua_FsFaeris_Mesh_draw00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Material","Material","FsObject",NULL);
  tolua_beginmodule(tolua_S,"Material");
   tolua_function(tolua_S,"getName",tolua_FsFaeris_Material_getName00);
   tolua_function(tolua_S,"setBlend",tolua_FsFaeris_Material_setBlend00);
   tolua_function(tolua_S,"getBlendEquation",tolua_FsFaeris_Material_getBlendEquation00);
   tolua_function(tolua_S,"getBlendSrc",tolua_FsFaeris_Material_getBlendSrc00);
   tolua_function(tolua_S,"getBlendDst",tolua_FsFaeris_Material_getBlendDst00);
   tolua_function(tolua_S,"setShadeMode",tolua_FsFaeris_Material_setShadeMode00);
   tolua_function(tolua_S,"getShadeMode",tolua_FsFaeris_Material_getShadeMode00);
   tolua_function(tolua_S,"setOpacity",tolua_FsFaeris_Material_setOpacity00);
   tolua_function(tolua_S,"getOpacity",tolua_FsFaeris_Material_getOpacity00);
   tolua_function(tolua_S,"setDepthTest",tolua_FsFaeris_Material_setDepthTest00);
   tolua_function(tolua_S,"getDepthTest",tolua_FsFaeris_Material_getDepthTest00);
   tolua_function(tolua_S,"setDepthMask",tolua_FsFaeris_Material_setDepthMask00);
   tolua_function(tolua_S,"getDepthMask",tolua_FsFaeris_Material_getDepthMask00);
   tolua_function(tolua_S,"setFrontSide",tolua_FsFaeris_Material_setFrontSide00);
   tolua_function(tolua_S,"getFrontSide",tolua_FsFaeris_Material_getFrontSide00);
   tolua_function(tolua_S,"load",tolua_FsFaeris_Material_load00);
   tolua_function(tolua_S,"unload",tolua_FsFaeris_Material_unload00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"ShaderMaterial","ShaderMaterial","Material",tolua_collect_ShaderMaterial);
  #else
  tolua_cclass(tolua_S,"ShaderMaterial","ShaderMaterial","Material",NULL);
  #endif
  tolua_beginmodule(tolua_S,"ShaderMaterial");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Uniform","ShaderMaterial::Uniform","FsObject",tolua_collect_ShaderMaterial__Uniform);
   #else
   tolua_cclass(tolua_S,"Uniform","ShaderMaterial::Uniform","FsObject",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Uniform");
    tolua_function(tolua_S,"new",tolua_FsFaeris_ShaderMaterial_Uniform_new00);
    tolua_function(tolua_S,"new_local",tolua_FsFaeris_ShaderMaterial_Uniform_new00_local);
    tolua_function(tolua_S,".call",tolua_FsFaeris_ShaderMaterial_Uniform_new00_local);
   tolua_endmodule(tolua_S);
   tolua_function(tolua_S,"setShadeMode",tolua_FsFaeris_ShaderMaterial_setShadeMode00);
   tolua_function(tolua_S,"enableWireFrame",tolua_FsFaeris_ShaderMaterial_enableWireFrame00);
   tolua_function(tolua_S,"setWireFrameWidth",tolua_FsFaeris_ShaderMaterial_setWireFrameWidth00);
   tolua_function(tolua_S,"setProgram",tolua_FsFaeris_ShaderMaterial_setProgram00);
   tolua_function(tolua_S,"setProgramSourceName",tolua_FsFaeris_ShaderMaterial_setProgramSourceName00);
   tolua_function(tolua_S,"getProgramSourceName",tolua_FsFaeris_ShaderMaterial_getProgramSourceName00);
   tolua_function(tolua_S,"setUniform1i",tolua_FsFaeris_ShaderMaterial_setUniform1i00);
   tolua_function(tolua_S,"setUniform2i",tolua_FsFaeris_ShaderMaterial_setUniform2i00);
   tolua_function(tolua_S,"setUniform3i",tolua_FsFaeris_ShaderMaterial_setUniform3i00);
   tolua_function(tolua_S,"setUniform4i",tolua_FsFaeris_ShaderMaterial_setUniform4i00);
   tolua_function(tolua_S,"setUniform1f",tolua_FsFaeris_ShaderMaterial_setUniform1f00);
   tolua_function(tolua_S,"setUniform2f",tolua_FsFaeris_ShaderMaterial_setUniform2f00);
   tolua_function(tolua_S,"setUniform3f",tolua_FsFaeris_ShaderMaterial_setUniform3f00);
   tolua_function(tolua_S,"setUniform4f",tolua_FsFaeris_ShaderMaterial_setUniform4f00);
   tolua_function(tolua_S,"setUniform1ui",tolua_FsFaeris_ShaderMaterial_setUniform1ui00);
   tolua_function(tolua_S,"setUniform2ui",tolua_FsFaeris_ShaderMaterial_setUniform2ui00);
   tolua_function(tolua_S,"setUniform3ui",tolua_FsFaeris_ShaderMaterial_setUniform3ui00);
   tolua_function(tolua_S,"setUniform4ui",tolua_FsFaeris_ShaderMaterial_setUniform4ui00);
   tolua_function(tolua_S,"setUniform1iv",tolua_FsFaeris_ShaderMaterial_setUniform1iv00);
   tolua_function(tolua_S,"setUniform2iv",tolua_FsFaeris_ShaderMaterial_setUniform2iv00);
   tolua_function(tolua_S,"setUniform3iv",tolua_FsFaeris_ShaderMaterial_setUniform3iv00);
   tolua_function(tolua_S,"setUniform4iv",tolua_FsFaeris_ShaderMaterial_setUniform4iv00);
   tolua_function(tolua_S,"setUniform1fv",tolua_FsFaeris_ShaderMaterial_setUniform1fv00);
   tolua_function(tolua_S,"setUniform2fv",tolua_FsFaeris_ShaderMaterial_setUniform2fv00);
   tolua_function(tolua_S,"setUniform3fv",tolua_FsFaeris_ShaderMaterial_setUniform3fv00);
   tolua_function(tolua_S,"setUniform4fv",tolua_FsFaeris_ShaderMaterial_setUniform4fv00);
   tolua_function(tolua_S,"setUniform1uiv",tolua_FsFaeris_ShaderMaterial_setUniform1uiv00);
   tolua_function(tolua_S,"setUniform2uiv",tolua_FsFaeris_ShaderMaterial_setUniform2uiv00);
   tolua_function(tolua_S,"setUniform3uiv",tolua_FsFaeris_ShaderMaterial_setUniform3uiv00);
   tolua_function(tolua_S,"setUniform4uiv",tolua_FsFaeris_ShaderMaterial_setUniform4uiv00);
   tolua_function(tolua_S,"addUniform",tolua_FsFaeris_ShaderMaterial_addUniform00);
   tolua_function(tolua_S,"getUniforms",tolua_FsFaeris_ShaderMaterial_getUniforms00);
   tolua_function(tolua_S,"new",tolua_FsFaeris_ShaderMaterial_new00);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_ShaderMaterial_new00_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_ShaderMaterial_new00_local);
   tolua_function(tolua_S,"delete",tolua_FsFaeris_ShaderMaterial_delete00);
   tolua_function(tolua_S,"getName",tolua_FsFaeris_ShaderMaterial_getName00);
   tolua_function(tolua_S,"load",tolua_FsFaeris_ShaderMaterial_load00);
   tolua_function(tolua_S,"unload",tolua_FsFaeris_ShaderMaterial_unload00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"SceneNode","SceneNode","",tolua_collect_SceneNode);
  #else
  tolua_cclass(tolua_S,"SceneNode","SceneNode","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"SceneNode");
   tolua_function(tolua_S,"new",tolua_FsFaeris_SceneNode_new00);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_SceneNode_new00_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_SceneNode_new00_local);
   tolua_function(tolua_S,"update",tolua_FsFaeris_SceneNode_update00);
   tolua_function(tolua_S,"updateSelf",tolua_FsFaeris_SceneNode_updateSelf00);
   tolua_function(tolua_S,"draw",tolua_FsFaeris_SceneNode_draw00);
   tolua_function(tolua_S,"drawSelf",tolua_FsFaeris_SceneNode_drawSelf00);
   tolua_function(tolua_S,"localToWorld",tolua_FsFaeris_SceneNode_localToWorld00);
   tolua_function(tolua_S,"worldToLocal",tolua_FsFaeris_SceneNode_worldToLocal00);
   tolua_function(tolua_S,"addChild",tolua_FsFaeris_SceneNode_addChild00);
   tolua_function(tolua_S,"remove",tolua_FsFaeris_SceneNode_remove00);
   tolua_function(tolua_S,"updateLocalMatrix",tolua_FsFaeris_SceneNode_updateLocalMatrix00);
   tolua_function(tolua_S,"updateWorldMatrix",tolua_FsFaeris_SceneNode_updateWorldMatrix00);
   tolua_function(tolua_S,"updateAllWorldMatrix",tolua_FsFaeris_SceneNode_updateAllWorldMatrix00);
   tolua_function(tolua_S,"getPosition",tolua_FsFaeris_SceneNode_getPosition00);
   tolua_function(tolua_S,"getScale",tolua_FsFaeris_SceneNode_getScale00);
   tolua_function(tolua_S,"getRotate",tolua_FsFaeris_SceneNode_getRotate00);
   tolua_function(tolua_S,"rotate",tolua_FsFaeris_SceneNode_rotate00);
   tolua_function(tolua_S,"rotateX",tolua_FsFaeris_SceneNode_rotateX00);
   tolua_function(tolua_S,"rotateY",tolua_FsFaeris_SceneNode_rotateY00);
   tolua_function(tolua_S,"rotateZ",tolua_FsFaeris_SceneNode_rotateZ00);
   tolua_function(tolua_S,"scale",tolua_FsFaeris_SceneNode_scale00);
   tolua_function(tolua_S,"scaleX",tolua_FsFaeris_SceneNode_scaleX00);
   tolua_function(tolua_S,"scaleY",tolua_FsFaeris_SceneNode_scaleY00);
   tolua_function(tolua_S,"scaleZ",tolua_FsFaeris_SceneNode_scaleZ00);
   tolua_function(tolua_S,"move",tolua_FsFaeris_SceneNode_move00);
   tolua_function(tolua_S,"moveX",tolua_FsFaeris_SceneNode_moveX00);
   tolua_function(tolua_S,"moveY",tolua_FsFaeris_SceneNode_moveY00);
   tolua_function(tolua_S,"moveZ",tolua_FsFaeris_SceneNode_moveZ00);
   tolua_function(tolua_S,"setRotate",tolua_FsFaeris_SceneNode_setRotate00);
   tolua_function(tolua_S,"setRotateX",tolua_FsFaeris_SceneNode_setRotateX00);
   tolua_function(tolua_S,"setRotateY",tolua_FsFaeris_SceneNode_setRotateY00);
   tolua_function(tolua_S,"setRotateZ",tolua_FsFaeris_SceneNode_setRotateZ00);
   tolua_function(tolua_S,"setScale",tolua_FsFaeris_SceneNode_setScale00);
   tolua_function(tolua_S,"setScaleX",tolua_FsFaeris_SceneNode_setScaleX00);
   tolua_function(tolua_S,"setScaleY",tolua_FsFaeris_SceneNode_setScaleY00);
   tolua_function(tolua_S,"setScaleZ",tolua_FsFaeris_SceneNode_setScaleZ00);
   tolua_function(tolua_S,"setPosition",tolua_FsFaeris_SceneNode_setPosition00);
   tolua_function(tolua_S,"setPositionX",tolua_FsFaeris_SceneNode_setPositionX00);
   tolua_function(tolua_S,"setPositionY",tolua_FsFaeris_SceneNode_setPositionY00);
   tolua_function(tolua_S,"setPositionZ",tolua_FsFaeris_SceneNode_setPositionZ00);
   tolua_function(tolua_S,"hide",tolua_FsFaeris_SceneNode_hide00);
   tolua_function(tolua_S,"show",tolua_FsFaeris_SceneNode_show00);
   tolua_function(tolua_S,"getVisible",tolua_FsFaeris_SceneNode_getVisible00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Entity","Entity","SceneNode",tolua_collect_Entity);
  #else
  tolua_cclass(tolua_S,"Entity","Entity","SceneNode",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Entity");
   tolua_function(tolua_S,"new",tolua_FsFaeris_Entity_new00);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Entity_new00_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Entity_new00_local);
   tolua_function(tolua_S,"new",tolua_FsFaeris_Entity_new01);
   tolua_function(tolua_S,"new_local",tolua_FsFaeris_Entity_new01_local);
   tolua_function(tolua_S,".call",tolua_FsFaeris_Entity_new01_local);
   tolua_function(tolua_S,"setMesh",tolua_FsFaeris_Entity_setMesh00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_FsFaeris (lua_State* tolua_S) {
 return tolua_FsFaeris_open(tolua_S);
};
#endif

