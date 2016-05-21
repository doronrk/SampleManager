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
    addAndMakeVisible(tagEditor);
    manageModel.addChangeListener(this);
    tagEditor.addListener(this);
}

void ManageView::paint (Graphics& g) {
}

void ManageView::resized() {
    float horSplit = 0.8;
    thumbnailView.setBoundsRelative(0.0, 0.0, 1.0, horSplit);
    tagEditor.setBoundsRelative(0.0, horSplit, 1.0, 1.0 - horSplit);
}

void ManageView::changeListenerCallback(ChangeBroadcaster *source) {
    if (source == &manageModel) {
        // TODO: only do this when sound changes, move to helper
        Sound *sound = manageModel.getActiveSound();
        AudioThumbnail *thumbnail = sound->getThumbnail();
        if (thumbnail == nullptr) {
            std::cout << "thumbnail is null" << std::endl;
        } else {
            std::cout << "thumbnail not null" << std::endl;
        }
        double length = thumbnail->getTotalLength();
        std::cout << "length of thumbnail: " << length << std::endl;
        thumbnailView.setThumbnail(sound->getThumbnail());
    }
}

void ManageView::textEditorTextChanged(TextEditor &) {
    //string text = tagEditor.getText();
}

