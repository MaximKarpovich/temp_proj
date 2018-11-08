//
// Created by max on 7.11.18.
//

//
// Created by max on 7.11.18.
//
#include "VideoPlayer.h"
#include <jni.h>
#include "helpers/EnvHolder.h"
#include <android/log.h>


namespace Platform {
    class NativeVideoPlayer : public AbstractVideoPlayer {
    public:
        explicit NativeVideoPlayer() {
            __android_log_print(ANDROID_LOG_INFO, "JNI", "1");
            jclass localRef = Jni::EnvHolder::env()->FindClass("ffmpeg/main/ffmpeg_sample/player/NdkVideoPlayer");
            _g_NdkVideoPlayer_ref = (jclass)Jni::EnvHolder::env()->NewGlobalRef(localRef);

            jmethodID create = Jni::EnvHolder::env()->GetStaticMethodID(_g_NdkVideoPlayer_ref, "createNativeVideoPlayer", "()V");

            _ndk_Load = Jni::EnvHolder::env()->GetStaticMethodID(_g_NdkVideoPlayer_ref, "Load", "(Ljava/lang/String;)Z");
            _ndk_Play = Jni::EnvHolder::env()->GetStaticMethodID(_g_NdkVideoPlayer_ref, "Play", "()V");
            _ndk_Stop = Jni::EnvHolder::env()->GetStaticMethodID(_g_NdkVideoPlayer_ref, "Stop", "()V");
            _ndk_Pause = Jni::EnvHolder::env()->GetStaticMethodID(_g_NdkVideoPlayer_ref, "Pause", "()V");
            _ndk_Playing = Jni::EnvHolder::env()->GetStaticMethodID(_g_NdkVideoPlayer_ref, "Playing", "()Z");
            _ndk_Reset = Jni::EnvHolder::env()->GetStaticMethodID(_g_NdkVideoPlayer_ref, "Reset", "()V");
            _ndk_Time = Jni::EnvHolder::env()->GetStaticMethodID(_g_NdkVideoPlayer_ref, "Time", "()D");
            _ndk_Duration = Jni::EnvHolder::env()->GetStaticMethodID(_g_NdkVideoPlayer_ref, "Duration", "()D");
            _ndk_Seek = Jni::EnvHolder::env()->GetStaticMethodID(_g_NdkVideoPlayer_ref, "Seek", "(D)V");
            _ndk_Width = Jni::EnvHolder::env()->GetStaticMethodID(_g_NdkVideoPlayer_ref, "Width", "()I");
            _ndk_Height = Jni::EnvHolder::env()->GetStaticMethodID(_g_NdkVideoPlayer_ref, "Height", "()I");
            _ndk_Capture = Jni::EnvHolder::env()->GetStaticMethodID(_g_NdkVideoPlayer_ref, "Capture", "(I)V");

            __android_log_print(ANDROID_LOG_INFO, "JNI", "2");
            Jni::EnvHolder::env()->CallStaticVoidMethod(_g_NdkVideoPlayer_ref, create);

            const jstring jName = Jni::EnvHolder::env()->NewStringUTF("hello");
            Jni::EnvHolder::env()->CallStaticBooleanMethod(_g_NdkVideoPlayer_ref, _ndk_Load, jName);

            jdouble duration = Jni::EnvHolder::env()->CallStaticDoubleMethod(_g_NdkVideoPlayer_ref, _ndk_Duration);
            Jni::EnvHolder::env()->CallStaticVoidMethod(_g_NdkVideoPlayer_ref, _ndk_Seek, duration);

        }

        virtual ~NativeVideoPlayer () {}

        bool Load (const std::string& path) override
        {

        };

        void Play () override
        {

        };

        void Stop () override
        {

        };

        void Pause () override
        {

        };

        bool Playing () const override
        {

        };

        void Reset () override
        {

        }; // reset state (if it has been stopped, for example)

        double Time () const override
        {

        }; // current time in seconds

        double Duration () const override
        {

        };// duration in seconds

        void Seek (double seconds) override
        {

        }; // set current time in seconds

        int Width () override {
            return 0;
        }

        int Height () override {
            return 0;
        }

        void Capture (/*Renderer::ImageRGBA& destination*/int destination) const override
        {

        }// current frame

    private:
        jclass _g_NdkVideoPlayer_ref;
        jmethodID _ndk_Load;
        jmethodID _ndk_Play;
        jmethodID _ndk_Stop;
        jmethodID _ndk_Pause;
        jmethodID _ndk_Playing;
        jmethodID _ndk_Reset;
        jmethodID _ndk_Time;
        jmethodID _ndk_Duration;
        jmethodID _ndk_Seek;
        jmethodID _ndk_Width;
        jmethodID _ndk_Height;
        jmethodID _ndk_Capture;
    };

    VideoPlayerPtr VideoPlayer () {
        //using static because VideoPlayer is derived from AbstractVideoPlayer so
        //it is 100% safe cast, no need for dynamic (it adds overhead on check)
        return std::static_pointer_cast<AbstractVideoPlayer>(std::make_shared<NativeVideoPlayer>());
    }
}