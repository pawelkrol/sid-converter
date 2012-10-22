#ifndef SidData_h
#define SidData_h

#include "memaddr.h"
#include "sidexception.h"
#include "sidutils.h"

class SidData {

  private:
    MemoryAddress address;
    byte *data;
    short int length;

    friend bool operator==(const SidData& a, const SidData& b);
    friend bool operator!=(const SidData& a, const SidData& b);

    static const bool compare(const SidData& a, const SidData& b);

  public:
    SidData();
    SidData(const byte *data);
    SidData(const byte *raw, const MemoryAddress addr);

    ~SidData();

    const MemoryAddress getAddress() const;

    const byte *getRawData(short int &length) const;
    const byte *getFileData(short int &length) const;
};

#endif // SidData_h
