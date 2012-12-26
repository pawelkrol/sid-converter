#include "testsidfile.h"

void SidFileTest :: setUp() {
  // TODO: add missing implementation...
}

void SidFileTest :: tearDown() {
  // TODO: add missing implementation...
}

void SidFileTest :: testBuildEmpty() {
  // TODO: add missing implementation...
  CPPUNIT_ASSERT(1 == 0);
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
