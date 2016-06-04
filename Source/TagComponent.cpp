/*
  ==============================================================================

    TagComponent.cpp
    Created: 3 Jun 2016 2:43:42pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "TagComponent.h"

TagComponent::TagComponent(String name) :
TextButton(name), name(name)
{
    setClickingTogglesState(true);
}

void TagComponent::paintButton (Graphics& g, bool isMouseOverButton, bool isButtonDown)
{
    LookAndFeel& lf = getLookAndFeel();
    
    lf.drawButtonBackground (g, *this,
                             findColour (getToggleState() ? buttonOnColourId : buttonColourId),
                             false, getToggleState());
    
    lf.drawButtonText (g, *this, isMouseOverButton, isButtonDown);
}