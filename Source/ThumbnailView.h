/*
  ==============================================================================

    ThumbnailView.h
    Created: 2 May 2016 4:18:16pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#ifndef THUMBNAILVIEW_H_INCLUDED
#define THUMBNAILVIEW_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class ThumbnailView :
    public Component,
    private ChangeListener
{
public:
    ThumbnailView(AudioThumbnail &thumbnail);
    ~ThumbnailView();
    void paint (Graphics& g) override;
    void resized() override;
    
private:
    void changeListenerCallback(ChangeBroadcaster *source) override;
    
    AudioThumbnail &thumbnail;
    bool displayFullThumb;
};



#endif  // THUMBNAILVIEW_H_INCLUDED
