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
    manageModel.addChangeListener(this);
}

void ManageView::paint (Graphics& g) {
    g.fillAll(Colours::bisque);
    thumbnailView.setBoundsRelative(0.0, 0.0, 1.0, 1.0);
}

void ManageView::resized() {
}

void ManageView::changeListenerCallback(ChangeBroadcaster *source) {
    if (source == &manageModel) {
        // TODO: only do this when sound changes, move to helper
        Sound *sound = manageModel.getActiveSound();
        thumbnailView.setThumbnail(sound->getThumbnail());
    }
}
