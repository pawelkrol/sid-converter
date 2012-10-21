#include "sidheaderv2.h"

bool operator==(const SidHeaderV2 &a, const SidHeaderV2 &b) {
  bool result = SidHeaderV2::compare(a, b);

#ifdef DEBUG
  const char *aDump = a.dataDump();
  const char *bDump = b.dataDump();

  printf("\n*** SidHeaderV2::operator== ***");
  printf("\n  1) a.dataDump\n%s\n", aDump);
  printf("\n  2) b.dataDump\n%s\n", bDump);
  printf("\n  Comparison result = %s", bool2str(result));

  delete aDump;
  delete bDump;
#endif

  return result;
}

bool operator!=(const SidHeaderV2 &a, const SidHeaderV2 &b) {
  return !SidHeaderV2::compare(a, b);
}

const bool SidHeaderV2 :: compare(const SidHeaderV2& a, const SidHeaderV2& b) {
  const byte *dataA = a.get();
  const byte *dataB = b.get();

  bool result = SidUtils::compareData(dataA, dataB, HEADER_V2_SIZE);

  delete dataA;
  delete dataB;

  return result;
}

SidHeaderV2 :: SidHeaderV2() {
  byte _version [VERSION_SIZE] = { 0x00, 0x02 };
  memcpy(version, _version, VERSION_SIZE);
}

const byte *SidHeaderV2 :: get() const {
  byte *bytes = new byte[HEADER_V2_SIZE];
  const byte *commonBytes = getCommon();
  memcpy(bytes, commonBytes, HEADER_COMMON_SIZE);
  delete commonBytes;
  memcpy(bytes + START_PAGE_OFFSET, startPage, START_PAGE_SIZE);
  memcpy(bytes + PAGE_LENGTH_OFFSET, pageLength, PAGE_LENGTH_SIZE);
  memcpy(bytes + RESERVED_OFFSET, reserved, RESERVED_SIZE);
  /*** TODO: implementation missing! ***/
bytes[HEADER_COMMON_SIZE] = 0xff;
bytes[HEADER_COMMON_SIZE + 1] = 0xee;
  /*** TODO: add missing version 2 specific components! ***/
  /*** TODO: implementation missing! ***/
  return bytes;
}

const short int SidHeaderV2 :: size() const {
  return HEADER_V2_SIZE;
}
