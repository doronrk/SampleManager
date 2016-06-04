/*
  ==============================================================================

    ManageView.h
    Created: 2 May 2016 1:22:16pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#ifndef MANAGEVIEW_H_INCLUDED
#define MANAGEVIEW_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"
#include "TagCollectionComponent.h"
#include "ThumbnailComponent.h"
#include "ManageModel.h"

class ManageView:
    public Component,
    private ChangeListener,
    private TextEditor::Listener
{
public:
    ManageView(ManageModel& manageModel);
    void paint (Graphics& g) override;
    void resized() override;
private:
    ManageModel& manageModel;
    TextEditor tagEditor;
    TagCollectionComponent tagCollectionComponent;
    ThumbnailComponent thumbnailComponent;
    
    void changeListenerCallback(ChangeBroadcaster *source) override;
    void textEditorTextChanged(TextEditor &) override;
    void textEditorReturnKeyPressed(TextEditor &) override;
};

#endif  // MANAGEVIEW_H_INCLUDED
