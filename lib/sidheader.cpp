#include "sidheader.h"

SidHeader :: SidHeader() {
  byte _magicID [MAGICID_SIZE] = { 0x50, 0x53, 0x49, 0x44 };
  memcpy(magicID, _magicID, MAGICID_SIZE);

  byte _version [VERSION_SIZE] = { 0x00, 0x02 };
  memcpy(version, _version, VERSION_SIZE);

  byte _dataOffset [DATA_OFFSET_SIZE] = { 0x00, 0x7c };
  memcpy(dataOffset, _dataOffset, DATA_OFFSET_SIZE);

  byte _loadAddress [LOAD_ADDRESS_SIZE] = { 0x00, 0x00 };
  memcpy(loadAddress, _loadAddress, LOAD_ADDRESS_SIZE);

  byte _initAddress [INIT_ADDRESS_SIZE] = { 0x10, 0x00 };
  memcpy(initAddress, _initAddress, INIT_ADDRESS_SIZE);

  byte _playAddress [PLAY_ADDRESS_SIZE] = { 0x10, 0x03 };
  memcpy(playAddress, _playAddress, PLAY_ADDRESS_SIZE);

  byte _songs [SONGS_SIZE] = { 0x00, 0x01 };
  memcpy(songs, _songs, SONGS_SIZE);

  byte _startSong [START_SONG_SIZE] = { 0x00, 0x01 };
  memcpy(startSong, _startSong, START_SONG_SIZE);

  byte _speed [SPEED_SIZE] = { 0x00, 0x00, 0x00, 0x00 };
  memcpy(speed, _speed, SPEED_SIZE);

  title.empty();
  author.empty();
  copyright.empty();
}

const byte *SidHeader :: getCommon() const {
  byte *bytes = new byte[HEADER_COMMON_SIZE];
  memcpy(bytes + MAGICID_OFFSET, magicID, MAGICID_SIZE);
  memcpy(bytes + VERSION_OFFSET, version, VERSION_SIZE);
  memcpy(bytes + DATA_OFFSET_OFFSET, dataOffset, DATA_OFFSET_SIZE);
  memcpy(bytes + LOAD_ADDRESS_OFFSET, loadAddress, LOAD_ADDRESS_SIZE);
  memcpy(bytes + INIT_ADDRESS_OFFSET, initAddress, INIT_ADDRESS_SIZE);
  memcpy(bytes + PLAY_ADDRESS_OFFSET, playAddress, PLAY_ADDRESS_SIZE);
  memcpy(bytes + SONGS_OFFSET, songs, SONGS_SIZE);
  memcpy(bytes + START_SONG_OFFSET, startSong, START_SONG_SIZE);
  memcpy(bytes + SPEED_OFFSET, speed, SPEED_SIZE);
  /*** TODO: implementation missing! ***/
  /*** TODO: add missing components! ***/
  return bytes;
}

const byte *SidHeader :: getMagicID() const {
  byte *_magicID = new byte[MAGICID_SIZE];
  memcpy(_magicID, magicID, MAGICID_SIZE);
  return _magicID;
}

const byte *SidHeader :: getVersion() const {
  getSidHeaderValue(version, VERSION_SIZE)
}

const short int SidHeader :: getVersionNum() const {
  getSidHeaderNumValue(getVersion)
}

const byte *SidHeader :: getDataOffset() const {
  getSidHeaderValue(dataOffset, DATA_OFFSET_SIZE)
}

const short int SidHeader :: getDataOffsetNum() const {
  getSidHeaderNumValue(getDataOffset)
}

const byte *SidHeader :: getLoadAddress() const {
  getSidHeaderValue(loadAddress, LOAD_ADDRESS_SIZE)
}

const short int SidHeader :: getLoadAddressNum() const {
  getSidHeaderNumValue(getLoadAddress)
}

const byte *SidHeader :: getInitAddress() const {
  getSidHeaderValue(initAddress, INIT_ADDRESS_SIZE)
}

const short int SidHeader :: getInitAddressNum() const {
  getSidHeaderNumValue(getInitAddress)
}

const byte *SidHeader :: getPlayAddress() const {
  getSidHeaderValue(playAddress, PLAY_ADDRESS_SIZE)
}

const short int SidHeader :: getPlayAddressNum() const {
  getSidHeaderNumValue(getPlayAddress)
}

const byte *SidHeader :: getSongs() const {
  getSidHeaderValue(songs, SONGS_SIZE)
}

const short int SidHeader :: getSongsNum() const {
  getSidHeaderNumValue(getSongs)
}

const byte *SidHeader :: getStartSong() const {
  getSidHeaderValue(startSong, START_SONG_SIZE)
}

const short int SidHeader :: getStartSongNum() const {
  getSidHeaderNumValue(getStartSong)
}

const byte *SidHeader :: getSpeed() const {
  byte *_speed = new byte[SPEED_SIZE];
  memcpy(_speed, speed, SPEED_SIZE);
  return _speed;
}

const char *SidHeader :: dataDump() const {
  const byte *dataBytes       = get();
  const unsigned int dataSize = size();

  const char *dump = SidUtils::dumpData(dataBytes, dataSize);

  delete dataBytes;

  return dump;
}
