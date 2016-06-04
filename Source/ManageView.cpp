/*
  ==============================================================================

    ManageView.cpp
    Created: 2 May 2016 1:22:16pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "ManageView.h"
#include <signal.h>

ManageView::ManageView(ManageModel& manageModel) :
    manageModel(manageModel)
{
    addAndMakeVisible(tagCollectionComponent);
    addAndMakeVisible(thumbnailComponent);
    addAndMakeVisible(tagEditor);
    manageModel.addChangeListener(this);
    tagEditor.addListener(this);
    tagEditor.setTextToShowWhenEmpty("add a new tag", Colours::grey);
    tagEditor.setReturnKeyStartsNewLine(false);
}

void ManageView::paint (Graphics& g) {
}

void ManageView::resized() {
    float thumbnailHeight = 0.5;
    thumbnailComponent.setBoundsRelative(0.0, 0.0, 1.0, thumbnailHeight);
    float tagFieldHeight = .25;
    tagCollectionComponent.setBoundsRelative(0.0, thumbnailHeight, 1.0, tagFieldHeight);
    float tagEditorHeight = 1.0 - thumbnailHeight - tagFieldHeight;
    tagEditor.setBoundsRelative(0.0, 1.0 - tagEditorHeight, 1.0, tagEditorHeight);
}

void ManageView::changeListenerCallback(ChangeBroadcaster *source) {
    if (source == &manageModel) {
        // TODO: only do this when sound changes, move to helper
        Sound *sound = manageModel.getActiveSound();
        AudioThumbnail *thumbnail = sound->getThumbnail();
        thumbnailComponent.setThumbnail(thumbnail);
        TagCollection *tags = sound->getTagCollection();
        tags->addTag("abdd");
        tags->addTag("asdfasdf");
        tagCollectionComponent.setTags(tags);
    }
}

void ManageView::textEditorTextChanged(TextEditor &) {
    //string text = tagEditor.getText();
}

void ManageView::textEditorReturnKeyPressed(TextEditor &tagEditor) {
    String text = tagEditor.getText();
    if (manageModel.addTag(text)) {
        tagEditor.clear();
    }
}


