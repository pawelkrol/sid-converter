#include "memaddr.h"

bool operator==(const MemoryAddress &a, const MemoryAddress &b) { 
  bool result = a.lo == b.lo && a.hi == b.hi;

#ifdef DEBUG
  printf("\n*** MemoryAddress::operator== ***");
  printf("\n  1) a.lo = $%02x / a.hi = $%02x", a.lo, a.hi);
  printf("\n  2) b.lo = $%02x / b.hi = $%02x", b.lo, b.hi);
  printf("\n  Comparison result = %s", bool2str(result));
#endif

  return result;
}

MemoryAddress :: MemoryAddress(byte memaddr_lo, byte memaddr_hi) :
  lo(memaddr_lo),
  hi(memaddr_hi)
{}

MemoryAddress :: MemoryAddress(addr memaddr) {
#ifdef DEBUG
  printf("\n*** MemoryAddress::constructor(addr) ***");
  printf("\n  Input parameter as short int = $%04x", memaddr);
#endif

  lo = byte(memaddr & 0x00ff);
  hi = byte((memaddr & 0xff00) >> 8);
}

MemoryAddress :: MemoryAddress() :
  lo(0x00),
  hi(0x00)
{}

addr MemoryAddress :: memaddr() {
  addr memaddr = (hi << 8 + lo) & 0xffff;

#ifdef DEBUG
 printf("\n*** MemoryAddress::memaddr ***");
 printf("\n  Return value as short int = $%04x", memaddr);
#endif

  return memaddr;
}
