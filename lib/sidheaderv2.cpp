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

  flags.setDefaults();

  byte _startPage [START_PAGE_SIZE] = { 0x00 };
  memcpy(startPage, _startPage, START_PAGE_SIZE);

  byte _pageLength [PAGE_LENGTH_SIZE] = { 0x00 };
  memcpy(pageLength, _pageLength, PAGE_LENGTH_SIZE);

  byte _reserved [RESERVED_SIZE] = { 0x00, 0x00 };
  memcpy(reserved, _reserved, RESERVED_SIZE);
}

const byte *SidHeaderV2 :: get() const {
  byte *bytes = new byte[HEADER_V2_SIZE];

  const byte *commonBytes = getCommon();
  memcpy(bytes, commonBytes, HEADER_COMMON_SIZE);
  delete commonBytes;

  const byte *flagsBytes = getFlags();
  memcpy(bytes + FLAGS_OFFSET, flagsBytes, FLAGS_SIZE);
  delete flagsBytes;

  memcpy(bytes + START_PAGE_OFFSET, startPage, START_PAGE_SIZE);
  memcpy(bytes + PAGE_LENGTH_OFFSET, pageLength, PAGE_LENGTH_SIZE);
  memcpy(bytes + RESERVED_OFFSET, reserved, RESERVED_SIZE);

  return bytes;
}

const byte *SidHeaderV2 :: getFlags() const {
  const byte *flagsBytes = flags.get();
  return flagsBytes;
}

const byte *SidHeaderV2 :: getStartPage() const {
  getSidHeaderValue(startPage, START_PAGE_SIZE)
}

const short int SidHeaderV2 :: getStartPageNum() const {
  getSidHeaderNumValue_1byte(getStartPage)
}

const byte *SidHeaderV2 :: getPageLength() const {
  getSidHeaderValue(pageLength, PAGE_LENGTH_SIZE)
}

const short int SidHeaderV2 :: getPageLengthNum() const {
  getSidHeaderNumValue_1byte(getPageLength)
}

const byte *SidHeaderV2 :: getReserved() const {
  getSidHeaderValue(reserved, RESERVED_SIZE)
}

const short int SidHeaderV2 :: getReservedNum() const {
  getSidHeaderNumValue(getReserved)
}

const short int SidHeaderV2 :: size() const {
  return HEADER_V2_SIZE;
}
