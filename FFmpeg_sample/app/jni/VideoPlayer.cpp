//
// Created by max on 7.11.18.
//

//
// Created by max on 7.11.18.
//
#include "VideoPlayer.h"
#include <jni.h>
#include <memory>
#include <functional>
#include <chrono>
#include <thread>
#include <android/log.h>


namespace Platform {
    class NativeVideoPlayer : public AbstractVideoPlayer {
    public:
        explicit NativeVideoPlayer() {}
        virtual ~NativeVideoPlayer () {}

        virtual bool Load (const std::string& path) override
        {

        };

        virtual bool Play () override
        {

        };

        virtual void Stop () override
        {

        };

        virtual void Pause () override
        {

        };

        virtual bool Playing () const override
        {

        };

        virtual void Reset () override
        {

        }; // reset state (if it has been stopped, for example)

        virtual double Time () const override
        {

        }; // current time in seconds

        virtual double Duration () const override
        {

        };// duration in seconds

        virtual void Seek (double seconds) override
        {

        }; // set current time in seconds


        virtual void set_items(JNIEnv *env, jobject player_object, jmethodID player_method) override
        {
            _env = env;
            env->GetJavaVM(&_jvm);
            _player_object = player_object;
            _player_pause = player_method;

            jclass localRef = _env->FindClass("ffmpeg/main/ffmpeg_sample/player/SphericalVideoPlayer");
            _globalClassRef = (jclass)env->NewGlobalRef(localRef);

            std::thread t(&NativeVideoPlayer::start_process, this);
        };

    private:
        void start_process()
        {
            JNIEnv *g_env;
            int getEnvStat = _jvm->GetEnv((void **)&g_env, JNI_VERSION_1_6);
            if (getEnvStat == JNI_EDETACHED) {
                __android_log_write(ANDROID_LOG_INFO, " JNI CODE ", " GENV NOT ATTACHED");
                if (_jvm->AttachCurrentThread(&g_env, NULL) != 0) {
                    __android_log_write(ANDROID_LOG_INFO, " JNI CODE ", " FAILED TO ATTACH");
                }
            } else if (getEnvStat == JNI_OK) {
                //
            } else if (getEnvStat == JNI_EVERSION) {
                __android_log_write(ANDROID_LOG_INFO, " JNI CODE ", " VERSION NOT SUPPORTED");
            }

            jmethodID mid = g_env->GetStaticMethodID(_globalClassRef, "test_method", "()V");
            g_env->CallStaticVoidMethod(_globalClassRef, mid);

            if (g_env->ExceptionCheck()) {
                g_env->ExceptionDescribe();
            }

            _jvm->DetachCurrentThread();

            //std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        }

    private:
        JavaVM *_jvm;
        JNIEnv *_env;
        jobject _player_object;
        jmethodID _player_pause;
        jclass _globalClassRef;
    };

    VideoPlayerPtr VideoPlayer () {
        //using static because VideoPlayer is derived from AbstractVideoPlayer so
        //it is 100% safe cast, no need for dynamic (it adds overhead on check)
        return std::static_pointer_cast<AbstractVideoPlayer>(std::make_shared<NativeVideoPlayer>());
    }
}