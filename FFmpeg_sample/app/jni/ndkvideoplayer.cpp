#include <jni.h>
#include "VideoPlayer.h"
#include "helpers/EnvHolder.h"
#include <android/log.h>

extern "C"
{

jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    JNIEnv* env = nullptr;
    vm->GetEnv((void**)&env, JNI_VERSION_1_6);
    //TODO: add error check

    __android_log_print(ANDROID_LOG_INFO, "JNI", "Inited env");

    const Jni::EnvHolder holder(env);
    __android_log_print(ANDROID_LOG_INFO, "JNI", "Before finish onload");
}

JNIEXPORT void JNICALL
Java_ffmpeg_main_ffmpeg_1sample_MainActivity_initVideoPlayer(JNIEnv *env, jobject thiz) {
    __android_log_print(ANDROID_LOG_INFO, "JNI", "Before player create");
    Platform::VideoPlayerPtr player = Platform::VideoPlayer();
}

}
