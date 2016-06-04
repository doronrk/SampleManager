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
#include "TagComponent.h"

class TagCollectionComponent:
    public Component,
    private ChangeListener
{
public:
    TagCollectionComponent();
    void paint (Graphics& g) override;
    void resized() override;
    void setTags(TagCollection *newTags);
    
private:
    void changeListenerCallback(ChangeBroadcaster *source) override;
    bool keyPressed(const KeyPress &key) override;
    void refreshTags();
    void handleBackspacePressed();
    TagCollection *tags;
    OwnedArray<TagComponent> tagComponents;
};



#endif  // TAGFIELD_H_INCLUDED
