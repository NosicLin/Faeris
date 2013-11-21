LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := lib3rdextends_static
LOCAL_CFLAGS := -I$(LOCAL_PATH)/../../src  \
				-I$(LOCAL_PATH)/../../../../libfaeris/src \
				-I$(LOCAL_PATH)/../../../../lib3rdparty/Box2D \




LOCAL_SRC_FILES := \
	../../src/box2d/fb2Draw.cc 


include $(BUILD_STATIC_LIBRARY)
