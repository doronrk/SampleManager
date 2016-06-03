/*
  ==============================================================================

    TagField.cpp
    Created: 2 Jun 2016 2:22:52pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "TagCollectionComponent.h"

TagCollectionComponent::TagCollectionComponent()
: tags(nullptr)
{}

void TagCollectionComponent::paint (Graphics& g) {
    if (tagComponents.isEmpty()) {
        g.drawSingleLineText("no tags", 0, 25);
        return;
    } 
}

void TagCollectionComponent::resized()  {
    float tcWidth = 1.0 / (float) tagComponents.size();
    float i = 0;
    for (auto iter = tagComponents.begin(); iter != tagComponents.end(); iter++, i++) {
        TagComponent *tc = *iter;
        tc->setBoundsRelative(i * tcWidth, 0, tcWidth, 1.0);
    }
}

void TagCollectionComponent::changeListenerCallback(ChangeBroadcaster *source) {
    if (source == tags) {
        repaint();
    }
}


void TagCollectionComponent::setTags(TagCollection *newTags) {
    this->tags = newTags;
    if (tags == nullptr) return;
    newTags->addChangeListener(this);
    tagComponents.clear();
    const std::vector<String> tagStrs = tags->getTagStrs();
    for (const String& tagStr: tagStrs) {
        TagComponent *tagComponent = new TagComponent(tagStr);
        tagComponents.add(tagComponent);
        addAndMakeVisible(tagComponent);
    }
    resized();
    repaint();
}