#include "testsidflags.h"

void SidFlagsTest :: setUp() {
  sidflags_01 = new SidFlags();
  sidflags_02 = new SidFlags();
}

void SidFlagsTest :: tearDown() {
  delete sidflags_01;
  delete sidflags_02;
}

void SidFlagsTest :: testEquality() {
  CPPUNIT_ASSERT(*sidflags_01 == *sidflags_02);
  CPPUNIT_ASSERT(!(*sidflags_01 != *sidflags_02));
}

void SidFlagsTest :: testBinaryDataFormatInitialization() {
  const BinaryDataFormatType binaryDataFormat         = sidflags_01->getBinaryDataFormat();
  const BinaryDataFormatType expectedBinaryDataFormat = BUILT_IN_MUSIC_PLAYER;

  CPPUNIT_ASSERT(binaryDataFormat == expectedBinaryDataFormat);
}

void SidFlagsTest :: testPlaySIDSpecificInitialization() {
  const PlaySIDSpecificType playSIDSpecific         = sidflags_01->getPlaySIDSpecific();
  const PlaySIDSpecificType expectedPlaySIDSpecific = C64_COMPATIBLE;

  CPPUNIT_ASSERT(playSIDSpecific == expectedPlaySIDSpecific);
}

void SidFlagsTest :: testEmptyInitialization() {
  const byte *flags                     = sidflags_01->get();
  const byte expectedFlags [FLAGS_SIZE] = { 0x00, 0x24 };

  CPPUNIT_ASSERT(TestUtils::compare(flags, expectedFlags, FLAGS_SIZE) == 0);

  delete flags;
}

CppUnit::Test *SidFlagsTest :: suite() {
  CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("SidFlagsTest");

  suiteOfTests->addTest(new CppUnit::TestCaller<SidFlagsTest>(
    "testEquality",
    &SidFlagsTest::testEquality
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidFlagsTest>(
    "testBinaryDataFormatInitialization",
    &SidFlagsTest::testBinaryDataFormatInitialization
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidFlagsTest>(
    "testPlaySIDSpecificInitialization",
    &SidFlagsTest::testPlaySIDSpecificInitialization
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidFlagsTest>(
    "testEmptyInitialization",
    &SidFlagsTest::testEmptyInitialization
  ));

  return suiteOfTests;
}
