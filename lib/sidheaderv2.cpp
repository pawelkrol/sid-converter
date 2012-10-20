#include "sidheaderv2.h"

bool operator==(const SidHeaderV2 &a, const SidHeaderV2 &b) {
  bool result = true;

  const byte *dataA = a.get();
  const byte *dataB = b.get();

  /*** TODO: refactor bytes array comparison into a separate auxialiary function ***/
  for (int i = 0; i < HEADER_V2_SIZE; i++) {
    byte valueA = *(dataA + i);
    byte valueB = *(dataB + i);

    if (valueA != valueB) {
      result = false;
      break;
    }
  }

  delete dataA;
  delete dataB;

  return result;
}

const byte *SidHeaderV2 :: get() const {
  byte *bytes = new byte[HEADER_V2_SIZE];
  const byte *commonBytes = getCommon();
  memcpy(bytes, commonBytes, HEADER_COMMON_SIZE);
  delete commonBytes;
  /*** TODO: implementation missing! ***/
  /*** TODO: add missing version 2 specific components! ***/
  return bytes;
}

const short int SidHeaderV2 :: size() const {
  return HEADER_V2_SIZE;
}
