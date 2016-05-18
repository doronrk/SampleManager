/*
  ==============================================================================

    ManageModel.cpp
    Created: 2 May 2016 11:58:45am
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "ManageModel.h"

bool ManageModel::hasActiveSound() const {
    return activeSound != nullptr;
}

const std::shared_ptr<Sound> ManageModel::getActiveSound() const {
    return activeSound;
}

void ManageModel::setActiveSound(Sound* sound) {
    activeSound.reset(sound);
}