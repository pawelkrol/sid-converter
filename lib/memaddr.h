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
    MemoryAddress(byte memaddr_lo, byte memaddr_hi) :
      lo(memaddr_lo),
      hi(memaddr_hi)
    {}

    MemoryAddress(addr memaddr) {
#ifdef DEBUG
     printf("\n*** MemoryAddress::constructor(addr) ***");
     printf("\n  Input parameter as short int = $%04x", memaddr);
#endif

      lo = byte(memaddr & 0x00ff);
      hi = byte((memaddr & 0xff00) >> 8);
    }

    MemoryAddress() :
      lo(0x00),
      hi(0x00)
    {}

    addr memaddr();
};

#endif // MemAddr_h
