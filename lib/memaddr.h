#ifndef MemAddr_h
#define MemAddr_h

#include <stdio.h>

#include "constants.h"

class MemoryAddress {

  private:

    byte lo;
    byte hi;

    friend bool operator==(const MemoryAddress& a, const MemoryAddress& b);

  public:
    MemoryAddress(byte memaddr_lo, byte memaddr_hi);
    MemoryAddress(addr memaddr);
    MemoryAddress();

    addr memaddr();
};

#endif // MemAddr_h
