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
#include "ThumbnailView.h"
#include "ManageModel.h"

class ManageView:
    public Component,
    private ChangeListener
{
public:
    ManageView(ManageModel& manageModel);
    void paint (Graphics& g) override;
    void resized() override;
private:
    ManageModel& manageModel;
    ThumbnailView thumbnailView;
    
    void changeListenerCallback(ChangeBroadcaster *source) override;
};

#endif  // MANAGEVIEW_H_INCLUDED
