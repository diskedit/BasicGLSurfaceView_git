#include <stdint.h>
#include <jni.h>
#include <android/native_window.h> // requires ndk r5 or newer
#include <android/native_window_jni.h> // requires ndk r5 or newer
#include <stdlib.h>

#include "jniapi.h"
#include "logger.h"


#define LOG_TAG "EglSample"


JNIEXPORT void JNICALL Java_com_example_android_basicglsurfaceview_BasicGLSurfaceViewActivity_setSurfaceBuffer(JNIEnv* jenv, jobject obj, jobject surface)
{
	//LOG_INFO("Java_com_example_android_basicglsurfaceview_BasicGLSurfaceViewActivity_setSurfaceBuffer");
	ANativeWindow *window = ANativeWindow_fromSurface(jenv, surface);

	    	LOG_INFO("Got window %p", window);
	    	if(window > 0)
	    	{
	            int width = ANativeWindow_getWidth(window);
	            int height = ANativeWindow_getHeight(window);

	            LOG_INFO("Got window %d %d", width,height);

	            LOG_INFO("window buffer count %d",window);

	            int result = ANativeWindow_setBuffersGeometry(window,0,0,WINDOW_FORMAT_RGB_565);

	            LOG_INFO("ANativeWindow_setBuffersGeometry result %d", result);

	        //    ANativeWindow_release(window);
	    	}

}

JNIEXPORT void JNICALL Java_com_example_android_basicglsurfaceview_BasicGLSurfaceViewActivity_testFunc(JNIEnv* jenv, jobject obj)
{
    LOG_INFO("Test Function");
    return;
}

void throwJavaException(JNIEnv *env, const char *msg)
{
    // You can put your own exception here
    jclass c = env->FindClass("java/io/RuntimeException");

    if (NULL == c)
    {
        //B plan: null pointer ...
        c = env->FindClass("java/lang/NullPointerException");
    }

    env->ThrowNew(c, msg);
}

JNIEXPORT void JNICALL Java_com_example_android_basicglsurfaceview_BasicGLSurfaceViewActivity_readSurface(JNIEnv* jenv, jobject obj, jobject surface)
{

	LOG_INFO("Java_com_example_android_basicglsurfaceview_BasicGLSurfaceViewActivity_readSurface");
    if (surface != 0) {
    	ANativeWindow *window = ANativeWindow_fromSurface(jenv, surface);
    	LOG_INFO("Got window %p", window);
    	if(window > 0)
    	{
            int width = ANativeWindow_getWidth(window);
            int height = ANativeWindow_getHeight(window);

            LOG_INFO("Got window %d %d", width,height);

            ANativeWindow_setBuffersGeometry(window,0,0,WINDOW_FORMAT_RGBA_8888);

            ANativeWindow_Buffer buffer;
            memset((void*)&buffer,0,sizeof(buffer));

            int lockResult = -22;

                lockResult = ANativeWindow_lock(window, &buffer, NULL);
                if (lockResult == 0) {
                  LOG_INFO("ANativeWindow_locked");
                  ANativeWindow_unlockAndPost(window);
                }
                else
                {
                	LOG_INFO("ANativeWindow_lock failed error %d",lockResult);
                }

            LOG_INFO("Releasing window");

            ANativeWindow_release(window);
    	}


    } else {
    	 LOG_INFO("surface is null");
    }

    return;
}


