#ifndef TestUtils_h
#define TestUtils_h

#include <stdio.h>

#include "constants.h"
#include "sidutils.h"

class TestUtils {

  public:
    static int compare(const byte *a, const byte *b, unsigned int size);
};

#endif // TestUtils_h
