/**
 * Copyright 2016-present, Facebook, Inc.
 * All rights reserved.
 *
 * Licensed under the Creative Commons CC BY-NC 4.0 Attribution-NonCommercial
 * License (the "License"). You may obtain a copy of the License at
 * https://creativecommons.org/licenses/by-nc/4.0/.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

package ffmpeg.main.ffmpeg_sample.player;

import ffmpeg.main.ffmpeg_sample.MainActivity;
import ffmpeg.main.ffmpeg_sample.R;

import android.graphics.SurfaceTexture;
import android.media.AudioManager;
import android.media.MediaPlayer;

import android.net.Uri;
import android.util.Log;

import android.view.Surface;

import java.io.IOException;


public class NativeVideoPlayer {
    private MediaPlayer videoPlayerInternal;
    //private RenderThread renderThread;
    private SurfaceTexture surfaceTexture;

    private final String SAMPLE_VIDEO_PATH = "android.resource://com.oculus.sample/raw/" + R.raw.sample360;

    private boolean readyToPlay;

    private boolean frameAvailable;

    public NativeVideoPlayer() {

        Log.d("NativeVideoPlayer", "Created");
        Load(SAMPLE_VIDEO_PATH);
    }

    public boolean Load (String videoPath) {
        Log.d("NativeVideoPlayer", videoPath);

        videoPlayerInternal = new MediaPlayer();
        videoPlayerInternal.setAudioStreamType(AudioManager.STREAM_MUSIC);

        // TODO: make sure it first looks in absolute path and if not found,
        // loads from bundle (apk)
        try {
            videoPlayerInternal.setDataSource("/storage/emulated/0/Download/test.mp4");
        }
        catch (IOException ex)
        {
            Log.d("NativeVideoPlayer", ex.getMessage());
        }

        videoPlayerInternal.setLooping(true);
        videoPlayerInternal.setOnPreparedListener(new MediaPlayer.OnPreparedListener() {
            @Override
            public void onPrepared(MediaPlayer mp) {
                Log.d("NativeVideoPlayer", "Start");
                mp.start();
            }
        });

        videoPlayerInternal.prepareAsync();

        return true;
    }

    public void Play () {
        if (!videoPlayerInternal.isPlaying()) {
            videoPlayerInternal.start();
        }
    }

    public void Stop () {
        if (videoPlayerInternal.isPlaying()) {
            videoPlayerInternal.stop();
        }
    }

    public void Pause () {
        if (!readyToPlay) {
            return;
        }

        if (videoPlayerInternal.isPlaying()) {
            videoPlayerInternal.pause();
        }
    }

    public boolean Playing () {
        return videoPlayerInternal.isPlaying();
    }
        
    public double Time () {
        return 0;
    }

    public double Duration () {
        return videoPlayerInternal.getDuration();
    }

    public void Seek (double seconds) {
        Log.d("NativeVideoPlayer", "Duration" + Double.toString(seconds));
    }
        
    public int Width () {
        return 0;
    }

    public int Height () {
        return 0;
    }
    
    public void Capture (int textureId) {
        if (!readyToPlay) {
            return;
        }

        // MAKE SURE IT'S RGBA!!!

        if (surfaceTexture == null) {
            surfaceTexture = new SurfaceTexture (textureId);

            surfaceTexture.setOnFrameAvailableListener(
                new SurfaceTexture.OnFrameAvailableListener() {
                    @Override
                    public void onFrameAvailable(SurfaceTexture surfaceTexture) {
                        frameAvailable = true;
                    }
            });

            videoPlayerInternal.setSurface (new Surface (surfaceTexture));
        }

        if (!frameAvailable) {
            return;
        }

        surfaceTexture.updateTexImage();

        frameAvailable = false;
    }

    private void OnPlayerPrepared()
    {

    }
}