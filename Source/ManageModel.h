/*
  ==============================================================================

    ManageModel.h
    Created: 2 May 2016 11:58:45am
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#ifndef MANAGEMODEL_H_INCLUDED
#define MANAGEMODEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Sound.h"

class ManageModel : public ChangeBroadcaster {
public:
    ManageModel();
    bool hasActiveSound() const;
    Sound *getActiveSound() const;
    void setActiveSound(Sound* sound);
    
    // returns true if successfully added, false otherwise
    bool addTag(String tag);
private:
    Sound *activeSound;
};


#endif  // MANAGEMODEL_H_INCLUDED
