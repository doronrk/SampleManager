/*
  ==============================================================================

    CaptureModel.h
    Created: 2 May 2016 11:58:38am
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#ifndef CAPTUREMODEL_H_INCLUDED
#define CAPTUREMODEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#define NCHANNELS 2
#define THUMB_RES 512
#define THUMB_CACHE_CAP 10

class CaptureModel: public AudioIODeviceCallback
{
public:
    CaptureModel();
    ~CaptureModel();
    void startRecording();
    void stopRecording();
    bool isRecording();
    
    // AudioIODeviceCallback functions
    void audioDeviceIOCallback (const float** inputChannelData, int numInputChannels,
                                float** outputChannelData, int numOutputChannels,
                                int numSamples) override;
    void audioDeviceAboutToStart (AudioIODevice* device) override;
    void audioDeviceStopped() override;

    // public fields for CaptureView, TODO: make a friend class?
    AudioDeviceManager deviceManager;
    AudioThumbnail &getThumbnail();

private:
    
    AudioFormatManager formatManager;
    AudioThumbnailCache thumbnailCache;
    AudioThumbnail thumbnail;
    long nextSampleNum;
    double sampleRate;
    bool recording;
};



#endif  // CAPTUREMODEL_H_INCLUDED
