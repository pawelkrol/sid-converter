#ifndef TestMemAddr_h
#define TestMemAddr_h

#include "memaddr.h"

#include <TestCaller.h>
#include <TestCase.h>
#include <TestSuite.h>

class MemoryAddressTest : public CppUnit::TestFixture {

  private:
    MemoryAddress *memaddr_01, *memaddr_02;

  public:
    void setUp();
    void tearDown();

    void testDummy();

    static CppUnit::Test *suite();
};

#endif // TestMemAddr_h
