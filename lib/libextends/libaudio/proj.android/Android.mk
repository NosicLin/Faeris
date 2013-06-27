LOCAL_PATH :=$(call my-dir)

IMPORT_PATH := $(LOCAL_PATH)

include $(CLEAR_VARS)

LOCAL_MODULE := audio_static

LOCAL_CFLAGS     :=  -I$(LOCAL_PATH)/../src \
					 -I$(LOCAL_PATH)/../src/luaext \
					 -I$(LOCAL_PATH)/../../../platform/thirdparty/android/lua \
					 -I$(LOCAL_PATH)/../../../platform/thirdparty/android/tolua++ \
					 -I$(LOCAL_PATH)/../../../platform/thirdparty/android/ \
					 -I$(LOCAL_PATH)/../../../libfaeris/src \
					 -I$(LOCAL_PATH)/../../../libfaeris/src/support  \
					 -I$(LOCAL_PATH)/../../libaudio/src


LOCAL_SRC_FILES :=  ../src/FsAudioEngine.cc \
				    ../src/FsAudioPlayer.cc \




					 



include $(BUILD_STATIC_LIBRARY)









