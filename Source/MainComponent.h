/*
  ==============================================================================

    MainComponent.h
    Created: 2 May 2016 1:25:03pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "CaptureView.h"

class MainContentComponent : public Component
{
public:
    MainContentComponent();
    ~MainContentComponent();
    
    void paint (Graphics& g) override;
    
    void resized() override;
    
    
private:
    CaptureView captureView;
    CaptureModel captureModel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};



#endif  // MAINCOMPONENT_H_INCLUDED
