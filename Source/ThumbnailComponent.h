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

class ThumbnailComponent :
    public Component,
    private ChangeListener
{
public:
    ThumbnailComponent();
    ~ThumbnailComponent();
    void paint (Graphics& g) override;
    void resized() override;
    void setThumbnail(AudioThumbnail *thumb);
    void setDisplayFullThumb(bool full);
    
private:
    void changeListenerCallback(ChangeBroadcaster *source) override;
    bool hasThumbnail();
    AudioThumbnail *thumbnail;
    bool displayFullThumb;
};



#endif  // THUMBNAILVIEW_H_INCLUDED
