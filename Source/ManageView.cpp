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
    addAndMakeVisible(nameEditor);
    addAndMakeVisible(saveButton);
    manageModel.addChangeListener(this);
    Font f;
    f.setHeight(25.0);
    tagEditor.addListener(this);
    tagEditor.setTextToShowWhenEmpty("add a new tag", Colours::grey);
    tagEditor.setReturnKeyStartsNewLine(false);
    tagEditor.setFont(f);
    tagEditor.setColour(TextEditor::ColourIds::outlineColourId, Colours::black);
    nameEditor.addListener(this);
    nameEditor.setTextToShowWhenEmpty("no name", Colours::grey);
    nameEditor.setReturnKeyStartsNewLine(false);
    nameEditor.setFont(f);
    nameEditor.setColour(TextEditor::ColourIds::outlineColourId, Colours::black);
    
    saveButton.setButtonText("Save");
    saveButton.addListener(this);
}

void ManageView::paint (Graphics& g) {
}

void ManageView::resized() {
    float thumbnailHeight = 0.5;
    float thumbnailWidth = 0.9;
    thumbnailComponent.setBoundsRelative(0.0, 0.0, thumbnailWidth, thumbnailHeight);
    saveButton.setBoundsRelative(thumbnailWidth, 0.0, 1.0 - thumbnailWidth, thumbnailHeight);
    float textFieldsHeight = .1;
    float nameWidth = .5;
    nameEditor.setBoundsRelative(0.0, thumbnailHeight, nameWidth, textFieldsHeight);
    tagEditor.setBoundsRelative(nameWidth, thumbnailHeight, 1.0 - nameWidth, textFieldsHeight);
    tagCollectionComponent.setBoundsRelative(0.0, thumbnailHeight + textFieldsHeight, 1.0, 1.0 - thumbnailHeight - textFieldsHeight);
}

void ManageView::changeListenerCallback(ChangeBroadcaster *source) {
    if (source == &manageModel) {
        // TODO: only do this when sound changes, move to helper
        Sound *sound = manageModel.getActiveSound();
        AudioThumbnail *thumbnail = sound->getThumbnail();
        thumbnailComponent.setThumbnail(thumbnail);
        TagCollection *tags = sound->getTagCollection();
        tagCollectionComponent.setTags(tags);
    }
}

void ManageView::textEditorTextChanged(TextEditor &) {
    //string text = tagEditor.getText();
}

void ManageView::textEditorReturnKeyPressed(TextEditor &textEditor) {
    String text = textEditor.getText();
    if (&textEditor == &tagEditor) {
        if (manageModel.addTag(text)) {
            tagEditor.clear();
        }
    } else if (&textEditor == &nameEditor) {
        manageModel.setName(text);
    }
}

void ManageView::buttonClicked(Button* b) {
    if (b == &saveButton) {
        String nametext = nameEditor.getText();
        manageModel.setName(nametext);
        manageModel.save();
    }
}


