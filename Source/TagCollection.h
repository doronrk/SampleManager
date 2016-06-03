/*
  ==============================================================================

    TagCollection.h
    Created: 2 Jun 2016 2:46:32pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#ifndef TAGCOLLECTION_H_INCLUDED
#define TAGCOLLECTION_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class TagCollection : public ChangeBroadcaster
{
public:
    void addTag(String tag);
    void removeTag(String tag);
    const std::vector<String>& getTagStrs() const;
private:
    std::vector<String> tags;
};

#endif  // TAGCOLLECTION_H_INCLUDED
