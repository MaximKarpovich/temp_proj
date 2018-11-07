#pragma once

#include <jni.h>
#include <cstdlib>
#include <memory>
#include <string>


namespace Platform {
    class AbstractVideoPlayer {
    public:
        virtual ~AbstractVideoPlayer () {}

        virtual bool Load (const std::string& path) = 0;

        virtual bool Play () = 0;
        virtual void Stop () = 0;
        virtual void Pause () = 0;
        virtual bool Playing () const = 0;

        virtual void Reset () = 0; // reset state (if it has been stopped, for example)

        virtual double Time () const = 0; // current time in seconds
        virtual double Duration () const = 0; // duration in seconds
        virtual void Seek (double seconds) = 0; // set current time in seconds
    };

    typedef std::shared_ptr<AbstractVideoPlayer> VideoPlayerPtr;

    VideoPlayerPtr VideoPlayer ();
}