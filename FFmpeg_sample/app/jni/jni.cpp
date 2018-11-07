#include <jni.h>
#include "VideoPlayer.h"
#include <android/log.h>

extern "C"
{

JNIEXPORT void JNICALL
Java_ffmpeg_main_ffmpeg_1sample_player_SphericalVideoPlayer_initVideoPlayer(JNIEnv *env, jobject thiz,
                                                             jstring file_path) {
    jclass cls = env->GetObjectClass(thiz);
    jmethodID mid = env->GetMethodID(cls, "pause", "()V");

    Platform::VideoPlayerPtr player = Platform::VideoPlayer();

    player->set_items(env, thiz, mid);
}

}