/*
  ==============================================================================

    ManageView.cpp
    Created: 2 May 2016 1:22:16pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "ManageView.h"

ManageView::ManageView(ManageModel& manageModel) :
    manageModel(manageModel)
{
    addAndMakeVisible(thumbnailView);
    const std::shared_ptr<Sound> sound = manageModel.getActiveSound();
    thumbnailView.setThumbnail(sound->getThumbnail());
}

void ManageView::paint (Graphics& g) {
    g.fillAll(Colours::bisque);
}

void ManageView::resized() {
}
