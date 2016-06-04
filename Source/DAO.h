/*
  ==============================================================================

    DAO.h
    Created: 2 May 2016 7:07:49pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#ifndef DAO_H_INCLUDED
#define DAO_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Sound.h"

#define APP_DATA_DIRNAME "SampleManager"

namespace DAO {
    void init();
    void initDBconn();
    File getAppSupportDir();
    File getTempCaptureFile();
    bool writeSound(Sound *sound);
}

#endif  // DAO_H_INCLUDED
