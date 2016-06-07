/*
  ==============================================================================

    Sound.h
    Created: 17 May 2016 9:24:03pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED

#include <vector>
#include <string>
#include <mutex>
#include "../JuceLibraryCode/JuceHeader.h"
#include "TagCollection.h"

class Sound {
public:
    Sound();
    void prepareRecord(int numChannels, double sampleRate);
    void appendAudio(const float **data, int numChannels, int numSamples);
    const String& getName();
    void setName(String name);
    void addTag(String tag);
    bool hasTag(String tag);
    TagCollection* getTagCollection();
    const std::vector<std::vector<float>>& getAudiodata() const;
    AudioThumbnail *getThumbnail();
    
private:
    std::mutex audiodataLock;
    std::vector<std::vector<float>> audiodata;
    TagCollection tags;
    String name;
    String filepath;
    AudioFormatManager manager;
    AudioThumbnailCache cache;
    AudioThumbnail thumbnail;
};


#endif  // SOUND_H_INCLUDED
