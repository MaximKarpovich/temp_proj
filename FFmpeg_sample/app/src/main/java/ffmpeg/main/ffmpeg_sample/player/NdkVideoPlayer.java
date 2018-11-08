package ffmpeg.main.ffmpeg_sample.player;

import android.util.Log;

import ffmpeg.main.ffmpeg_sample.player.NativeVideoPlayer;

public class NdkVideoPlayer
{
    private static NativeVideoPlayer player;

    public static void createNativeVideoPlayer()
    {
        player = new NativeVideoPlayer();
    }

    public static boolean Load (String videoPath) {
        Log.d("NdkVideoPlayer", "Load");
        return player.Load(videoPath);
    }

    public static void Play () {
        player.Play();
    }

    public static void Stop () {
        player.Stop();
    }

    public static void Pause () {
        player.Pause();
    }

    public static boolean Playing () {
        return player.Playing();
    }

    public static void Reset () {

    } // reset state (if it has been stopped, for example)

    public static double Time () {
        return player.Time();
    }

    public static double Duration () {
        return player.Duration();
    }

    public static void Seek (double seconds) {
        player.Seek(seconds);
    }

    public static int Width () {
        return player.Width();
    }

    public static int Height () {
        return player.Height();
    }

    public static void Capture (int textureId) {
        player.Capture(textureId);
    }
}
