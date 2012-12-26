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
    static void intToHex(short int integer, byte *hex, unsigned int numBytes);

    static const bool compareData(const byte *dataA, const byte *dataB, const unsigned int size);

    static const char *dumpData(const byte *data, const unsigned int size, const unsigned int bytesPerLine = 8);

    static const addr twoBytesToAddr(const byte *loHi);
    static const byte* addrToTwoBytes(const addr& memaddr);
};

#endif // SidUtils_h
