/*
  ==============================================================================

    ManageModel.h
    Created: 2 May 2016 11:58:45am
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#ifndef MANAGEMODEL_H_INCLUDED
#define MANAGEMODEL_H_INCLUDED

#include <memory>
#include "Sound.h"

class ManageModel {
public:
    bool hasActiveSound() const;
    const std::shared_ptr<Sound> getActiveSound() const;
    void setActiveSound(Sound* sound);
private:
    std::shared_ptr<Sound> activeSound;
};



#endif  // MANAGEMODEL_H_INCLUDED
