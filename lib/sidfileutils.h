#ifndef SidFileUtils_h
#define SidFileUtils_h

#include "constants.h"
#include "sidexception.h"

class SidFileUtils {

  public:
    static const bool exists(const char *filename);
    static const byte *read(const char *filename, unsigned int filesize);
    static void write(const char *filename, unsigned int filesize);
};

#endif // SidFileUtils_h
