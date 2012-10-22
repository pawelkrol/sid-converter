#ifndef TestSidData_h
#define TestSidData_h

#include "siddata.h"

#include "testutils.h"

#include <TestCaller.h>
#include <TestCase.h>
#include <TestSuite.h>

class SidDataTest : public CppUnit::TestFixture {

  private:
    SidData *siddata_01, *siddata_02;

  public:
    void setUp();
    void tearDown();

    void testEquality();

    void testGetAddress();
    void testGetFileData();
    void testGetRawData();

    void testEmptyInitialization();

    static CppUnit::Test *suite();
};

#endif // TestSidData_h
