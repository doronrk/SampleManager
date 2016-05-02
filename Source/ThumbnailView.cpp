/*
  ==============================================================================

    ThumbnailView.cpp
    Created: 2 May 2016 4:18:16pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "ThumbnailView.h"

ThumbnailView::ThumbnailView(AudioThumbnail &thumbnail) :
    thumbnail(thumbnail),
    displayFullThumb(false)
{
}

void ThumbnailView::paint (Graphics& g)
{
    g.fillAll (Colours::darkgrey);
    g.setColour (Colours::lightgrey);
    
    if (thumbnail.getTotalLength() > 0.0) {
        const double endTime = displayFullThumb ? thumbnail.getTotalLength()
            : jmax (30.0, thumbnail.getTotalLength());
        
        Rectangle<int> thumbArea (getLocalBounds());
        thumbnail.drawChannels(g, thumbArea.reduced (2), 0.0, endTime, 1.0f);
    }
    else {
        g.setFont (14.0f);
        g.drawFittedText ("(No file recorded)", getLocalBounds(), Justification::centred, 2);
    }
}

void ThumbnailView::resized() {
    
}

void ThumbnailView::changeListenerCallback(ChangeBroadcaster *source)
{
    if (source == &thumbnail) {
        repaint();
    }
}
