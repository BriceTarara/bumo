LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE    := bumo
LOCAL_SRC_FILES := bumo.cpp
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/
include $(BUILD_SHARED_LIBRARY)

