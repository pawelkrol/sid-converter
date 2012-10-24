#ifndef SidFile_h
#define SidFile_h

#include "constants.h"
#include "siddata.h"
#include "sidheader.h"

class SidFile {

  private:
    char *file;

    SidData *data;
    SidHeader *header;

  public:
    SidFile();
    SidFile(const char *filename);
    SidFile(const byte *siddata, unsigned short int dataSize);

    ~SidFile();

    void load();
    void save() const;
};

#endif // SidFile_h
