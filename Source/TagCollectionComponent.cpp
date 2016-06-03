/*
  ==============================================================================

    TagField.cpp
    Created: 2 Jun 2016 2:22:52pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "TagCollectionComponent.h"

void TagCollectionComponent::paint (Graphics& g) {
    String text;
    if (tags != nullptr) {
        const std::vector<String> tagStrs = tags->getTagStrs();
        for (const String& tagStr: tagStrs) {
            text += tagStr + " ";
        }
    }
    if (text.isEmpty()) text = "no tags yet";
    g.drawSingleLineText(text, 0, 25);
}

void TagCollectionComponent::resized()  {
    
}

void TagCollectionComponent::changeListenerCallback(ChangeBroadcaster *source) {
    if (source == tags) {
        repaint();
    }
}


void TagCollectionComponent::setTags(TagCollection *newTags) {
    newTags->addChangeListener(this);
    this->tags = newTags;
}