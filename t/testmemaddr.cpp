#include "testmemaddr.h"

void MemoryAddressTest :: setUp() {
  memaddr_01 = new MemoryAddress();
  memaddr_02 = new MemoryAddress();
}

void MemoryAddressTest :: tearDown() {
  delete memaddr_01;
  delete memaddr_02;
}

void MemoryAddressTest :: testDummy() {
  CPPUNIT_ASSERT(1 == 1);
}

CppUnit::Test *MemoryAddressTest :: suite() {
  CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("MemoryAddressTest");

  suiteOfTests->addTest(new CppUnit::TestCaller<MemoryAddressTest>(
    "testDummy",
    &MemoryAddressTest::testDummy
  ));

  return suiteOfTests;
}
