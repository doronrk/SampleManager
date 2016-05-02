/*
  ==============================================================================

    CaptureModel.cpp
    Created: 2 May 2016 11:58:38am
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "CaptureModel.h"



CaptureModel::CaptureModel() :
thumbnailCache(THUMB_CACHE_CAP),
thumbnail(THUMB_RES, formatManager, thumbnailCache),
nextSampleNum(0),
sampleRate(0)
{
    String audioError = deviceManager.initialise (NCHANNELS, NCHANNELS, nullptr, true);
    jassert (audioError.isEmpty());
    
    deviceManager.addAudioCallback (this);
}

CaptureModel::~CaptureModel()
{
    deviceManager.removeAudioCallback(this);
    deviceManager.closeAudioDevice();
}

void CaptureModel::startRecord()
{
    
}

void CaptureModel::stopRecord()
{
    
}

void CaptureModel::audioDeviceIOCallback (const float** inData, int numInputChannels,
                            float** outData, int numOutputChannels,
                            int numSamples)
{
    /*
    if (isRecording()) {
        int nChannels = thumbnail.getNumChannels();
        for (int ch = 0; ch < nChannels; ch++) {
            const AudioSampleBuffer buffer(const_cast<float**> (inData), nChannels, numSamples);
            thumbnail.addBlock(nextSampleNum, buffer, 0, numSamples);
            nextSampleNum += numSamples;
        }
    }
    
    for (int i = 0; i < numOutputChannels; ++i) {
        if (outData[i] != nullptr) {
            FloatVectorOperations::clear (outData[i], numSamples);
        }
    }*/
}

void CaptureModel::audioDeviceAboutToStart(AudioIODevice* device)
{
    sampleRate = device->getCurrentSampleRate();
}

void CaptureModel::audioDeviceStopped()
{
    sampleRate = 0;
}

AudioThumbnail &CaptureModel::getThumbnail()
{
    return thumbnail;
}



bool CaptureModel::isRecording()
{
    return true;
}

