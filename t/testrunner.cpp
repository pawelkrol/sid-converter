#include "testmemaddr.h"
#include "testsidheader.h"

#include <ui/text/TestRunner.h>

int main(int argc, char **argv) {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(MemoryAddressTest::suite());
  runner.addTest(SidHeaderTest::suite());
  bool wasSuccessful = runner.run("", false);
  return ! wasSuccessful;
}
