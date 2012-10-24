#ifndef TestSidFileUtils_h
#define TestSidFileUtils_h

#include "sidfile.h"

#include <TestCaller.h>
#include <TestCase.h>
#include <TestSuite.h>

class SidStringTest : public CppUnit::TestFixture {

  public:
    void setUp();
    void tearDown();

    void testBuildEmpty();
    void testBuildFromFile();
    void testBuildFromData();

    void testBuildLoadFile();
    void testBuildSaveFile();

    static CppUnit::Test *suite();
};

#endif // TestSidFileUtils_h
