#include "testsidfile.h"

const SidData SidFileTest :: getDefaultData() {
  const unsigned short int dataSize = 9;
  const byte data [dataSize] = { 0x00, 0x10, 0x4c, 0x06, 0x10, 0x4c, 0x06, 0x10, 0x60 };
  SidData sidData = SidData(data, dataSize);
  return sidData;
}

const SidHeaderV2 SidFileTest :: getDefaultHeader() {
  SidHeaderV2 sidHeader = SidHeaderV2();
  sidHeader.setTitleString("sid-converter");
  sidHeader.setAuthorString("Pawel Krol");
  sidHeader.setCopyrightString("(C) 2013 Pawel Krol");
  return sidHeader;
}

const SidFile SidFileTest :: getDefaultFile() {
  const SidHeaderV2 header = getDefaultHeader();
  const SidData data = getDefaultData();
  SidFile sidFile = SidFile(header, data);
  return sidFile;
}

const SidData SidFileTest :: getEmptyData() {
  const unsigned short int dataSize = 2;
  const byte data [dataSize] = { 0x00, 0x00 };
  SidData sidData = SidData(data, dataSize);
  return sidData;
}

const SidHeaderV2 SidFileTest :: getEmptyHeader() {
  SidHeaderV2 sidHeader = SidHeaderV2();
  return sidHeader;
}

const SidFile SidFileTest :: getEmptyFile() {
  const SidHeaderV2 header = getEmptyHeader();
  const SidData data = getEmptyData();
  SidFile sidFile = SidFile(header, data);
  return sidFile;
}

void SidFileTest :: setUp() {
  sidfile_01 = new SidFile();
  sidfile_02 = new SidFile();
  *sidfile_01 = getEmptyFile();
  *sidfile_02 = getDefaultFile();
}

void SidFileTest :: tearDown() {
  delete sidfile_01;
  delete sidfile_02;
}

void SidFileTest :: testBuildEmpty() {
  const SidFile *empty = new SidFile();
// TODO: REMOVE IT!!!
//printf("\n>>> new SidFile() <<<\n");
//empty->showDataDump();
  CPPUNIT_ASSERT(*empty == *sidfile_01);
  delete empty;
}

void SidFileTest :: testBuildFromFile() {
  // TODO: add missing implementation...
  CPPUNIT_ASSERT(1 == 0);
}

void SidFileTest :: testBuildFromData() {
  // TODO: add missing implementation...
  CPPUNIT_ASSERT(1 == 0);
}

void SidFileTest :: testBuildLoadFile() {
  // TODO: add missing implementation...
  CPPUNIT_ASSERT(1 == 0);
}

void SidFileTest :: testBuildSaveFile() {
  // TODO: add missing implementation...
  CPPUNIT_ASSERT(1 == 0);
}

CppUnit::Test *SidFileTest :: suite() {
  CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("SidFileTest");

  suiteOfTests->addTest(new CppUnit::TestCaller<SidFileTest>(
    "testBuildEmpty",
    &SidFileTest::testBuildEmpty
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidFileTest>(
    "testBuildFromFile",
    &SidFileTest::testBuildFromFile
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidFileTest>(
    "testBuildFromData",
    &SidFileTest::testBuildFromData
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidFileTest>(
    "testBuildLoadFile",
    &SidFileTest::testBuildLoadFile
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidFileTest>(
    "testBuildSaveFile",
    &SidFileTest::testBuildSaveFile
  ));

  return suiteOfTests;
}
