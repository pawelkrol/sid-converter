#ifndef TestSidHeader_h
#define TestSidHeader_h

#include <string.h>

#include "constants.h"
#include "sidheaderv2.h"

#include "testutils.h"

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

    void testMagicIDInitialization();
    void testVersionInitialization();
    void testDataOffsetInitialization();
    void testLoadAddressInitialization();
    void testInitAddressInitialization();
    void testPlayAddressInitialization();
    void testSongsInitialization();
    void testStartSongInitialization();
    void testSpeedInitialization();
    void testTitleInitialization();
    void testAuthorInitialization();
    void testCopyrightInitialization();
    void testFlagsInitialization();
    // TODO: add tests for other fields...
    //  * startPage
    //  * pageLength
    //  * reserved

    // TODO: add tests for all set methods...
    // TODO: add tests for exceptions on invalid set values...

    void testEmptyInitialization();

    static CppUnit::Test *suite();
};

#endif // TestSidHeader_h
