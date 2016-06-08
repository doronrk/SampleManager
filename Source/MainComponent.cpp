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
    setSize (800, 800);
    setWantsKeyboardFocus(true);
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
}

bool MainContentComponent::keyPressed(const KeyPress& key) {
    if (key.getKeyCode() == KeyPress::tabKey) {
        if (key.getModifiers().isShiftDown()) {
            captureView.setVisible(!captureView.isVisible());
            searchView.setVisible(!searchView.isVisible());
            return true;
        }
    }
    return false;
}
