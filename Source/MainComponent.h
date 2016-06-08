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
#include "ManageView.h"
#include "SearchView.h"

class MainContentComponent :
public Component,
private Button::Listener
{
public:
    MainContentComponent();
    ~MainContentComponent();
    
    void paint (Graphics& g) override;
    void resized() override;
    
private:
    void buttonClicked(Button* b) override;
    
    CaptureModel captureModel;
    ManageModel manageModel;
    
    CaptureView captureView;
    ManageView manageView;
    SearchView searchView;
    TextButton toggle;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};



#endif  // MAINCOMPONENT_H_INCLUDED
