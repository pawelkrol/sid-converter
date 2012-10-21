#ifndef SidUtils_h
#define SidUtils_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string>

#include "constants.h"

class SidUtils {

  public:
    static const short int hexToInt(const byte *hex);

    static const bool compareData(const byte *dataA, const byte *dataB, const unsigned int size);

    static const char *dumpData(const byte *data, const unsigned int size, const unsigned int bytesPerLine = 8);
};

#endif // SidUtils_h
