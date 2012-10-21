#include "testsidstring.h"

void SidStringTest :: setUp() {
  sidstring_01 = new SidString();
  sidstring_02 = new SidString();
}

void SidStringTest :: tearDown() {
  delete sidstring_01;
  delete sidstring_02;
}

void SidStringTest :: testEquality() {
  CPPUNIT_ASSERT(*sidstring_01 == *sidstring_02);
  CPPUNIT_ASSERT(!(*sidstring_01 != *sidstring_02));
}

void SidStringTest :: testGetLength() {
  const byte length = sidstring_01->getLength();

  CPPUNIT_ASSERT(length == 0x00);
}

void SidStringTest :: testSetString() {
  sidstring_01->setString("SID");
  const char *string = sidstring_01->getString();

  CPPUNIT_ASSERT(strcmp(string, "SID") == 0);

  delete string;
}

void SidStringTest :: testGetBytes() {
  sidstring_01->setString("SID");
  const byte *bytes = sidstring_01->getBytes();
  const byte expectedBytes [SID_STRING_SIZE] = {
    0x53, 0x49, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };

  CPPUNIT_ASSERT(TestUtils::compare(bytes, expectedBytes, SID_STRING_SIZE) == 0);

  delete bytes;
}

void SidStringTest :: testSetTooLongString() {
  sidstring_01->setString("1234567890123456789012345678901234567890");
  const char *string = sidstring_01->getString();

  CPPUNIT_ASSERT(strcmp(string, "1234567890123456789012345678901") == 0);

  delete string;
}

void SidStringTest :: testEmptyInitialization() {
  const char *string = sidstring_01->getString();

  CPPUNIT_ASSERT(strcmp(string, "") == 0);

  delete string;
}

CppUnit::Test *SidStringTest :: suite() {
  CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("SidStringTest");

  suiteOfTests->addTest(new CppUnit::TestCaller<SidStringTest>(
    "testEquality",
    &SidStringTest::testEquality
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidStringTest>(
    "testGetLength",
    &SidStringTest::testGetLength
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidStringTest>(
    "testSetString",
    &SidStringTest::testSetString
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidStringTest>(
    "testGetBytes",
    &SidStringTest::testGetBytes
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidStringTest>(
    "testSetTooLongString",
    &SidStringTest::testSetTooLongString
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidStringTest>(
    "testEmptyInitialization",
    &SidStringTest::testEmptyInitialization
  ));

  return suiteOfTests;
}
