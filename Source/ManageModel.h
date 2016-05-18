/*
  ==============================================================================

    ManageModel.h
    Created: 2 May 2016 11:58:45am
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#ifndef MANAGEMODEL_H_INCLUDED
#define MANAGEMODEL_H_INCLUDED

#include "Sound.h"

class ManageModel : public ChangeBroadcaster {
public:
    bool hasActiveSound() const;
    Sound *getActiveSound() const;
    void setActiveSound(Sound* sound);
private:
    Sound *activeSound;
};



#endif  // MANAGEMODEL_H_INCLUDED
