#ifndef TestSidHeader_h
#define TestSidHeader_h

#include "constants.h"
#include "sidheaderv2.h"

#include <TestCaller.h>
#include <TestCase.h>
#include <TestSuite.h>

class SidHeaderTest : public CppUnit::TestFixture {

  private:
    SidHeaderV2 *sidheader_01, *sidheader_02;

  public:
    void setUp();
    void tearDown();

    void testEquality();
    void testEmptyInitialization();

    static CppUnit::Test *suite();
};

#endif // TestSidHeader_h
