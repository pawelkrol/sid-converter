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
  CPPUNIT_ASSERT(!(*sidheader_01 == *sidheader_02));
}

void SidHeaderTest :: testEmptyInitialization() {
  const byte *magicID            = sidheader_01->getMagicID();
  const byte expectedMagicID [4] = { 0x50, 0x53, 0x49, 0x44 };

  CPPUNIT_ASSERT(TestUtils::compare(magicID, expectedMagicID, MAGICID_SIZE) == 0);

  delete magicID;

  /*** TODO: implementation missing! ***/
  /*** TODO: add individual tests for all header fields! ***/

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
    "testEmptyInitialization",
    &SidHeaderTest::testEmptyInitialization
  ));

  return suiteOfTests;
}
