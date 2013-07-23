# Normal Information 
CC=gcc
FILE_EXT=cc

FLAGS_DEBUG= -g -Wall  -DLINUX
FLAGS_RELEASE= -O3 -DTOLUA_RELEASE  -DLINUX

#Project infor 
PROJECT_PATH= ../../../library/linux/
PROJECT=luaexport

SRC_DIR=../src
INCLUDE_DIR=-I../src \
			-I../../../libfaeris/src \
			-I../../../lib3rdparty/tolua++/include \
			-I../../../lib3rdparty/lua/include \
			-I../../../libextends/libaudio/src \
			-I../../../libextends/libnetwork/src \
			-I../../../libextends/libspinesprite/src \


#Source File 
SRC=  luaexport/FsLibAudioExport.cc \
	  luaexport/FsLibNetworkExport.cc \
	  luaexport/FsLibSpineSprite.cc \
	  luaexport/FsLibFaerisExport.cc \
	  luaexport/FsLibLuaScript.cc \
	  luaexport/FsLuaFuncExport.cc \
	  luaext/FsLuaScene.cc \
	  luaext/FsLuaSysEventListener.cc \
	  luaext/FsLuaTouchEventListener.cc \
	  luaext/FsLuaHttpRequest.cc \
	  FsLuaEngine.cc \
	  toluaext++.cc  \
	

include ../../../MK_BUILD_STATIC_LIB 


	 

