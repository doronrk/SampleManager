#include "MainComponent.h"


MainContentComponent::MainContentComponent() :
captureView(captureModel),
manageView(captureModel.getThumbnail())
{
    addAndMakeVisible(captureView);
    addAndMakeVisible(manageView);
    setSize (800, 600);
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
    float horizSplit = 0.5;
    manageView.setBoundsRelative(0.0, 0.0, 1.0, horizSplit);
    captureView.setBoundsRelative(0.0, 1.0 - horizSplit, 1.0, 1.0 - horizSplit);
}