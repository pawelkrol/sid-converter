#include "testsidfile.h"

const SidData SidFileTest :: getDefaultData() {
  const unsigned short int dataSize = 9;
  const byte data [dataSize] = { 0x00, 0x10, 0x4c, 0x06, 0x10, 0x4c, 0x06, 0x10, 0x60 };
  SidData sidData = SidData(data, dataSize);
  return sidData;
}

const SidHeaderV2 SidFileTest :: getDefaultHeader() {
  // TODO: add missing implementation...
  SidHeaderV2 sidHeader = SidHeaderV2();
  // TODO: set some values differently...
  return sidHeader;
}

const SidFile SidFileTest :: getDefaultFile() {
  // TODO: add missing implementation...
  SidFile sidFile = SidFile();
  return sidFile;
}

const SidData SidFileTest :: getEmptyData() {
  const unsigned short int dataSize = 2;
  const byte data [dataSize] = { 0x00, 0x00 }; // TODO: $0000 ???
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
  // TODO: add missing implementation...
}

void SidFileTest :: tearDown() {
  // TODO: add missing implementation...
}

void SidFileTest :: testBuildEmpty() {
  const SidFile *empty = new SidFile();
// TODO: REMOVE IT!!!
printf("\n>>> new SidFile() <<<\n");
empty->showDataDump();
  const SidFile expected = getEmptyFile();
// TODO: REMOVE IT!!!
printf("\n>>> getEmptyFile() <<<\n");
expected.showDataDump();
  CPPUNIT_ASSERT(*empty == expected);
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
