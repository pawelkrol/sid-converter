#ifndef TestMemAddr_h
#define TestMemAddr_h

#include "memaddr.h"

#include <TestCaller.h>
#include <TestCase.h>
#include <TestSuite.h>

class MemoryAddressTest : public CppUnit::TestFixture {

  private:
    MemoryAddress *memaddr_0000_01, *memaddr_0000_02;
    MemoryAddress *memaddr_1000_01, *memaddr_1000_02;

  public:
    void setUp();
    void tearDown();

    void testEquality();
    void testAddressValue();

    static CppUnit::Test *suite();
};

#endif // TestMemAddr_h
