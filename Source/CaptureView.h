/*
  ==============================================================================

    CaptureView.h
    Created: 2 May 2016 1:22:04pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#ifndef CAPTUREVIEW_H_INCLUDED
#define CAPTUREVIEW_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "CaptureModel.h"

class CaptureView :
    public Component,
    private Button::Listener
{
public:
    CaptureView(CaptureModel &captureModel);
    void paint (Graphics& g) override;
    void resized() override;
    
private:
    CaptureModel &captureModel;
    AudioDeviceSelectorComponent deviceSelector;
    TextButton recordButton;
    
    void buttonClicked(Button *button) override;
    void startRecording();
    void stopRecording();
};



#endif  // CAPTUREVIEW_H_INCLUDED
