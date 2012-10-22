#include "testsiddata.h"

void SidDataTest :: setUp() {
  siddata_01 = new SidData();
  siddata_02 = new SidData();
}

void SidDataTest :: tearDown() {
  delete siddata_01;
  delete siddata_02;
}

void SidDataTest :: testEquality() {
  CPPUNIT_ASSERT(*siddata_01 == *siddata_02);
  CPPUNIT_ASSERT(!(*siddata_01 != *siddata_02));
}

void SidDataTest :: testGetAddress() {
  // TODO: fix this dummy test and write some real code...
  CPPUNIT_ASSERT(0 == 1);
}

void SidDataTest :: testGetFileData() {
  // TODO: fix this dummy test and write some real code...
  CPPUNIT_ASSERT(0 == 1);
}

void SidDataTest :: testGetRawData() {
  // TODO: fix this dummy test and write some real code...
  CPPUNIT_ASSERT(0 == 1);
}

void SidDataTest :: testEmptyInitialization() {
  short int length;
  const byte *fileData = siddata_01->getFileData(length);
  const byte expectedFileData [2] = { 0x00, 0x00 };

  CPPUNIT_ASSERT(length == 2);
  CPPUNIT_ASSERT(TestUtils::compare(fileData, expectedFileData, length) == 0);

  delete fileData;

  const byte *rawData = siddata_01->getRawData(length);

  CPPUNIT_ASSERT(length == 0);

  delete rawData;
}

CppUnit::Test *SidDataTest :: suite() {
  CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("SidDataTest");

  suiteOfTests->addTest(new CppUnit::TestCaller<SidDataTest>(
    "testEquality",
    &SidDataTest::testEquality
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidDataTest>(
    "testGetAddress",
    &SidDataTest::testGetAddress
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidDataTest>(
    "testGetFileData",
    &SidDataTest::testGetFileData
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidDataTest>(
    "testGetRawData",
    &SidDataTest::testGetRawData
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidDataTest>(
    "testEmptyInitialization",
    &SidDataTest::testEquality
  ));

  return suiteOfTests;
}
