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
  const BinaryDataFormat musPlayer         = sidflags_01->getMusPlayer();
  const BinaryDataFormat expectedMusPlayer = PLAYER_BUILT_IN_MUSIC_PLAYER;

  CPPUNIT_ASSERT(musPlayer == expectedMusPlayer);
}

void SidFlagsTest :: testPlaySIDSpecificInitialization() {
  const PlaySIDSpecific psidSpecific         = sidflags_01->getPsidSpecific();
  const PlaySIDSpecific expectedPsidSpecific = PSID_C64_COMPATIBLE;

  CPPUNIT_ASSERT(psidSpecific == expectedPsidSpecific);
}

void SidFlagsTest :: testVideoStandardInitialization() {
  const VideoStandard clock         = sidflags_01->getClock();
  const VideoStandard expectedClock = CLOCK_PAL;

  CPPUNIT_ASSERT(clock == expectedClock);
}

void SidFlagsTest :: testSIDVersionInitialization() {
  const SIDVersion sidModel         = sidflags_01->getSidModel();
  const SIDVersion expectedSidModel = SID_MOS8580;

  CPPUNIT_ASSERT(sidModel == expectedSidModel);
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
    "testVideoStandardInitialization",
    &SidFlagsTest::testVideoStandardInitialization
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidFlagsTest>(
    "testSIDVersionInitialization",
    &SidFlagsTest::testSIDVersionInitialization
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidFlagsTest>(
    "testEmptyInitialization",
    &SidFlagsTest::testEmptyInitialization
  ));

  return suiteOfTests;
}
