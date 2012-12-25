#include "testsidfileutils.h"

void SidFileUtilsTest :: setUp() {
}

void SidFileUtilsTest :: tearDown() {
}

void SidFileUtilsTest :: testExists() {
  const char *filename = TestFileUtils::createRandomFile();
  const bool result = SidFileUtils::exists(filename);
  TestFileUtils::removeRandomFile(filename);
  CPPUNIT_ASSERT(result);
}

void SidFileUtilsTest :: testRead() {
  const int numBytes = 9;
  const byte expectedData [numBytes] = { 0x00, 0x10, 0x4c, 0x06, 0x10, 0x4c, 0x06, 0x10, 0x60 };
  const char *filename = TestFileUtils::createRandomFile(expectedData, numBytes);
  unsigned long int filesize;
  const byte *data = SidFileUtils::read(filename, filesize);
  TestFileUtils::removeRandomFile(filename);
  CPPUNIT_ASSERT(filesize == numBytes);
  CPPUNIT_ASSERT(TestUtils::compare(data, expectedData, numBytes) == 0);
  delete data;
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
