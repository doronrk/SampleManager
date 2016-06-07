/*
  ==============================================================================

    Sound.cpp
    Created: 17 May 2016 9:24:03pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "Sound.h"

#define THUMB_RES 512
#define THUMB_CACHE_CAP 10

Sound::Sound() :
cache(THUMB_CACHE_CAP),
thumbnail(THUMB_RES, manager, cache)
{}

Sound::Sound(String str) :
cache(THUMB_CACHE_CAP),
thumbnail(THUMB_RES, manager, cache)
{
    StringArray lines;
    lines.addTokens(str, "\n", "\"");
    name = lines[0];
    StringArray tags;
    tags.addTokens(lines[1], ",", "\"");
    for (const String& tag: tags) {
        addTag(tag);
    }
}

void Sound::prepareRecord(int numChannels, double sampleRate) {
    audiodataLock.lock();
    audiodata.clear();
    audiodata.resize(numChannels);
    audiodataLock.unlock();
    thumbnail.reset(numChannels, sampleRate);
}

void Sound::appendAudio(const float **data, int numChannels, int numSamples) {
    // TODO: assert numChannels = audiodata.size()

    // update the thumbnail
    const AudioSampleBuffer buffer(const_cast<float**> (data), numChannels, numSamples);
    thumbnail.addBlock(audiodata[0].size(), buffer, 0, numSamples);
    
    // update the audio data
    audiodataLock.lock();
    for (int i = 0; i < numChannels; i++) {
        std::vector<float>& channel = audiodata[i];
        const float *inchannel = data[i];
        for (int j = 0; j < numSamples; j++) {
            channel.push_back(inchannel[j]);
        }
    }
    audiodataLock.unlock();
}

const String& Sound::getName() {
    return name;
}


void Sound::setName(String name) {
    this->name = name;
}


void Sound::addTag(String tag) {
    if (tag.isEmpty()) return;
    tags.addTag(tag);
}

bool Sound::hasTag(String tag) {
    return tags.containsTag(tag);
}

TagCollection *Sound::getTagCollection() {
    return &tags;
}

const std::vector<std::vector<float>>& Sound::getAudiodata() const {
    return audiodata;
}

AudioThumbnail *Sound::getThumbnail() {
    return &thumbnail;
}

ValueTree Sound::getValueTree() {
    ValueTree vt("sound");
    vt.setProperty("name", name, 0);
    const Array<String>& ts = tags.getTagStrs();
    Array<var> vs;
    vs.addArray(ts);
    vt.setProperty("tags", vs, 0);
    return vt;
}

String Sound::getAsString() {
    String s = name;
    s += "\n";
    for (const String& t: tags.getTagStrs()) {
        s += t + ",";
    }
    return s;
}
