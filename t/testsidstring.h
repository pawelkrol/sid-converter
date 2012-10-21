#ifndef TestSidString_h
#define TestSidString_h

#include "sidstring.h"

#include <TestCaller.h>
#include <TestCase.h>
#include <TestSuite.h>

class SidStringTest : public CppUnit::TestFixture {

  private:
    SidString *sidstring_01, *sidstring_02;

  public:
    void setUp();
    void tearDown();

    void testEquality();

    void testGetLength();
    void testSetString();

    void testSetTooLongString();

    void testEmptyInitialization();

    static CppUnit::Test *suite();
};

#endif // TestSidString_h
