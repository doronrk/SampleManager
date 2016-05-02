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

class ManageView:
    public Component
{
public:
    ManageView(AudioThumbnail &captureThumb);
    void paint (Graphics& g) override;
    void resized() override;
private:
    ThumbnailView thumbView;
};

#endif  // MANAGEVIEW_H_INCLUDED
