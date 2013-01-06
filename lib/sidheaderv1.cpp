#include "sidheaderv1.h"

bool operator==(const SidHeaderV1 &a, const SidHeaderV1 &b) {
  return SidHeader::compare(a, b);
}

bool operator!=(const SidHeaderV1 &a, const SidHeaderV1 &b) {
  return !SidHeader::compare(a, b);
}

SidHeaderV1 :: SidHeaderV1() {
}

SidHeaderV1 :: SidHeaderV1(const byte *bytes) {
  initCommon(bytes);
}

SidHeaderV1 :: ~SidHeaderV1() {
}

SidHeaderV1& SidHeaderV1 :: operator=(const SidHeaderV1& sidHeader) {
  // TODO: implementation missing...
  throw SidException("Implementation missing!");
  // TODO: currently assignment doesn't work, this will obviously not work if anything was changed in header
  return *this;
}

const byte *SidHeaderV1 :: get() const {
  const byte *bytes = getCommon();
  return bytes;
}

const short int SidHeaderV1 :: size() const {
  return HEADER_V1_SIZE;
}

void SidHeaderV1 :: validate() const {
  // TODO: implementation missing...
}

void SidHeaderV1 :: showDataDump() const {
  printf("\nSidHeaderV1 :: dataDump");
  printf("\n=======================");
  printf("\n  * object = %p", this);

  showCommonDataDump();

  printf("\n");
}
