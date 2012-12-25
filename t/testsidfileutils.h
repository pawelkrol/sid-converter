#ifndef TestSidFileUtils_h
#define TestSidFileUtils_h

#include "sidfileutils.h"

#include <TestCaller.h>
#include <TestCase.h>
#include <TestSuite.h>

class SidFileUtilsTest : public CppUnit::TestFixture {

  public:
    void setUp();
    void tearDown();

    void testExists();
    void testRead();
    void testWrite();

    static CppUnit::Test *suite();
};

#endif // TestSidFileUtils_h
