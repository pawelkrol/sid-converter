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
  musPlayer(PLAYER_BUILT_IN_MUSIC_PLAYER),
  psidSpecific(PSID_C64_COMPATIBLE),
  clock(CLOCK_PAL),
  sidModel(SID_MOS8580)
{}

const byte SidFlags :: getMusPlayerBits() const {
  switch (getMusPlayer()) {
    case PLAYER_BUILT_IN_MUSIC_PLAYER:
      return 0x00;
    case PLAYER_COMPUTES_SIDPLAYER_MUS_DATA:
      return 0x01;
    case PLAYER_UNINITIALIZED:
      throw SidException("Uninitialized SID header flag: \"musPlayer\" must specify binary data format!");
  }
}

const byte SidFlags :: getPsidSpecificBits() const {
  switch (getPsidSpecific()) {
    case PSID_C64_COMPATIBLE:
      return 0x00;
    case PSID_PLAYSID_SPECIFIC:
      return 0x02;
    case PSID_UNINITIALIZED:
      throw SidException("Uninitialized SID header flag: \"psidSpecific\" must specify PlaySID specific!");
  }
}

const byte SidFlags :: getClockBits() const {
  switch (getClock()) {
    case CLOCK_UNKNOWN:
      return 0x00;
    case CLOCK_PAL:
      return 0x04;
    case CLOCK_NTSC:
      return 0x08;
    case CLOCK_PAL_AND_NTSC:
      return 0x0c;
    case CLOCK_UNINITIALIZED:
      throw SidException("Uninitialized SID header flag: \"clock\" must specify video standard!");
  }
}

const byte SidFlags :: getSidModelBits() const {
  switch (getSidModel()) {
    case SID_UNKNOWN:
      return 0x00;
    case SID_MOS6581:
      return 0x10;
    case SID_MOS8580:
      return 0x20;
    case SID_MOS6581_AND_MOS8580:
      return 0x30;
    case SID_UNINITIALIZED:
      throw SidException("Uninitialized SID header flag: \"sidModel\" must specify SID version!");
  }
}

const byte *SidFlags :: get() const {
  byte *flags = new byte[FLAGS_SIZE];
  flags[0] = 0x00;
  flags[1] = getMusPlayerBits() | getPsidSpecificBits() | getClockBits() | getSidModelBits();
  return flags;
}

const BinaryDataFormat SidFlags :: getMusPlayer() const {
  return musPlayer;
}

const PlaySIDSpecific SidFlags :: getPsidSpecific() const {
  return psidSpecific;
}

const VideoStandard SidFlags :: getClock() const {
  return clock;
}

const SIDVersion SidFlags :: getSidModel() const {
  return sidModel;
}

void SidFlags :: setDefaults() {
  musPlayer    = PLAYER_BUILT_IN_MUSIC_PLAYER;
  psidSpecific = PSID_C64_COMPATIBLE;
  clock        = CLOCK_PAL;
  sidModel     = SID_MOS8580;
}
