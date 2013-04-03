LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)


LOCAL_MODULE :=minizip_static

LOCAL_SRC_FILES := ../ioapi.c  \
				   ../unzip.c \

LOCAL_C_INCLUDES := ../ 


include $(BUILD_STATIC_LIBRARY)



