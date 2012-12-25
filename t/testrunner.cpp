#include "testmemaddr.h"
#include "testsiddata.h"
#include "testsidflags.h"
#include "testsidheader.h"
#include "testsidstring.h"
#include "testsidfileutils.h"

#include <ui/text/TestRunner.h>

int main(int argc, char **argv) {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(MemoryAddressTest::suite());
  runner.addTest(SidDataTest::suite());
  runner.addTest(SidFlagsTest::suite());
  runner.addTest(SidStringTest::suite());
  runner.addTest(SidHeaderTest::suite());
  runner.addTest(SidFileUtilsTest::suite());
  bool wasSuccessful = runner.run("", false);
  return ! wasSuccessful;
}
