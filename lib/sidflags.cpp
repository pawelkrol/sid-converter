#include "sidflags.h"

bool operator==(const SidFlags& a, const SidFlags& b) {
  return SidFlags::compare(a, b);
}

bool operator!=(const SidFlags& a, const SidFlags& b) {
  return !SidFlags::compare(a, b);
}

const bool SidFlags :: compare(const SidFlags& a, const SidFlags& b) {
  const byte *dataA = a.get();
  const byte *dataB = b.get();

  bool result = SidUtils::compareData(dataA, dataB, FLAGS_SIZE);

  delete dataA;
  delete dataB;

  return result;
}

SidFlags :: SidFlags() :
  binaryDataFormat(BUILT_IN_MUSIC_PLAYER),
  playSIDSpecific(C64_COMPATIBLE)
{}

const byte *SidFlags :: get() const {
  /*** TODO: implementation missing! ***/
  /*** WARNING! This is just SidFlags::get stub! ***/
  byte *temp = new byte[2];
  temp[0] = 0x12;
  temp[1] = 0x34;
  return temp;
  /*** TODO: implementation missing! ***/
}

const BinaryDataFormatType SidFlags :: getBinaryDataFormat() const {
  return binaryDataFormat;
}

const PlaySIDSpecificType SidFlags :: getPlaySIDSpecific() const {
  return playSIDSpecific;
}
