/*
  ==============================================================================

    CaptureView.cpp
    Created: 2 May 2016 1:22:04pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "CaptureView.h"

CaptureView::CaptureView(CaptureModel &captureModel) :
audioDeviceSelector(captureModel.deviceManager, 0, 2, 0, 2, false, false, true, true)
{

}

void CaptureView::paint (Graphics& g) {
    g.fillAll(Colours::aliceblue);
}