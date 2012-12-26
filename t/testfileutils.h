#ifndef TestFileUtils_h
#define TestFileUtils_h

#include <cstring>
#include <random>
#include <stdio.h>

#include "constants.h"
#include "siddata.h"
#include "sidexception.h"
#include "sidheaderv2.h"

class TestFileUtils {

  public:
    static const char *createRandomFile(const unsigned int numBytes = 0);
    static const char *createRandomFile(const byte *data, const unsigned int numBytes = 0);
    static const char *createEmptySidFile(unsigned int &numBytes);
    static const char *createRandomSidFile(unsigned int &numBytes);
    static void removeRandomFile(const char *fileName);
    static const byte *getFileContents(const char *fileName, unsigned int &numBytes);
    static void showFileContents(const char *fileName, unsigned int bytesPerLine = 16, unsigned int maxBumBytes = 1024);
};

#endif // TestFileUtils_h
