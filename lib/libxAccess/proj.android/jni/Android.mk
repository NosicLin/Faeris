LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE :=libthirdParty_static

LOCAL_CFLAGS :=     -I$(LOCAL_PATH)/../../../libfaeris/src \
 					-I$(LOCAL_PATH)/../../../lib3rdparty/lua/include \
 					-I$(LOCAL_PATH)/../../../libextends/libluaexport/src \
 					-I$(LOCAL_PATH)/../../../lib3rdparty/tolua++/include \
 					-I$(LOCAL_PATH)/../../src  \



LOCAL_SRC_FILES :=  \
			src/com_rwhz_minder_Fs_r3rdPartyJni.cc \
			../../src/FsxAccessExport.cc \
			../../src/FsxAccessModule.cc\
			../../src/FsxAccessFuc.cc\
			../../src/FsUpdateApk.cc\
			../../src/FsTest.cc \


include $(BUILD_STATIC_LIBRARY)
