/*
  ==============================================================================

    DAO.cpp
    Created: 2 May 2016 7:07:49pm
    Author:  Doron Roberts-Kedes

  ==============================================================================
*/

#include "DAO.h"

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
 Include directly the different
 headers from cppconn/ and mysql_driver.h + mysql_util.h
 (and mysql_connection.h). This will reduce your build time!

#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
 */

DAO *DAO::s_dao = nullptr;
std::mutex DAO::singletonGuard;

using namespace std;
void DAO::initDBconn() {
    cout << endl;
    cout << "Let's have MySQL count from 10 to 1..." << endl;
    /*
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;
        sql::PreparedStatement *pstmt;
        
        // Create a connection
        driver = sql::mysql::get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "");
        // Connect to the MySQL test database
        con->setSchema("test");
        
        stmt = con->createStatement();
        stmt->execute("DROP TABLE IF EXISTS test");
        stmt->execute("CREATE TABLE test(id INT)");
        delete stmt;
        
        // '?' is the supported placeholder syntax
        pstmt = con->prepareStatement("INSERT INTO test(id) VALUES (?)");
        for (int i = 1; i <= 10; i++) {
            pstmt->setInt(1, i);
            pstmt->executeUpdate();
        }
        delete pstmt;
        
        // Select in ascending order
        pstmt = con->prepareStatement("SELECT id FROM test ORDER BY id ASC");
        res = pstmt->executeQuery();
        
        // Fetch in reverse = descending order!
        res->afterLast();
        while (res->previous())
            cout << "\t... MySQL counts: " << res->getInt("id") << endl;
        delete res;
        
        delete pstmt;
        delete con;
        
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    
    cout << endl;
    */
}

using namespace juce;
// private constructor
DAO::DAO() {
    init();
}

DAO *DAO::getDAO() {
    singletonGuard.lock();
    if (s_dao == nullptr) {
        s_dao = new DAO();
    }
    singletonGuard.unlock();
    return s_dao;
}

void DAO::initSoundCache() {
    File support = DAO::getAppSupportDir();
    Array<File> children;
    support.findChildFiles(children, File::findFiles, false, "*.data");
    WavAudioFormat wavForm;
    for (File child: children) {
        FileInputStream *fis = child.createInputStream();
        String str = fis->readEntireStreamAsString();
        Sound *s = new Sound(str);
        
        String audiofilename = s->getName() + ".wav";
        File audioDataFile(support.getChildFile(audiofilename));
        FileInputStream *audiofis = audioDataFile.createInputStream();
        if (audiofis == nullptr) continue;
        ScopedPointer<AudioFormatReader> reader = wavForm.createReaderFor(audiofis, false);
        // TODO better error checking and file regex filtering
        if (reader == nullptr) continue;
        // TODO more sensible conversion between float vectors and juce sample buffers
        int nSamples = reader->lengthInSamples;
        AudioSampleBuffer buff(reader->numChannels, nSamples);
        reader->read(&buff, 0, nSamples, 0, true, true);
        s->prepareRecord(buff.getNumChannels(), reader->sampleRate);
        s->appendAudio(buff.getArrayOfReadPointers(), buff.getNumChannels(), buff.getNumSamples());
        
        soundCollection.push_back(s);
        std::cout << s->getAsString() << std::endl;
    }
}


void DAO::init()
{
    File support(File::getSpecialLocation(File::userApplicationDataDirectory)
                 .getChildFile(APP_DATA_DIRNAME));
    if (!support.exists()) {
        support.createDirectory();
    }
    initSoundCache();
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

bool DAO::writeSound(Sound *sound) {
    if (sound == nullptr) return false;
    File support = DAO::getAppSupportDir();
    File audioDataFile(support.getNonexistentChildFile(sound->getName(), ".wav"));
    WavAudioFormat wavForm;
    FileOutputStream* outStream = audioDataFile.createOutputStream();
    const std::vector<std::vector<float>>& audioData = sound->getAudiodata();
    int nChannels = audioData.size();
    if (nChannels == 0) return false;
    int nSamples = audioData[0].size();
    ScopedPointer<AudioFormatWriter> writer = wavForm.createWriterFor(outStream, 44100, nChannels, 24, nullptr, 0);
    ;
    AudioSampleBuffer buff(nChannels, nSamples);
    for (int i = 0; i < nChannels; i++) {
        float *w = buff.getWritePointer(i);
        for (int j = 0; j < nSamples; j++) {
            w[j] = audioData[i][j];
        }
    }
    writer->writeFromAudioSampleBuffer(buff, 0, nSamples);
    File dataFile(support.getNonexistentChildFile(sound->getName(), ".data"));
    ScopedPointer<FileOutputStream> fos = dataFile.createOutputStream();
    fos->writeString(sound->getAsString());
    return true;
}

const std::vector<Sound *>& DAO::getSoundCollection() {
    return soundCollection;
}

