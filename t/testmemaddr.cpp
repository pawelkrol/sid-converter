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
  CPPUNIT_ASSERT(1 == 0);
}
