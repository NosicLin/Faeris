/*
** Lua binding: FsLibAudio
** Generated automatically by tolua++-1.0.92 on 06/15/13 15:42:13.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_FsLibAudio_open (lua_State* tolua_S);

#include "FsAudioEngine.h"
#include "FsLuaExport.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Channel");
 toluaext_usertype(tolua_S,"FsObject");
 toluaext_usertype(tolua_S,"AudioEngine");
}

/* method: create of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibAudio_AudioEngine_create00
static int tolua_FsLibAudio_AudioEngine_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   AudioEngine* tolua_ret = (AudioEngine*)  AudioEngine::create();
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"AudioEngine");
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

/* method: create of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibAudio_AudioEngine_create01
static int tolua_FsLibAudio_AudioEngine_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int channel_nu = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   AudioEngine* tolua_ret = (AudioEngine*)  AudioEngine::create(channel_nu);
    toluaext_pushfsobject2(tolua_S,(void*)tolua_ret,"AudioEngine");
  }
 }
 return 1;
tolua_lerror:
 return tolua_FsLibAudio_AudioEngine_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadSound of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibAudio_AudioEngine_loadSound00
static int tolua_FsLibAudio_AudioEngine_loadSound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadSound'", NULL);
#endif
  {
   int tolua_ret = (int)  self->loadSound(name);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadSound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unloadSound of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibAudio_AudioEngine_unloadSound00
static int tolua_FsLibAudio_AudioEngine_unloadSound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unloadSound'", NULL);
#endif
  {
   int tolua_ret = (int)  self->unloadSound(name);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unloadSound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unloadSounds of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibAudio_AudioEngine_unloadSounds00
static int tolua_FsLibAudio_AudioEngine_unloadSounds00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unloadSounds'", NULL);
#endif
  {
   int tolua_ret = (int)  self->unloadSounds();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unloadSounds'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playSound of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibAudio_AudioEngine_playSound00
static int tolua_FsLibAudio_AudioEngine_playSound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int loop = ((int)  tolua_tonumber(tolua_S,3,0));
  int priority = ((int)  tolua_tonumber(tolua_S,4,AudioEngine::PRIORITY_MIDDLE));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playSound'", NULL);
#endif
  {
   Channel* tolua_ret = (Channel*)  self->playSound(name,loop,priority);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Channel");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playSound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pauseChannel of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibAudio_AudioEngine_pauseChannel00
static int tolua_FsLibAudio_AudioEngine_pauseChannel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Channel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  Channel* c = ((Channel*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pauseChannel'", NULL);
#endif
  {
   self->pauseChannel(c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pauseChannel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resumeChannel of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibAudio_AudioEngine_resumeChannel00
static int tolua_FsLibAudio_AudioEngine_resumeChannel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Channel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  Channel* c = ((Channel*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resumeChannel'", NULL);
#endif
  {
   self->resumeChannel(c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resumeChannel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopChannel of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibAudio_AudioEngine_stopChannel00
static int tolua_FsLibAudio_AudioEngine_stopChannel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Channel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  Channel* c = ((Channel*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopChannel'", NULL);
#endif
  {
   self->stopChannel(c);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopChannel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setChannelVolume of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibAudio_AudioEngine_setChannelVolume00
static int tolua_FsLibAudio_AudioEngine_setChannelVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Channel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  Channel* c = ((Channel*)  tolua_tousertype(tolua_S,2,0));
  float value = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setChannelVolume'", NULL);
#endif
  {
   self->setChannelVolume(c,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setChannelVolume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getChannelVolume of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibAudio_AudioEngine_getChannelVolume00
static int tolua_FsLibAudio_AudioEngine_getChannelVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Channel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  Channel* c = ((Channel*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getChannelVolume'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getChannelVolume(c);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getChannelVolume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pauseChannels of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibAudio_AudioEngine_pauseChannels00
static int tolua_FsLibAudio_AudioEngine_pauseChannels00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pauseChannels'", NULL);
#endif
  {
   self->pauseChannels();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pauseChannels'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resumeChannels of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibAudio_AudioEngine_resumeChannels00
static int tolua_FsLibAudio_AudioEngine_resumeChannels00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resumeChannels'", NULL);
#endif
  {
   self->resumeChannels();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resumeChannels'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopChannnels of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibAudio_AudioEngine_stopChannnels00
static int tolua_FsLibAudio_AudioEngine_stopChannnels00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopChannnels'", NULL);
#endif
  {
   self->stopChannnels();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopChannnels'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVolume of class  AudioEngine */
#ifndef TOLUA_DISABLE_tolua_FsLibAudio_AudioEngine_setVolume00
static int tolua_FsLibAudio_AudioEngine_setVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioEngine",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioEngine* self = (AudioEngine*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVolume'", NULL);
#endif
  {
   self->setVolume(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVolume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_FsLibAudio_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"AudioEngine","AudioEngine","FsObject",toluaext_fscollector);
  tolua_beginmodule(tolua_S,"AudioEngine");
   tolua_function(tolua_S,"create",tolua_FsLibAudio_AudioEngine_create00);
   tolua_function(tolua_S,"create",tolua_FsLibAudio_AudioEngine_create01);
   tolua_function(tolua_S,"loadSound",tolua_FsLibAudio_AudioEngine_loadSound00);
   tolua_function(tolua_S,"unloadSound",tolua_FsLibAudio_AudioEngine_unloadSound00);
   tolua_function(tolua_S,"unloadSounds",tolua_FsLibAudio_AudioEngine_unloadSounds00);
   tolua_function(tolua_S,"playSound",tolua_FsLibAudio_AudioEngine_playSound00);
   tolua_function(tolua_S,"pauseChannel",tolua_FsLibAudio_AudioEngine_pauseChannel00);
   tolua_function(tolua_S,"resumeChannel",tolua_FsLibAudio_AudioEngine_resumeChannel00);
   tolua_function(tolua_S,"stopChannel",tolua_FsLibAudio_AudioEngine_stopChannel00);
   tolua_function(tolua_S,"setChannelVolume",tolua_FsLibAudio_AudioEngine_setChannelVolume00);
   tolua_function(tolua_S,"getChannelVolume",tolua_FsLibAudio_AudioEngine_getChannelVolume00);
   tolua_function(tolua_S,"pauseChannels",tolua_FsLibAudio_AudioEngine_pauseChannels00);
   tolua_function(tolua_S,"resumeChannels",tolua_FsLibAudio_AudioEngine_resumeChannels00);
   tolua_function(tolua_S,"stopChannnels",tolua_FsLibAudio_AudioEngine_stopChannnels00);
   tolua_function(tolua_S,"setVolume",tolua_FsLibAudio_AudioEngine_setVolume00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_FsLibAudio (lua_State* tolua_S) {
 return tolua_FsLibAudio_open(tolua_S);
};
#endif

