#include "MainComponent.h"

MainContentComponent::MainContentComponent() :
captureView(captureModel),
manageView(manageModel)
{
    manageModel.setActiveSound(captureModel.getSound());
    addAndMakeVisible(captureView);
    addAndMakeVisible(manageView);
    setSize (800, 800);
    DAO::initDBconn();
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
    float managePortion = 0.7;
    manageView.setBoundsRelative(0.0, 0.0, 1.0, managePortion);
    captureView.setBoundsRelative(0.0, managePortion, 1.0, 1.0 - managePortion);
}