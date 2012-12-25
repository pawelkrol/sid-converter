#ifndef TestUtils_h
#define TestUtils_h

#include <limits.h>
#include <stdio.h>
//#include <unistd.h>

#include "constants.h"
#include "sidutils.h"

class TestUtils {

  public:
    static int compare(const byte *a, const byte *b, unsigned int size);
    static const char *getcwd();
};

#endif // TestUtils_h
