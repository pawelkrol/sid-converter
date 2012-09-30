#include "memaddr.h"

#include <TestCase.h>

class MemoryAddressTest : public CppUnit::TestFixture {

  private:
    MemoryAddress *memaddr_01, *memaddr_02;

  public:
    void setUp();
    void tearDown();

    void testDummy();
};
