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

            jmethodID method = Jni::EnvHolder::env()->GetStaticMethodID(_g_NdkVideoPlayer_ref, "createNativeVideoPlayer", "()V");
            __android_log_print(ANDROID_LOG_INFO, "JNI", "2");
            Jni::EnvHolder::env()->CallStaticVoidMethod(_g_NdkVideoPlayer_ref, method);
        }

        virtual ~NativeVideoPlayer () {}

        bool Load (const std::string& path) override
        {

        };

        bool Play () override
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

    private:

        jclass _g_NdkVideoPlayer_ref;

    };

    VideoPlayerPtr VideoPlayer () {
        //using static because VideoPlayer is derived from AbstractVideoPlayer so
        //it is 100% safe cast, no need for dynamic (it adds overhead on check)
        return std::static_pointer_cast<AbstractVideoPlayer>(std::make_shared<NativeVideoPlayer>());
    }
}