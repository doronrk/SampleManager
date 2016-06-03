/*
  ==============================================================================

    TagField.h
    Created: 2 Jun 2016 2:22:52pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#ifndef TAGFIELD_H_INCLUDED
#define TAGFIELD_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "TagCollection.h"

class TagCollectionComponent:
    public Component,
    private ChangeListener
{
public:
    void paint (Graphics& g) override;
    void resized() override;
    void setTags(TagCollection *newTags);
    
private:
    void changeListenerCallback(ChangeBroadcaster *source) override;
    TagCollection *tags;
};



#endif  // TAGFIELD_H_INCLUDED
