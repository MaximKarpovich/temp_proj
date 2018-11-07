package ffmpeg.main.ffmpeg_sample.player;

import ffmpeg.main.ffmpeg_sample.player.NativeVideoPlayer;

public class NdkVideoPlayer
{
    private static NativeVideoPlayer player;

    public static void createNativeVideoPlayer()
    {
        player = new NativeVideoPlayer();
    }
}
