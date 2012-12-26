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

void MemoryAddress :: set(const addr &memaddr) {
  lo = byte(memaddr & 0x00ff);
  hi = byte((memaddr & 0xff00) >> 8);
}

MemoryAddress :: MemoryAddress(const byte &memaddr_lo, const byte &memaddr_hi) :
  lo(memaddr_lo),
  hi(memaddr_hi)
{}

MemoryAddress :: MemoryAddress(const addr &memaddr) {
#ifdef DEBUG
  printf("\n*** MemoryAddress::constructor(addr) ***");
  printf("\n  Input parameter as short int = $%04x", memaddr);
#endif

  set(memaddr);
}

MemoryAddress :: MemoryAddress(const MemoryAddress &cAddr) {
  const addr memaddr = cAddr.get();

  set(memaddr);
}

MemoryAddress :: MemoryAddress() :
  lo(0x00),
  hi(0x00)
{}

MemoryAddress& MemoryAddress :: operator=(const addr &memaddr) {
  set(memaddr);

  return *this;
}

const addr MemoryAddress :: get() const {
  addr memaddr = ((hi << 8) + lo) & 0xffff;

#ifdef DEBUG
 printf("\n*** MemoryAddress::memaddr ***");
 printf("\n  Return value as short int = $%04x", memaddr);
#endif

  return memaddr;
}

const byte *MemoryAddress :: getLoHi() const {
  byte *loHi = new byte [2];

  loHi[0] = lo;
  loHi[1] = hi;

  return loHi;
}
