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
            mOldEnvironment = mEnvironment;
            mEnvironment = environment;
        }

        ~EnvHolder() {
            mEnvironment = mOldEnvironment;
        }

        /**
         * Retrieves a current JNI environment or NULL if not set.
         */
        static JNIEnv *env() {
            return mEnvironment;
        }
    };
}