LOCAL_PATH :=$(call my-dir)../

include $(CLEAR_VARS)

LOCAL_MODULE :=faeris_lua_static 


LOCAL_C_INCLUDES:= -I../  \
	-I../src \
	-I../src/luaext \
	-I../../../platform/thirdparty/linux/lua \
	-I../../../platform/thirdparty/linux/tolua++ \
	-I../../../src \
	-I../../../src/support  \


LOCAL_SRC_FILES:= ../src/FsLuaEngine.cc \
	../src/FsLuaFaeris.cc \
	../src/tolua_ext.cc \
	../src/main.cc  \
	../src/luaext/FsLuaScene.cc  \
	../src/luaext/FsLuaSysEventListener.cc \
	../src/luaext/FsLuaTouchEventListener.cc \


include $(BUILD_SHARE_LIBRARY)

