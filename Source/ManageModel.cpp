/*
  ==============================================================================

    ManageModel.cpp
    Created: 2 May 2016 11:58:45am
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "ManageModel.h"

ManageModel::ManageModel() :
    activeSound(nullptr)
{}

bool ManageModel::hasActiveSound() const {
    return activeSound != nullptr;
}

Sound *ManageModel::getActiveSound() const {
    return activeSound;
}

void ManageModel::setActiveSound(Sound* sound) {
    activeSound = sound;
    sendChangeMessage();
}

bool ManageModel::addTag(String tag) {
    if (!hasActiveSound()) return false;
    if (tag.isEmpty()) return false;
    if (activeSound->hasTag(tag)) return false;
    activeSound->addTag(tag);
    return true;
}