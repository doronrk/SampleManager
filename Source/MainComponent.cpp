#include "MainComponent.h"


MainContentComponent::MainContentComponent() :
captureView(captureModel)
{
    addAndMakeVisible(captureView);
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
    captureView.setBoundsRelative(0.0, 0.0, 1.0, 1.0);
}