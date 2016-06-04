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
{
    setWantsKeyboardFocus(true);
}

void TagCollectionComponent::paint (Graphics& g) {
    if (tagComponents.isEmpty()) {
        g.drawSingleLineText("no tags", 0, 25);
        return;
    } 
}

void TagCollectionComponent::resized()  {
    int tcHeight = getHeight() / 3.0;
    int x = 0;
    int y = 0;
    int rightEdge = x + getWidth();
    for (auto iter = tagComponents.begin(); iter != tagComponents.end(); iter++) {
        TagComponent *tc = *iter;
        int width = tc->getBestWidthForHeight(tcHeight);
        if (x + width > rightEdge) {
            x = 0;
            y += tcHeight;
        }
        tc->setBounds(x, y, width, tcHeight);
        x += width;
    }
}

void TagCollectionComponent::changeListenerCallback(ChangeBroadcaster *source) {
    if (source == tags) {
        refreshTags();
    }
}

void TagCollectionComponent::refreshTags() {
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

void TagCollectionComponent::handleBackspacePressed() {
    for (auto iter = tagComponents.begin(); iter != tagComponents.end(); iter++) {
        TagComponent *tc = *iter;
        if (tc->getToggleState()) {
            const String& tag = tc->getButtonText();
            tags->removeTag(tag);
        }
    }
}


bool TagCollectionComponent::keyPressed(const KeyPress& key) {
    if (key.getKeyCode() == KeyPress::backspaceKey) {
        handleBackspacePressed();
        return true;
    }
    return false;
}
