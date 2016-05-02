/*
  ==============================================================================

    CaptureModel.cpp
    Created: 2 May 2016 11:58:38am
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "CaptureModel.h"

#define NCHANNELS 2

CaptureModel::CaptureModel() :
activeSound(NCHANNELS, 0)
{
    String audioError = deviceManager.initialise (NCHANNELS, NCHANNELS, nullptr, true);
    jassert (audioError.isEmpty());
    
    deviceManager.addAudioCallback (this);
    activeSound.clear();
}

CaptureModel::~CaptureModel()
{
    deviceManager.removeAudioCallback(this);
    deviceManager.closeAudioDevice();
}

void CaptureModel::audioDeviceIOCallback (const float** inputChannelData, int numInputChannels,
                            float** outputChannelData, int numOutputChannels,
                            int numSamples)
{
    for (int i = 0; i < numOutputChannels; ++i)
        if (outputChannelData[i] != nullptr)
            FloatVectorOperations::clear (outputChannelData[i], numSamples);
}

void CaptureModel::audioDeviceAboutToStart(AudioIODevice* device)
{
    sampleRate = device->getCurrentSampleRate();
}

void CaptureModel::audioDeviceStopped()
{
    sampleRate = 0;
}
