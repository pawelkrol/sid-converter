#include "sidheader.h"

SidHeader :: SidHeader() {
  byte _magicID [MAGICID_SIZE] = { 0x50, 0x53, 0x49, 0x44 };
  memcpy(magicID, _magicID, MAGICID_SIZE);
  /*** TODO: implementation missing! ***/
  /*** TODO: add missing components! ***/
}

const byte *SidHeader :: getCommon() const {
  byte *bytes = new byte[HEADER_COMMON_SIZE];
  memcpy(bytes + 0, magicID, MAGICID_SIZE);
  /*** TODO: implementation missing! ***/
  /*** TODO: add missing components! ***/
  return bytes;
}

const byte *SidHeader :: getMagicID() const {
  byte *_magicID = new byte[MAGICID_SIZE];
  memcpy(_magicID, magicID, MAGICID_SIZE);
  return _magicID;
}
