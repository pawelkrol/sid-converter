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

addr MemoryAddress :: memaddr() {
  addr memaddr = (hi << 8 + lo) & 0xffff;

#ifdef DEBUG
 printf("\n*** MemoryAddress::memaddr ***");
 printf("\n  Return value as short int = $%04x", memaddr);
#endif

  return memaddr;
}
