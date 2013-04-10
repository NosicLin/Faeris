LOCAL_PATH :=$(call my-dir)

IMPORT_PATH := $(LOCAL_PATH)

include $(CLEAR_VARS)

LOCAL_MODULE := faeris

LOCAL_SRC_FILES :=  ../../src/tolua_ext.cc \
					../../src/luaext/FsLuaScene.cc \
					../../src/luaext/FsLuaSysEventListener.cc \
					../../src/luaext/FsLuaTouchEventListener.cc \
					../../src/FsLuaEngine.cc \
					../../src/FsLuaFaeris.cc \
					../../src/platform/FsAndroidMain.cc \


LOCAL_C_INCLUDES :=  -I../../../  \
					 -I../../../src \
					 -I../../../src/luaext \
					 -I../../../../../platform/thirdparty/linux/lua \
					 -I../../../../../platform/thirdparty/linux/tolua++ \
					 -I../../../../../src \
					 -I../../../../../src/support  \
					 


LOCAL_WHOLE_STATIC_LIBRARIES := zlib_static 
LOCAL_WHOLE_STATIC_LIBRARIES += freetype_static 
LOCAL_WHOLE_STATIC_LIBRARIES += minizip_static 
LOCAL_WHOLE_STATIC_LIBRARIES += libpng_static
LOCAL_WHOLE_STATIC_LIBRARIES += lua_static 
LOCAL_WHOLE_STATIC_LIBRARIES += tolua_static
LOCAL_WHOLE_STATIC_LIBRARIES += faeris_static 

LOCAL_LDLIBS    += -llog -lGLESv2  -lEGL


include $(BUILD_SHARED_LIBRARY)

$(call import-add-path,$(IMPORT_PATH))
$(call import-module,../../../../platform/proj.android/faeris/jni)
$(call import-module,../../../../platform/proj.android/freetype/jni)
$(call import-module,../../../../platform/proj.android/libpng/jni)
$(call import-module,../../../../platform/proj.android/zlib/jni)
$(call import-module,../../../../platform/proj.android/minizip/jni)
$(call import-module,../../../../platform/proj.android/lua/jni)
$(call import-module,../../../../platform/proj.android/tolua++/jni)








