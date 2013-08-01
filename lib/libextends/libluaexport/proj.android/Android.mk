LOCAL_PATH :=$(call my-dir)

IMPORT_PATH := $(LOCAL_PATH)

include $(CLEAR_VARS)

LOCAL_MODULE := luaexport_static


LOCAL_CFLAGS     :=  -I$(LOCAL_PATH)/../src \
					 -I$(LOCAL_PATH)/../src/luaext \
					 -I$(LOCAL_PATH)/../../../lib3rdparty/lua/include \
					 -I$(LOCAL_PATH)/../../../lib3rdparty/tolua++/include \
					 -I$(LOCAL_PATH)/../../../lib3rdparty/fmod/include \
					 -I$(LOCAL_PATH)/../../../libfaeris/src \
					 -I$(LOCAL_PATH)/../../../libfaeris/src/support  \
					 -I$(LOCAL_PATH)/../../libaudio/src \
					 -I$(LOCAL_PATH)/../../libnetwork/src \
					 -I$(LOCAL_PATH)/../../libspinesprite/src 


LOCAL_SRC_FILES :=  ../src/toluaext++.cc \
					../src/luaext/FsLuaScene.cc \
					../src/luaext/FsLuaSysEventListener.cc \
					../src/luaext/FsLuaTouchEventListener.cc \
					../src/luaext/FsLuaHttpRequest.cc \
					../src/FsLuaEngine.cc \
					../src/luaexport/FsLibFaerisExport.cc \
					../src/luaexport/FsLibLuaScript.cc \
					../src/luaexport/FsLuaFuncExport.cc \
					../src/luaexport/FsLibSpineSprite.cc \



					 



include $(BUILD_STATIC_LIBRARY)









