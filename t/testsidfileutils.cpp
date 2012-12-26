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
  // TODO: add missing implementation...
  const char *filename = tmpnam(NULL);
  const unsigned int numBytes = 9;
  const byte expectedData [numBytes] = { 0x00, 0x10, 0x4c, 0x06, 0x10, 0x4c, 0x06, 0x10, 0x60 };
  SidFileUtils::write(filename, numBytes, expectedData);
  // get file contents using TestFileUtils::getFileContents (implement it first!)
  unsigned int filesize;
  const byte *data = TestFileUtils::getFileContents(filename, filesize);
  // compare fetched data with the original test file data and their sizes (assert...)
  CPPUNIT_ASSERT(filesize == numBytes);
  CPPUNIT_ASSERT(TestUtils::compare(data, expectedData, numBytes) == 0);
  delete data;
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
