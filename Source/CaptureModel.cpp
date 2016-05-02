/*
  ==============================================================================

    CaptureModel.cpp
    Created: 2 May 2016 11:58:38am
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "CaptureModel.h"


CaptureModel::CaptureModel()
{
    setAudioChannels(2, 2);
}

CaptureModel::~CaptureModel()
{
    shutdownAudio();
}

void CaptureModel::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    
}

void CaptureModel::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    bufferToFill.clearActiveBufferRegion();
}

void CaptureModel::releaseResources()
{
    
}