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

SidFlags :: SidFlags(const byte *bytes) {
  byte flags = *(bytes + 1);

  setMusPlayer(flags);
  setPsidSpecific(flags);
  setClock(flags);
  setSidModel(flags);
}

void SidFlags :: setMusPlayer(const byte bits) {
  BinaryDataFormat format = getMusPlayer(bits);
  setMusPlayer(format);
}

void SidFlags :: setPsidSpecific(const byte bits) {
  PlaySIDSpecific specific = getPsidSpecific(bits);
  setPsidSpecific(specific);
}

void SidFlags :: setClock(const byte bits) {
  VideoStandard standard = getClock(bits);
  setClock(standard);
}

void SidFlags :: setSidModel(const byte bits) {
  SIDVersion version = getSidModel(bits);
  setSidModel(version);
}

const BinaryDataFormat SidFlags :: getMusPlayer(const byte bits) const {
  switch (bits & 0x01) {
    case 0x00:
      return PLAYER_BUILT_IN_MUSIC_PLAYER;
    case 0x01:
      return PLAYER_COMPUTES_SIDPLAYER_MUS_DATA;
    default:
      return PLAYER_UNINITIALIZED;
  }
}

const PlaySIDSpecific SidFlags :: getPsidSpecific(const byte bits) const {
  switch (bits & 0x02) {
    case 0x00:
      return PSID_C64_COMPATIBLE;
    case 0x02:
      return PSID_PLAYSID_SPECIFIC;
    default:
      return PSID_UNINITIALIZED;
  }
}

const VideoStandard SidFlags :: getClock(const byte bits) const {
  switch (bits & 0x0c) {
    case 0x00:
      return CLOCK_UNKNOWN;
    case 0x04:
      return CLOCK_PAL;
    case 0x08:
      return CLOCK_NTSC;
    case 0x0c:
      return CLOCK_PAL_AND_NTSC;
    default:
      return CLOCK_UNINITIALIZED;
  }
}

const SIDVersion SidFlags :: getSidModel(const byte bits) const {
  switch (bits & 0x30) {
    case 0x00:
      return SID_UNKNOWN;
    case 0x10:
      return SID_MOS6581;
    case 0x20:
      return SID_MOS8580;
    case 0x30:
      return SID_MOS6581_AND_MOS8580;
    default:
      return SID_UNINITIALIZED;
  }
}

const byte SidFlags :: getMusPlayerBits() const {
  switch (getMusPlayer()) {
    case PLAYER_BUILT_IN_MUSIC_PLAYER:
      return 0x00;
    case PLAYER_COMPUTES_SIDPLAYER_MUS_DATA:
      return 0x01;
    default:
      throw SidException("Uninitialized SID header flag: \"musPlayer\" must specify binary data format!");
  }
}

const byte SidFlags :: getPsidSpecificBits() const {
  switch (getPsidSpecific()) {
    case PSID_C64_COMPATIBLE:
      return 0x00;
    case PSID_PLAYSID_SPECIFIC:
      return 0x02;
    default:
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
    default:
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
    default:
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

void SidFlags :: setMusPlayer(BinaryDataFormat format) {
  musPlayer = format;
}

const PlaySIDSpecific SidFlags :: getPsidSpecific() const {
  return psidSpecific;
}

void SidFlags :: setPsidSpecific(PlaySIDSpecific specific) {
  psidSpecific = specific;
}

const VideoStandard SidFlags :: getClock() const {
  return clock;
}

void SidFlags :: setClock(VideoStandard standard) {
  clock = standard;
}

const SIDVersion SidFlags :: getSidModel() const {
  return sidModel;
}

void SidFlags :: setSidModel(SIDVersion version) {
  sidModel = version;
}

void SidFlags :: setDefaults() {
  musPlayer    = PLAYER_BUILT_IN_MUSIC_PLAYER;
  psidSpecific = PSID_C64_COMPATIBLE;
  clock        = CLOCK_PAL;
  sidModel     = SID_MOS8580;
}
