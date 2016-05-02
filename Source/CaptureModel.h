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

class CaptureModel: public AudioAppComponent
{
public:
    CaptureModel();
    ~CaptureModel();
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;
};



#endif  // CAPTUREMODEL_H_INCLUDED
