/*
  ==============================================================================

    CaptureView.cpp
    Created: 2 May 2016 1:22:04pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "CaptureView.h"

CaptureView::CaptureView(CaptureModel &captureModel) :
captureModel(captureModel),
deviceSelector(captureModel.deviceManager, 0, 2, 0, 2, false, false, true, true)
{
    addAndMakeVisible(deviceSelector);
}

void CaptureView::paint (Graphics& g) {
    g.fillAll(Colours::aliceblue);
}

void CaptureView::resized() {
    deviceSelector.setBoundsRelative(0.0, 0.0, 1.0, 1.0);
}

void CaptureView::changeListenerCallback(ChangeBroadcaster *source)
{
}