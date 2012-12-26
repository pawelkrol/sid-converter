#ifndef TestFileUtils_h
#define TestFileUtils_h

#include <random>
#include <stdio.h>

#include "constants.h"
#include "sidexception.h"

class TestFileUtils {

  public:
    static const char *createRandomFile(const unsigned int numBytes = 0);
    static const char *createRandomFile(const byte *data, const unsigned int numBytes = 0);
    static void removeRandomFile(const char *fileName);
    static const byte *getFileContents(const char *fileName, unsigned int &numBytes);
    static void showFileContents(const char *fileName, unsigned int bytesPerLine = 16, unsigned int maxBumBytes = 1024);
};

#endif // TestFileUtils_h
