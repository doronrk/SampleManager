/*
  ==============================================================================

    DAO.cpp
    Created: 2 May 2016 7:07:49pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "DAO.h"

void DAO::init()
{
    File support(File::getSpecialLocation(File::userApplicationDataDirectory)
                 .getChildFile(APP_DATA_DIRNAME));
    if (!support.exists()) {
        support.createDirectory();
    }
}

File DAO::getAppSupportDir()
{
    File support(File::getSpecialLocation(File::userApplicationDataDirectory)
                 .getChildFile(APP_DATA_DIRNAME));
    if (!support.exists()) {
        support.createDirectory();
    }
    return support;
}

File DAO::getTempCaptureFile()
{
    File support = DAO::getAppSupportDir();
    File captureFile(support.getNonexistentChildFile("temp-capture", ".wav"));
    return captureFile;
}