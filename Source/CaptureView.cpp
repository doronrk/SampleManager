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
    captureModel.addChangeListener(this);
    addAndMakeVisible(deviceSelector);
    addAndMakeVisible(recordButton);
    recordButton.setButtonText("record");
    recordButton.addListener(this);
}

void CaptureView::paint (Graphics& g) {
    g.fillAll(Colours::aliceblue);
}

void CaptureView::resized() {
    float vertSplit = .2;
    recordButton.setBoundsRelative(0.0, 0.0, vertSplit, 1.0);
    deviceSelector.setBoundsRelative(vertSplit, 0.0, 1.0 - vertSplit, 1.0);
}

void CaptureView::buttonClicked(Button *button) {
    if (button == &recordButton) {
        if (captureModel.isRecording()) {
            captureModel.stopRecording();
        } else {
            captureModel.startRecording();
        }
    }
}

void CaptureView::updateRecordState(bool recording) {
    std::string text = recording ? "stop" : "record";
    recordButton.setButtonText(text);
}


void CaptureView::changeListenerCallback(ChangeBroadcaster *source) {
    if (source == &captureModel) {
        updateRecordState(captureModel.isRecording());
    }
}

