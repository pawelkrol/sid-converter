#ifndef SidFile_h
#define SidFile_h

#include "constants.h"
#include "siddata.h"
#include "sidheader.h"
#include "sidheaderv1.h"
#include "sidheaderv2.h"

class SidFile {

  private:
    char *file;

    SidData *data;
    SidHeader *header;

    friend bool operator==(const SidFile& a, const SidFile& b);
    friend bool operator!=(const SidFile& a, const SidFile& b);

    static const bool compare(const SidFile& a, const SidFile& b);

  public:
    SidFile();
    SidFile(const char *filename);
    SidFile(const byte *siddata, unsigned short int dataSize);
    SidFile(const SidHeader &header, const SidData &data);

    ~SidFile();

    SidFile& operator=(const SidFile& sidFile);

    const char *getFile() const;
    void setFile(const char *filename);

    SidData *getData() const;
    SidHeader *getHeader() const;

    void load();
    void save() const;

    void showDataDump() const;
};

#endif // SidFile_h
