#include "sidheaderv2.h"

bool operator==(const SidHeaderV2 &a, const SidHeaderV2 &b) {
  bool result = SidHeader::compare(a, b);

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
  return !SidHeader::compare(a, b);
}

SidHeaderV2 :: SidHeaderV2(const SidHeaderV2& sidHeader) {
  // TODO: implementation missing...
  throw SidException("Implementation missing!");
}

SidHeaderV2& SidHeaderV2 :: operator=(const SidHeaderV2& sidHeader) {
  // TODO: implementation missing...
  throw SidException("Implementation missing!");
  // TODO: currently assignment doesn't work, this will obviously not work if anything was changed in header
  return *this;
}

SidHeaderV2 :: SidHeaderV2() {
  byte _version [VERSION_SIZE] = { 0x00, 0x02 };
  setVersion(_version);

  flags.setDefaults();

  byte _startPage [START_PAGE_SIZE] = { 0x00 };
  memcpy(startPage, _startPage, START_PAGE_SIZE);

  byte _pageLength [PAGE_LENGTH_SIZE] = { 0x00 };
  memcpy(pageLength, _pageLength, PAGE_LENGTH_SIZE);

  byte _reserved [RESERVED_SIZE] = { 0x00, 0x00 };
  memcpy(reserved, _reserved, RESERVED_SIZE);
}

SidHeaderV2 :: SidHeaderV2(const byte *bytes) {
  initCommon(bytes);

  flags = SidFlags(bytes + FLAGS_OFFSET);

  memcpy(startPage, bytes + START_PAGE_OFFSET, START_PAGE_SIZE);
  memcpy(pageLength, bytes + PAGE_LENGTH_OFFSET, PAGE_LENGTH_SIZE);
  memcpy(reserved, bytes + RESERVED_OFFSET, RESERVED_SIZE);
}

SidHeaderV2 :: ~SidHeaderV2() {
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

void SidHeaderV2 :: validate() const {
  // TODO: implementation missing...
}

void SidHeaderV2 :: showDataDump() const {
  printf("\nSidHeaderV2 :: dataDump");
  printf("\n=======================");
  printf("\n  * object = %p", this);

  showCommonDataDump();

  const byte *_flags = flags.get();
  showValueDump("flags", _flags, FLAGS_SIZE)
  delete _flags;

  showValueDump("startPage", startPage, START_PAGE_SIZE)
  showValueDump("pageLength", pageLength, PAGE_LENGTH_SIZE)
  showValueDump("reserved", reserved, RESERVED_SIZE)

  printf("\n");
}
