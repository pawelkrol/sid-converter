#include "testsidfileutils.h"

void SidFileUtilsTest :: setUp() {
}

void SidFileUtilsTest :: tearDown() {
}

void SidFileUtilsTest :: testExists() {
  const char *filename = "## TODO ##";
  const bool result = SidFileUtils::exists(filename);
  // TODO: add missing implementation...
  CPPUNIT_ASSERT(1 == 0);
}

void SidFileUtilsTest :: testRead() {
  const char *filename = "## TODO ##";
  unsigned int filesize;
  const byte *data = SidFileUtils::read(filename, filesize);
  // TODO: add missing implementation...
  CPPUNIT_ASSERT(1 == 0);
}

void SidFileUtilsTest :: testWrite() {
  const char *filename = "## TODO ##";
  const unsigned int filesize = 0;
  const byte *data = NULL;
  SidFileUtils::write(filename, filesize, data);
  // TODO: add missing implementation...
  CPPUNIT_ASSERT(1 == 0);
}

CppUnit::Test *SidFileUtilsTest :: suite() {
  CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("SidFileUtilsTest");

  suiteOfTests->addTest(new CppUnit::TestCaller<SidFileUtilsTest>(
    "testExists",
    &SidFileUtilsTest::testExists
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidFileUtilsTest>(
    "testRead",
    &SidFileUtilsTest::testRead
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<SidFileUtilsTest>(
    "testWrite",
    &SidFileUtilsTest::testWrite
  ));

  return suiteOfTests;
}
