/*
  ==============================================================================

    TagCollection.cpp
    Created: 2 Jun 2016 2:46:32pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "TagCollection.h"

void TagCollection::addTag(String tag) {
    tags.add(tag);
    sendChangeMessage();
}

void TagCollection::removeTag(String tagToRemove) {
    tags.remove(&tagToRemove);
    sendChangeMessage();
}

bool TagCollection::containsTag(String tag) {
    for (auto it = tags.begin(); it != tags.end(); it++) {
        if ((*it) == tag) return true;
    }
    return false;
}


const Array<String>& TagCollection::getTagStrs() const {
    return tags;
}