#include "MainComponent.h"

MainContentComponent::MainContentComponent() :
captureView(captureModel),
manageView(manageModel),
searchView(manageModel)
{
    manageModel.setActiveSound(captureModel.getSound());
    addChildComponent(captureView);
    //addAndMakeVisible(captureView);
    addAndMakeVisible(manageView);
    addAndMakeVisible(searchView);
    addAndMakeVisible(toggle);
    setSize (800, 800);
    setWantsKeyboardFocus(true);
    toggle.setButtonText("switch");
    toggle.addListener(this);
}

MainContentComponent::~MainContentComponent()
{
    
}


void MainContentComponent::paint (Graphics& g)
{
    //g.fillAll (Colours::black);
}

void MainContentComponent::resized() 
{
    float managePortion = 0.5;
    manageView.setBoundsRelative(0.0, 0.0, 1.0, managePortion);
    captureView.setBoundsRelative(0.0, managePortion, 1.0, 1.0 - managePortion);
    searchView.setBoundsRelative(0.0, managePortion, 1.0, 1.0 - managePortion);
    toggle.setBoundsRelative(.95, .95, .05, .05);
}

void MainContentComponent::buttonClicked(Button* b) {
    if (b == &toggle) {
        captureView.setVisible(!captureView.isVisible());
        searchView.setVisible(!searchView.isVisible());
    }
}


