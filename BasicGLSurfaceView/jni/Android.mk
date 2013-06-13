
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := nativeegl
LOCAL_CFLAGS    := -Wall
LOCAL_SRC_FILES := jniapi.cpp 
LOCAL_LDLIBS    := -llog -landroid -lEGL 

include $(BUILD_SHARED_LIBRARY)
