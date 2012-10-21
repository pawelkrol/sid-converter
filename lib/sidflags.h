#ifndef SidFlags_h
#define SidFlags_h

#include "constants.h"
#include "sidutils.h"

#define FLAGS_SIZE 0x02

enum BinaryDataFormatType {
  UNINITIALIZED_BINARY_DATA_FORMAT,
  BUILT_IN_MUSIC_PLAYER,
  COMPUTES_SIDPLAYER_MUS_DATA
};

enum PlaySIDSpecificType {
  UNINITIALIZED_PLAY_SID_SPECIFIC,
  C64_COMPATIBLE,
  PLAYSID_SPECIFIC
};

class SidFlags {

  private:
    BinaryDataFormatType binaryDataFormat;
    PlaySIDSpecificType playSIDSpecific;

    friend bool operator==(const SidFlags& a, const SidFlags& b);
    friend bool operator!=(const SidFlags& a, const SidFlags& b);

    static const bool compare(const SidFlags& a, const SidFlags& b);

  public:
    SidFlags();

    const byte *get() const;

    const BinaryDataFormatType getBinaryDataFormat() const;
    void setBinaryDataFormat(BinaryDataFormatType fmt);

    const PlaySIDSpecificType getPlaySIDSpecific() const;
    void setPlaySIDSpecific(PlaySIDSpecificType spec);

    void validate() const;
};

#endif // SidFlags_h
