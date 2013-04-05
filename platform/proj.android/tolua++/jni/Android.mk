LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE :=tolua_static 

LOCAL_SRC_FILES := ../tolua_event.c \
				   ../tolua_is.c \
				   ../tolua_map.c \
				   ../tolua_push.c \
				   ../tolua_to.c \


LOCAL_C_INCLUDES := ../  \
					../../../platform/thirdparty/android/lua \

include $(BUILD_STATIC_LIBRARY)

