#pragma once
#include <jni.h>
#include <android/log.h>

namespace Jni {
    /**
     * Implements current JNI environment storage with RAII idiom. Should be used only from rendering thread!
     */
    class EnvHolder {
        /// Current JNI environment instance.
        static JNIEnv *mEnvironment;

        /// An old JNI environment instance.
        JNIEnv *mOldEnvironment = nullptr;
    public:
        /**
         * @param environment A JNI environment to hold.
         */
        EnvHolder(JNIEnv *environment) {
            __android_log_print(ANDROID_LOG_INFO, "JNI", "env holder 1");
            mOldEnvironment = mEnvironment;
            __android_log_print(ANDROID_LOG_INFO, "JNI", "env holder 2");
            mEnvironment = environment;
            __android_log_print(ANDROID_LOG_INFO, "JNI", "env holder 3");
        }

        ~EnvHolder() {
            __android_log_print(ANDROID_LOG_INFO, "JNI", "env holder 4");
            mEnvironment = mOldEnvironment;
            __android_log_print(ANDROID_LOG_INFO, "JNI", "env holder 5");
        }

        /**
         * Retrieves a current JNI environment or NULL if not set.
         */
        static JNIEnv *env() {
            return mEnvironment;
        }
    };
}