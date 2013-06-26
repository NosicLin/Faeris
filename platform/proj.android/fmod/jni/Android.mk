LOCAL_PATH := $(call my-dir)

#
# FMOD Ex Shared Library
# 
include $(CLEAR_VARS)

LOCAL_MODULE            := fmodex
LOCAL_SRC_FILES         := ../lib/$(TARGET_ARCH_ABI)/libfmodex.so

include $(PREBUILT_SHARED_LIBRARY)
