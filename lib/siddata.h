#ifndef SidData_h
#define SidData_h

#include "memaddr.h"
#include "sidexception.h"
#include "sidutils.h"

class SidData {

  private:
    MemoryAddress address;
    byte *data;
    unsigned short int length;

    friend bool operator==(const SidData& a, const SidData& b);
    friend bool operator!=(const SidData& a, const SidData& b);

    static const bool compare(const SidData& a, const SidData& b);

    void setRawData(const byte *raw, unsigned short int rawSize);

  public:
    SidData();
    SidData(const byte *data, unsigned short int dataSize);
    SidData(const byte *raw, unsigned short int rawSize, const MemoryAddress addr);

    ~SidData();

    const MemoryAddress getAddress() const;
    const unsigned short int getRawDataLength() const;

    const byte *getRawData(unsigned short int &len) const;
    const byte *getFileData(unsigned short int &len) const;

    void showDataDump() const;
};

#endif // SidData_h
