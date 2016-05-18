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
    thumbnail.addBlock(audiodata.size(), buffer, 0, numSamples);
    
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

void Sound::addTag(const std::string& tag) {
    tags.push_back(tag);
}

const std::vector<std::string>& Sound::getTags() const {
    return tags;
}

const std::vector<std::vector<float>>& Sound::getAudiodata() const {
    return audiodata;
}

AudioThumbnail *Sound::getThumbnail() {
    return &thumbnail;
}
