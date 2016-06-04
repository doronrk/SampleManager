/*
  ==============================================================================

    TagCollection.cpp
    Created: 2 Jun 2016 2:46:32pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "TagCollection.h"

void TagCollection::addTag(String tag) {
    tags.push_back(tag);
    sendChangeMessage();
}

void TagCollection::removeTag(String tagToRemove) {
    for (auto it = tags.begin(); it != tags.end(); it++) {
        if ((*it) == tagToRemove) {
            tags.erase(it);
            break;
        }
    }
    sendChangeMessage();
}

bool TagCollection::containsTag(String tag) {
    for (auto it = tags.begin(); it != tags.end(); it++) {
        if ((*it) == tag) return true;
    }
    return false;
}


const std::vector<String>& TagCollection::getTagStrs() const {
    return tags;
}