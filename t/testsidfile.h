#ifndef TestSidFile_h
#define TestSidFile_h

#include "sidfile.h"

#include <TestCaller.h>
#include <TestCase.h>
#include <TestSuite.h>

class SidFileTest : public CppUnit::TestFixture {

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

#endif // TestSidFile_h
