#ifndef SidFlags_h
#define SidFlags_h

#include "constants.h"
#include "sidexception.h"
#include "sidutils.h"

#define FLAGS_SIZE 0x02

enum BinaryDataFormat {
  PLAYER_UNINITIALIZED,
  PLAYER_BUILT_IN_MUSIC_PLAYER,
  PLAYER_COMPUTES_SIDPLAYER_MUS_DATA
};

enum PlaySIDSpecific {
  PSID_UNINITIALIZED,
  PSID_C64_COMPATIBLE,
  PSID_PLAYSID_SPECIFIC
};

enum VideoStandard {
  CLOCK_UNINITIALIZED,
  CLOCK_UNKNOWN,
  CLOCK_PAL,
  CLOCK_NTSC,
  CLOCK_PAL_AND_NTSC
};

enum SIDVersion {
  SID_UNINITIALIZED,
  SID_UNKNOWN,
  SID_MOS6581,
  SID_MOS8580,
  SID_MOS6581_AND_MOS8580
};

class SidFlags {

  private:
    BinaryDataFormat musPlayer;
    PlaySIDSpecific psidSpecific;
    VideoStandard clock;
    SIDVersion sidModel;

    const byte getMusPlayerBits() const;
    const byte getPsidSpecificBits() const;
    const byte getClockBits() const;
    const byte getSidModelBits() const;

    friend bool operator==(const SidFlags& a, const SidFlags& b);
    friend bool operator!=(const SidFlags& a, const SidFlags& b);

    static const bool compare(const SidFlags& a, const SidFlags& b);

  public:
    SidFlags();

    const byte *get() const;

    const BinaryDataFormat getMusPlayer() const;
    void setMusPlayer(BinaryDataFormat format);

    const PlaySIDSpecific getPsidSpecific() const;
    void setPsidSpecific(PlaySIDSpecific specific);

    const VideoStandard getClock() const;
    void setClock(VideoStandard standard);

    const SIDVersion getSidModel() const;
    void setSidModel(SIDVersion version);

    void setDefaults();

    void validate() const;
};

#endif // SidFlags_h
