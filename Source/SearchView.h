/*
  ==============================================================================

    SearchView.h
    Created: 2 May 2016 1:22:09pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#ifndef SEARCHVIEW_H_INCLUDED
#define SEARCHVIEW_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"
#include "DAO.h"
#include "Sound.h"

class SearchView  : public Component,
private ListBoxModel,
private Slider::Listener,
private Button::Listener,
private ComboBox::Listener
{
public:
    SearchView(ManageModel& manageModel) :
    manageModel(manageModel)
    {
        dao = DAO::getDAO();
        setOpaque (true);
        
        addAndMakeVisible (listBox);
        
        const std::vector<Sound *>& soundVector = dao->getSoundCollection();
        for (Sound* sound: soundVector) {
            sounds.add(sound);
        }
        
        listBox.setRowHeight (40);
        listBox.setModel (this);   // Tell the listbox where to get its data model
        listBox.setMultipleSelectionEnabled(false);
    }
    
    //==============================================================================
    void paint (Graphics& g) override
    {
        g.fillAll(Colours::azure);
    }
    
    void resized() override
    {
        listBox.setBoundsRelative(0.0, 0.0, 1.0, 1.0);
    }
    
    void sliderValueChanged (Slider* sliderThatWasMoved) override
    {

    }
    
    void buttonClicked (Button* buttonThatWasClicked) override
    {
        
    }
    
    // The following methods implement the ListBoxModel virtual methods:
    int getNumRows() override
    {
        return sounds.size();
    }
    
    void paintListBoxItem (int rowNumber, Graphics& g,
                           int width, int height, bool rowIsSelected) override
    {
        if (rowIsSelected)
            g.fillAll (Colours::lightblue);
        
        Sound *sound = sounds[rowNumber];
        AttributedString s;
        s.setWordWrap (AttributedString::none);
        s.setJustification (Justification::centred);
        Font f;
        f.setHeight(400.0);
        s.setFont(f);
        s.append(sound->getName());
        
        s.draw (g, Rectangle<int> (width, height).expanded (-4, 50).toFloat());
    }
    
    void selectedRowsChanged (int /*lastRowselected*/) override
    {
        int row = listBox.getSelectedRow();
        manageModel.setActiveSound(sounds[row]);
    }
    
private:
    ManageModel& manageModel;
    DAO *dao;
    Array<Sound *> sounds;
    StringArray currentStyleList;
    
    ListBox listBox;
    
    
    void comboBoxChanged (ComboBox* box) override
    {

    }
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SearchView)
};



#endif  // SEARCHVIEW_H_INCLUDED
