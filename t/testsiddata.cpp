#include "testsiddata.h"

void SidDataTest :: setUp() {
  siddata_01 = new SidData();
  siddata_02 = new SidData();

  unsigned short int dataSize = 9;
  const byte data [9] = { 0x00, 0x10, 0x4c, 0x06, 0x10, 0x4c, 0x06, 0x10, 0x60 };

  siddata_03 = new SidData(data, dataSize);
  siddata_04 = new SidData(data, dataSize);
}

void SidDataTest :: tearDown() {
  delete siddata_01;
  delete siddata_02;
}

void SidDataTest :: testEquality() {
  CPPUNIT_ASSERT(*siddata_01 == *siddata_02);
  CPPUNIT_ASSERT(*siddata_03 == *siddata_04);
  CPPUNIT_ASSERT(*siddata_01 != *siddata_03);
  CPPUNIT_ASSERT(!(*siddata_01 != *siddata_02));
}

void SidDataTest :: testGetAddress() {
  const MemoryAddress memaddr_01 = siddata_01->getAddress();
  const MemoryAddress memaddr_03 = siddata_03->getAddress();

  CPPUNIT_ASSERT(memaddr_01 == MemoryAddress(0x0000));
  CPPUNIT_ASSERT(memaddr_03 == MemoryAddress(0x1000));
}

void SidDataTest :: testGetFileData() {
  unsigned short int len_01, len_03;

  const byte *data_01 = siddata_01->getFileData(len_01);
  const byte expectedData_01 [2] = { 0x00, 0x00 };

  const byte *data_03 = siddata_03->getFileData(len_03);
  const byte expectedData_03 [9] = { 0x00, 0x10, 0x4c, 0x06, 0x10, 0x4c, 0x06, 0x10, 0x60 };

  CPPUNIT_ASSERT(len_01 == 2);
  CPPUNIT_ASSERT(len_03 == 9);

  CPPUNIT_ASSERT(TestUtils::compare(data_01, expectedData_01, len_01) == 0);
  CPPUNIT_ASSERT(TestUtils::compare(data_03, expectedData_03, len_03) == 0);

  delete data_01;
  delete data_03;
}

void SidDataTest :: testGetRawData() {
  unsigned short int len_01, len_03;

  const byte *raw_01 = siddata_01->getRawData(len_01);
  const byte *expectedRaw_01 = NULL;

  const byte *raw_03 = siddata_03->getRawData(len_03);
  const byte expectedRaw_03 [7] = { 0x4c, 0x06, 0x10, 0x4c, 0x06, 0x10, 0x60 };

  CPPUNIT_ASSERT(len_01 == 0);
  CPPUNIT_ASSERT(len_03 == 7);

  CPPUNIT_ASSERT(raw_01 == expectedRaw_01);
  CPPUNIT_ASSERT(TestUtils::compare(raw_03, expectedRaw_03, len_03) == 0);

  delete raw_01;
  delete raw_03;
}

void SidDataTest :: testGetRawDataLength() {
  const unsigned short int len_01 = siddata_01->getRawDataLength();
  const unsigned short int len_03 = siddata_03->getRawDataLength();

  CPPUNIT_ASSERT(len_01 == 0);
  CPPUNIT_ASSERT(len_03 == 7);
}

void SidDataTest :: testEmptyInitialization() {
  unsigned short int length;
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
    "testGetRawDataLength",
    &SidDataTest::testGetRawDataLength
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidDataTest>(
    "testEmptyInitialization",
    &SidDataTest::testEquality
  ));

  return suiteOfTests;
}
