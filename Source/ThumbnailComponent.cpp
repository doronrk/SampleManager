/*
  ==============================================================================

    ThumbnailView.cpp
    Created: 2 May 2016 4:18:16pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "ThumbnailComponent.h"

ThumbnailComponent::ThumbnailComponent() :
    thumbnail(nullptr),
    displayFullThumb(false)
{}

ThumbnailComponent::~ThumbnailComponent()
{
    if (hasThumbnail()) {
        thumbnail->removeChangeListener(this);
    }
}

void ThumbnailComponent::setThumbnail(AudioThumbnail *thumb) {
    if (hasThumbnail()) {
        thumbnail->removeChangeListener(this);
    }
    thumbnail = thumb;
    thumbnail->addChangeListener(this);
}


void ThumbnailComponent::paint (Graphics& g)
{
    g.fillAll (Colours::darkgrey);
    g.setColour (Colours::lightgrey);
    
    if (hasThumbnail()) {
        const double endTime = displayFullThumb ? thumbnail->getTotalLength()
            : jmax (30.0, thumbnail->getTotalLength());
        
        Rectangle<int> thumbArea (getLocalBounds());
        thumbnail->drawChannels(g, thumbArea.reduced (2), 0.0, endTime, 1.0f);
    } else {
        g.setFont (14.0f);
        g.drawFittedText ("(No file recorded)", getLocalBounds(), Justification::centred, 2);
    }
}

void ThumbnailComponent::resized() {
    
}

bool ThumbnailComponent::hasThumbnail() {
    return thumbnail != nullptr && thumbnail->getTotalLength() > 0.0;
}


void ThumbnailComponent::changeListenerCallback(ChangeBroadcaster *source)
{
    repaint();
}

void ThumbnailComponent::setDisplayFullThumb(bool full) {
    displayFullThumb = full;
}

