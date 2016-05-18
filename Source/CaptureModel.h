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
#include "DAO.h"
#include "Sound.h"

#define NCHANNELS 2

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

    AudioDeviceManager deviceManager;
    Sound *getSound();

private:
    AudioFormatManager formatManager;
    long nextSampleNum;
    double sampleRate;
    int numInputChannels;
    bool recording;
    Sound sound;
};



#endif  // CAPTUREMODEL_H_INCLUDED
