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
private ComboBox::Listener,
private TextEditor::Listener
{
public:
    SearchView(ManageModel& manageModel) :
    manageModel(manageModel)
    {
        dao = DAO::getDAO();
        setOpaque (true);
        
        Font f;
        f.setHeight(25.0);
        searchField.addListener(this);
        searchField.setTextToShowWhenEmpty("search for a tag", Colours::grey);
        searchField.setReturnKeyStartsNewLine(false);
        searchField.setFont(f);
        searchField.setColour(TextEditor::ColourIds::outlineColourId, Colours::black);
        
        addAndMakeVisible(listBox);
        addAndMakeVisible(searchField);
        
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
        searchField.setBoundsRelative(0.0, 0.0, 1.0, 0.1);
        listBox.setBoundsRelative(0.0, 0.1, 1.0, 0.9);
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
        if (sound == nullptr) return;
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
        if (row > sounds.size()) return;
        Sound *sound = sounds[row];
        if (sound == nullptr) return;
        manageModel.setActiveSound(sound);
    }
    
private:
    ManageModel& manageModel;
    DAO *dao;
    Array<Sound *> sounds;
    StringArray currentStyleList;
    
    TextEditor searchField;
    ListBox listBox;
    
    
    void comboBoxChanged (ComboBox* box) override
    {

    }
    
    void textEditorReturnKeyPressed(TextEditor &textEditor) override {
        if (&textEditor == &searchField) {
            sounds.clear();
            const std::vector<Sound *>& soundVector = dao->getSoundCollection();
            String text = searchField.getText();
            for (Sound *sound: soundVector) {
                if (text.isEmpty()) {
                    sounds.add(sound);
                } else if (sound->hasTag(text)) {
                    sounds.add(sound);
                }
            }
            repaint();
        }
    }
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SearchView)
};



#endif  // SEARCHVIEW_H_INCLUDED
