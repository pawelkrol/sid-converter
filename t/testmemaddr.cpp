#include "testmemaddr.h"

void MemoryAddressTest :: setUp() {
  memaddr_0000_01 = new MemoryAddress();
  memaddr_0000_02 = new MemoryAddress();
  memaddr_1000_01 = new MemoryAddress(0x00, 0x10);
  memaddr_1000_02 = new MemoryAddress(0x1000);
}

void MemoryAddressTest :: tearDown() {
  delete memaddr_0000_01;
  delete memaddr_0000_02;
  delete memaddr_1000_01;
  delete memaddr_1000_02;
}

void MemoryAddressTest :: testEquality() {
  CPPUNIT_ASSERT(*memaddr_0000_01 == *memaddr_0000_02);
  CPPUNIT_ASSERT(!(*memaddr_0000_01 == *memaddr_1000_01));
}

void MemoryAddressTest :: testAddressValue() {
  addr memaddr = 0x1000;

  CPPUNIT_ASSERT(memaddr_1000_01->get() == memaddr);
  CPPUNIT_ASSERT(memaddr_1000_02->get() == memaddr);
}

CppUnit::Test *MemoryAddressTest :: suite() {
  CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("MemoryAddressTest");

  suiteOfTests->addTest(new CppUnit::TestCaller<MemoryAddressTest>(
    "testEquality",
    &MemoryAddressTest::testEquality
  ));

  suiteOfTests->addTest(new CppUnit::TestCaller<MemoryAddressTest>(
    "testAddressValue",
    &MemoryAddressTest::testAddressValue
  ));

  return suiteOfTests;
}
