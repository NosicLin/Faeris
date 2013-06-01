LOCAL_PATH :=$(call my-dir)

IMPORT_PATH := $(LOCAL_PATH)

include $(CLEAR_VARS)

LOCAL_MODULE := luaexport_static

LOCAL_CFLAGS     :=  -I$(LOCAL_PATH)/../src \
					 -I$(LOCAL_PATH)/../src/luaext \
					 -I$(LOCAL_PATH)/../../../platform/thirdparty/linux/lua \
					 -I$(LOCAL_PATH)/../../../platform/thirdparty/linux/tolua++ \
					 -I$(LOCAL_PATH)/../../../platform/thirdparty/linux/fmod \
					 -I$(LOCAL_PATH)/../../../libfaeris/src \
					 -I$(LOCAL_PATH)/../../../libfaeris/src/support  \
					 -I$(LOCAL_PATH)/../../libaudio/src


LOCAL_SRC_FILES :=  ../src/toluaext++.cc \
					../src/luaext/FsLuaScene.cc \
					../src/luaext/FsLuaSysEventListener.cc \
					../src/luaext/FsLuaTouchEventListener.cc \
					../src/FsLuaEngine.cc \
					../src/luaexport/FsLibAudioExport.cc \
					../src/luaexport/FsLibFaerisExport.cc \
					../src/luaexport/FsLibLuaScript.cc \
					../src/luaexport/FsLuaFuncExport.cc \



					 



include $(BUILD_STATIC_LIBRARY)









