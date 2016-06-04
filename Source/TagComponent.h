/*
  ==============================================================================

    TagComponent.h
    Created: 3 Jun 2016 2:43:42pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#ifndef TAGCOMPONENT_H_INCLUDED
#define TAGCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class TagComponent : public TextButton
{
public:
    TagComponent(String name);
    void paintButton (Graphics& g, bool isMouseOverButton, bool isButtonDown) override;
private:
    String name;
};

#endif  // TAGCOMPONENT_H_INCLUDED
