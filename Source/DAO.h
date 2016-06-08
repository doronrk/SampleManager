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
#include <mutex>

#define APP_DATA_DIRNAME "SampleManager"

class DAO {
    static std::mutex singletonGuard;
    static DAO *s_dao; // singleton instance
public:
    static DAO *getDAO();
    File getAppSupportDir();
    File getTempCaptureFile();
    bool writeSound(Sound *sound);
    const std::vector<Sound *>& getSoundCollection();
private:
    DAO(); // private constructor
    void init();
    void initSoundCache();
    void initDBconn();
    std::vector<Sound *> soundCollection;
};

#endif  // DAO_H_INCLUDED
