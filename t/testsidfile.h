#ifndef TestSidFile_h
#define TestSidFile_h

#include "sidfile.h"
#include "sidheaderv2.h"

#include <TestCaller.h>
#include <TestCase.h>
#include <TestSuite.h>

class SidFileTest : public CppUnit::TestFixture {

  private:
    SidFile *sidfile_01, *sidfile_02;

    const SidData getDefaultData();
    const SidHeaderV2 getDefaultHeader();
    const SidFile getDefaultFile();

    const SidData getEmptyData();
    const SidHeaderV2 getEmptyHeader();
    const SidFile getEmptyFile();

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
