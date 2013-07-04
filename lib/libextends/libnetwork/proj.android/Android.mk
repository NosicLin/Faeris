LOCAL_PATH :=$(call my-dir)

IMPORT_PATH := $(LOCAL_PATH)

include $(CLEAR_VARS)

LOCAL_MODULE := network_static

LOCAL_CFLAGS     :=  -I$(LOCAL_PATH)/../src \
					 -I$(LOCAL_PATH)/../../../lib3rdparty/curl/include \
					 -I$(LOCAL_PATH)/../../../libfaeris/src \
					 -I$(LOCAL_PATH)/../../../libfaeris/src/support  \


LOCAL_SRC_FILES :=  ../src/FsHttpEngine.cc \
					../src/FsHttpReponse.cc \
					../src/FsHttpRequest.cc  \




					 



include $(BUILD_STATIC_LIBRARY)









