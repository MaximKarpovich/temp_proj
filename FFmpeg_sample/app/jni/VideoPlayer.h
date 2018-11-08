#pragma once

#include <jni.h>
#include <cstdlib>
#include <memory>
#include <string>

//#include "../Renderer/ImageRGBA.h"
//#include "../Renderer/Common.h"

namespace Platform {
    class AbstractVideoPlayer {
    public:
        virtual ~AbstractVideoPlayer () {}

        virtual bool Load (const std::string& path) = 0;

        virtual void Play () = 0;
        virtual void Stop () = 0;
        virtual void Pause () = 0;
        virtual bool Playing () const = 0;

        virtual void Reset () = 0; // reset state (if it has been stopped, for example)

        virtual double Time () const = 0; // current time in seconds
        virtual double Duration () const = 0; // duration in seconds
        virtual void Seek (double seconds) = 0; // set current time in seconds
        virtual int Width () = 0;
        virtual int Height () = 0;
        virtual void Capture (/*Renderer::ImageRGBA& destination*/int destination) const = 0; // current frame
    };

    typedef std::shared_ptr<AbstractVideoPlayer> VideoPlayerPtr;

    VideoPlayerPtr VideoPlayer ();
}