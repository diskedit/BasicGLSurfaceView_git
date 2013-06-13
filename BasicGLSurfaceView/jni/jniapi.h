
#ifndef JNIAPI_H
#define JNIAPI_H

extern "C" {
    JNIEXPORT void JNICALL Java_com_example_android_basicglsurfaceview_BasicGLSurfaceViewActivity_testFunc(JNIEnv* jenv, jobject obj);
    JNIEXPORT void JNICALL Java_com_example_android_basicglsurfaceview_BasicGLSurfaceViewActivity_readSurface(JNIEnv* jenv, jobject obj, jobject surface);
    JNIEXPORT void JNICALL Java_com_example_android_basicglsurfaceview_BasicGLSurfaceViewActivity_setSurfaceBuffer(JNIEnv* jenv, jobject obj, jobject surface);

};

#endif // JNIAPI_H
