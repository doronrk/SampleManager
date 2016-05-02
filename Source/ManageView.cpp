/*
  ==============================================================================

    ManageView.cpp
    Created: 2 May 2016 1:22:16pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "ManageView.h"

ManageView::ManageView(AudioThumbnail &captureThumb) :
    thumbView(captureThumb)
{
    addAndMakeVisible(thumbView);
}

void ManageView::paint (Graphics& g) {
    g.fillAll(Colours::bisque);
}

void ManageView::resized() {
    thumbView.setBoundsRelative(0.0, 0.0, 1.0, 1.0);
}
