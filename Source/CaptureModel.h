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

class CaptureModel: public AudioIODeviceCallback
{
public:
    CaptureModel();
    ~CaptureModel();
    void audioDeviceIOCallback (const float** inputChannelData, int numInputChannels,
                                float** outputChannelData, int numOutputChannels,
                                int numSamples) override;
    void audioDeviceAboutToStart (AudioIODevice* device) override;
    void audioDeviceStopped() override;


    
    AudioDeviceManager deviceManager;
private:
    AudioSampleBuffer activeSound;
    double sampleRate;
};



#endif  // CAPTUREMODEL_H_INCLUDED
