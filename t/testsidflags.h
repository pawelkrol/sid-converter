#ifndef TestSidFlags_h
#define TestSidFlags_h

#include "sidflags.h"

#include "constants.h"
#include "sidheaderv2.h"

#include "testutils.h"

#include <TestCaller.h>
#include <TestCase.h>
#include <TestSuite.h>

class SidFlagsTest : public CppUnit::TestFixture {

  private:
    SidFlags *sidflags_01, *sidflags_02;

  public:
    void setUp();
    void tearDown();

    void testEquality();

    void testBinaryDataFormatInitialization();
    void testPlaySIDSpecificInitialization();
    void testVideoStandardInitialization();
    void testSIDVersionInitialization();

    // TODO: add tests for all set methods...
    // TODO: add tests for exceptions on invalid set values...

    void testEmptyInitialization();

    static CppUnit::Test *suite();
};

#endif // TestSidFlags_h
