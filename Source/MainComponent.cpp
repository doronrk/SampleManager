#include "MainComponent.h"


MainContentComponent::MainContentComponent()
{
    setSize (800, 600);
}

MainContentComponent::~MainContentComponent()
{
}


void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colours::black);
}

void MainContentComponent::resized() 
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}