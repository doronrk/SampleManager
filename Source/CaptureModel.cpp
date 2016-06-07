/*
  ==============================================================================

    CaptureModel.cpp
    Created: 2 May 2016 11:58:38am
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "CaptureModel.h"


CaptureModel::CaptureModel() :
nextSampleNum(0),
sampleRate(0),
recording(false)
{
    String audioError = deviceManager.initialise(NCHANNELS, NCHANNELS, nullptr, true);
    jassert (audioError.isEmpty());
    deviceManager.addAudioCallback(this);
    dao = DAO::getDAO();
}

CaptureModel::~CaptureModel()
{
    deviceManager.removeAudioCallback(this);
    deviceManager.closeAudioDevice();
}

void CaptureModel::startRecording()
{
    stopRecording();
    sound.prepareRecord(numInputChannels, sampleRate);
    recording = true;
    sendChangeMessage();
}

void CaptureModel::stopRecording()
{
    recording = false;
    sendChangeMessage();
}

bool CaptureModel::isRecording()
{
    return recording;
}

void CaptureModel::audioDeviceIOCallback (const float** inData,
                                          int nInChannels,
                                          float** outData,
                                          int nOutChannels,
                                          int nSamples)
{
    // TODO: assert matching nInChannels
    if (isRecording()) {
        sound.appendAudio(inData, numInputChannels, nSamples);
    }
    
    for (int i = 0; i < nOutChannels; ++i) {
        if (outData[i] != nullptr) {
            FloatVectorOperations::clear (outData[i], nSamples);
        }
    }
}

void CaptureModel::audioDeviceAboutToStart(AudioIODevice* device)
{
    sampleRate = device->getCurrentSampleRate();
    BigInteger activeIn = device->getActiveInputChannels();
    numInputChannels = activeIn.countNumberOfSetBits();
}

void CaptureModel::audioDeviceStopped()
{
    sampleRate = 0;
    numInputChannels = 0;
}

Sound *CaptureModel::getSound() {
    return &sound;
}


