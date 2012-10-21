#include "string.h"

#include "testsidheader.h"
#include "testutils.h"

void SidHeaderTest :: setUp() {
  sidheader_01 = new SidHeaderV2();
  sidheader_02 = new SidHeaderV2();
}

void SidHeaderTest :: tearDown() {
  delete sidheader_01;
  delete sidheader_02;
}

void SidHeaderTest :: testEquality() {
  CPPUNIT_ASSERT(*sidheader_01 == *sidheader_02);
  CPPUNIT_ASSERT(!(*sidheader_01 != *sidheader_02));
}

void SidHeaderTest :: testMagicIDInitialization() {
  const byte *magicID            = sidheader_01->getMagicID();
  const byte expectedMagicID [4] = { 0x50, 0x53, 0x49, 0x44 };

  CPPUNIT_ASSERT(TestUtils::compare(magicID, expectedMagicID, MAGICID_SIZE) == 0);

  delete magicID;
}

void SidHeaderTest :: testVersionInitialization() {
  const byte *version            = sidheader_01->getVersion();
  const byte expectedVersion [2] = { 0x00, 0x02 };

  CPPUNIT_ASSERT(TestUtils::compare(version, expectedVersion, VERSION_SIZE) == 0);

  delete version;

  const short int versionNum = sidheader_01->getVersionNum();
  CPPUNIT_ASSERT(versionNum == 0x0002);
}

void SidHeaderTest :: testDataOffsetInitialization() {
  const byte *dataOffset            = sidheader_01->getDataOffset();
  const byte expectedDataOffset [2] = { 0x00, 0x7c };

  CPPUNIT_ASSERT(TestUtils::compare(dataOffset, expectedDataOffset, DATA_OFFSET_SIZE) == 0);

  delete dataOffset;

  const short int dataOffsetNum = sidheader_01->getDataOffsetNum();
  CPPUNIT_ASSERT(dataOffsetNum == 0x007c);
}

void SidHeaderTest :: testLoadAddressInitialization() {
  const byte *loadAddress            = sidheader_01->getLoadAddress();
  const byte expectedLoadAddress [2] = { 0x00, 0x00 };

  CPPUNIT_ASSERT(TestUtils::compare(loadAddress, expectedLoadAddress, LOAD_ADDRESS_SIZE) == 0);

  delete loadAddress;

  const short int loadAddressNum = sidheader_01->getLoadAddressNum();
  CPPUNIT_ASSERT(loadAddressNum == 0x0000);
}

void SidHeaderTest :: testInitAddressInitialization() {
  const byte *initAddress            = sidheader_01->getInitAddress();
  const byte expectedInitAddress [2] = { 0x10, 0x00 };

  CPPUNIT_ASSERT(TestUtils::compare(initAddress, expectedInitAddress, INIT_ADDRESS_SIZE) == 0);

  delete initAddress;

  const short int initAddressNum = sidheader_01->getInitAddressNum();
  CPPUNIT_ASSERT(initAddressNum == 0x1000);
}

void SidHeaderTest :: testPlayAddressInitialization() {
  const byte *playAddress            = sidheader_01->getPlayAddress();
  const byte expectedPlayAddress [2] = { 0x10, 0x03 };

  CPPUNIT_ASSERT(TestUtils::compare(playAddress, expectedPlayAddress, PLAY_ADDRESS_SIZE) == 0);

  delete playAddress;

  const short int playAddressNum = sidheader_01->getPlayAddressNum();
  CPPUNIT_ASSERT(playAddressNum == 0x1003);
}

void SidHeaderTest :: testSongsInitialization() {
  const byte *songs            = sidheader_01->getSongs();
  const byte expectedSongs [2] = { 0x00, 0x01 };

  CPPUNIT_ASSERT(TestUtils::compare(songs, expectedSongs, SONGS_SIZE) == 0);

  delete songs;

  const short int songsNum = sidheader_01->getSongsNum();
  CPPUNIT_ASSERT(songsNum == 0x0001);
}

void SidHeaderTest :: testStartSongInitialization() {
  const byte *startSong            = sidheader_01->getStartSong();
  const byte expectedStartSong [2] = { 0x00, 0x01 };

  CPPUNIT_ASSERT(TestUtils::compare(startSong, expectedStartSong, START_SONG_SIZE) == 0);

  delete startSong;

  const short int startSongNum = sidheader_01->getStartSongNum();
  CPPUNIT_ASSERT(startSongNum == 0x0001);
}

void SidHeaderTest :: testSpeedInitialization() {
  const byte *speed            = sidheader_01->getSpeed();
  const byte expectedSpeed [4] = { 0x00, 0x00, 0x00, 0x00 };

  CPPUNIT_ASSERT(TestUtils::compare(speed, expectedSpeed, SPEED_SIZE) == 0);

  delete speed;
}

void SidHeaderTest :: testEmptyInitialization() {
  /*** TODO: implementation missing! ***/
  /*** TODO: add individual tests for all other header fields! ***/

  const byte *header               = sidheader_01->get();
  const byte expectedHeader [0x7c] = {
    0x50, 0x53, 0x49, 0x44, 0x00, 0x02, 0x00, 0x7c, 0x00, 0x00, 0x10, 0x00, 0x10, 0x03, 0x00, 0x01,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00
  };

  CPPUNIT_ASSERT(TestUtils::compare(header, expectedHeader, HEADER_V2_SIZE) == 0);

  delete header;
}

CppUnit::Test *SidHeaderTest :: suite() {
  CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("SidHeaderTest");

  suiteOfTests->addTest(new CppUnit::TestCaller<SidHeaderTest>(
    "testEquality",
    &SidHeaderTest::testEquality
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidHeaderTest>(
    "testMagicIDInitialization",
    &SidHeaderTest::testMagicIDInitialization
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidHeaderTest>(
    "testVersionInitialization",
    &SidHeaderTest::testVersionInitialization
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidHeaderTest>(
    "testDataOffsetInitialization",
    &SidHeaderTest::testDataOffsetInitialization
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidHeaderTest>(
    "testLoadAddressInitialization",
    &SidHeaderTest::testLoadAddressInitialization
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidHeaderTest>(
    "testInitAddressInitialization",
    &SidHeaderTest::testInitAddressInitialization
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidHeaderTest>(
    "testPlayAddressInitialization",
    &SidHeaderTest::testPlayAddressInitialization
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidHeaderTest>(
    "testSongsInitialization",
    &SidHeaderTest::testSongsInitialization
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidHeaderTest>(
    "testStartSongInitialization",
    &SidHeaderTest::testStartSongInitialization
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidHeaderTest>(
    "testSpeedInitialization",
    &SidHeaderTest::testSpeedInitialization
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidHeaderTest>(
    "testEmptyInitialization",
    &SidHeaderTest::testEmptyInitialization
  ));

  return suiteOfTests;
}
