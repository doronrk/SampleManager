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

class SearchView  : public Component,
private ListBoxModel,
private Slider::Listener,
private Button::Listener,
private ComboBox::Listener
{
public:
    SearchView()
    {
        setOpaque (true);
        
        addAndMakeVisible (listBox);
        
        Font::findFonts (fonts);   // Generate the list of fonts
        
        listBox.setRowHeight (20);
        listBox.setModel (this);   // Tell the listbox where to get its data model

        // set up the layout and resizer bars..
        verticalLayout.setItemLayout (0, -0.2, -0.8, -0.35); // width of the font list must be
        // between 20% and 80%, preferably 50%
        verticalLayout.setItemLayout (1, 8, 8, 8);           // the vertical divider drag-bar thing is always 8 pixels wide
        verticalLayout.setItemLayout (2, 150, -1.0, -0.65);  // the components on the right must be
        // at least 150 pixels wide, preferably 50% of the total width
        
        verticalDividerBar = new StretchableLayoutResizerBar (&verticalLayout, 1, true);
        addAndMakeVisible (verticalDividerBar);
        
        // ..and pick a random font to select intially
        listBox.selectRow (Random::getSystemRandom().nextInt (fonts.size()));
}
    
    //==============================================================================
    void paint (Graphics& g) override
    {
        g.fillAll(Colours::azure);
    }
    
    void resized() override
    {
        Rectangle<int> r (getLocalBounds().reduced (5));
        
        // lay out the list box and vertical divider..
        Component* vcomps[] = { &listBox, verticalDividerBar, nullptr };
        
        verticalLayout.layOutComponents (vcomps, 3,
                                         r.getX(), r.getY(), r.getWidth(), r.getHeight(),
                                         false,     // lay out side-by-side
                                         true);     // resize the components' heights as well as widths
        
        
        r.removeFromLeft (verticalDividerBar->getRight());
        
        const int labelWidth = 60;
        
        Rectangle<int> row (r.removeFromBottom (30));
        row.removeFromLeft (labelWidth);
        
        r.removeFromBottom (8);
        r.removeFromBottom (8);
        r.removeFromBottom (8);
        r.removeFromBottom (8);
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
        return fonts.size();
    }
    
    void paintListBoxItem (int rowNumber, Graphics& g,
                           int width, int height, bool rowIsSelected) override
    {
        if (rowIsSelected)
            g.fillAll (Colours::lightblue);
        
        Font font (fonts [rowNumber]);
        
        AttributedString s;
        s.setWordWrap (AttributedString::none);
        s.setJustification (Justification::centredLeft);
        s.append (font.getTypefaceName(), font.withPointHeight (height * 0.7f), Colours::black);
        s.append ("   " + font.getTypefaceName(), Font (height * 0.5f, Font::italic), Colours::grey);
        
        s.draw (g, Rectangle<int> (width, height).expanded (-4, 50).toFloat());
    }
    
    void selectedRowsChanged (int /*lastRowselected*/) override
    {
        refreshPreviewBoxFont();
    }
    
private:
    Array<Font> fonts;
    StringArray currentStyleList;
    
    ListBox listBox;
    
    StretchableLayoutManager verticalLayout;
    ScopedPointer<StretchableLayoutResizerBar> verticalDividerBar;
    
    void refreshPreviewBoxFont()
    {
        const bool useStyle = ! (bold || italic);
        
        Font font (fonts [listBox.getSelectedRow()]);
        
        if (bold)    font = font.boldened();
        if (italic)  font = font.italicised();
        
        updateStylesList (font);
        
    }
    
    void updateStylesList (const Font& newFont)
    {
        const StringArray newStyles (newFont.getAvailableStyles());
        
        if (newStyles != currentStyleList)
        {
            currentStyleList = newStyles;
            
        }
    }
    
    void comboBoxChanged (ComboBox* box) override
    {

    }
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SearchView)
};



#endif  // SEARCHVIEW_H_INCLUDED
