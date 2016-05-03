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
sampleRate(0),
recording(false)
{
    String audioError = deviceManager.initialise (NCHANNELS, NCHANNELS, nullptr, true);
    jassert (audioError.isEmpty());
    
    deviceManager.addAudioCallback(this);
    thumbnail.reset(NCHANNELS, sampleRate);
}

CaptureModel::~CaptureModel()
{
    deviceManager.removeAudioCallback(this);
    deviceManager.closeAudioDevice();
}

void CaptureModel::startRecording()
{
    stopRecording();
    File support(File::getSpecialLocation(File::userApplicationDataDirectory)
                 .getChildFile("SampleManager"));
    jassert(support.exists());
    support.getNonexistentChildFile("temp-capture-record", ".wav");
    recording = true;
}

void CaptureModel::stopRecording()
{
    recording = false;
}

bool CaptureModel::isRecording()
{
    return recording;
}

void CaptureModel::audioDeviceIOCallback (const float** inData, int numInputChannels,
                            float** outData, int numOutputChannels,
                            int numSamples)
{
    if (isRecording()) {
        int nChannels = thumbnail.getNumChannels();
        const AudioSampleBuffer buffer(const_cast<float**> (inData), nChannels, numSamples);
        thumbnail.addBlock(nextSampleNum, buffer, 0, numSamples);
        nextSampleNum += numSamples;
    }
    
    for (int i = 0; i < numOutputChannels; ++i) {
        if (outData[i] != nullptr) {
            FloatVectorOperations::clear (outData[i], numSamples);
        }
    }
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

