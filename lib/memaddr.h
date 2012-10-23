#ifndef MemAddr_h
#define MemAddr_h

#include <stdio.h>

#include "constants.h"

class MemoryAddress {

  private:

    byte lo;
    byte hi;

    friend bool operator==(const MemoryAddress& a, const MemoryAddress& b);

    void set(const addr &memaddr);

  public:
    MemoryAddress(const byte &memaddr_lo, const byte &memaddr_hi);
    MemoryAddress(const addr &memaddr);
    MemoryAddress(const MemoryAddress &memaddr);
    MemoryAddress();

    MemoryAddress& operator=(const addr &memaddr);

    const addr get() const;
    const byte *getLoHi() const;
};

#endif // MemAddr_h
