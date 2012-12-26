#include "sidheader.h"

const bool SidHeader :: compare(const SidHeader& a, const SidHeader& b) {
  const byte *dataA = a.get();
  const byte *dataB = b.get();

  const short int headerSize = a.size();

  bool result = SidUtils::compareData(dataA, dataB, headerSize);

  delete dataA;
  delete dataB;

  return result;
}

SidHeader :: SidHeader() {
  byte _magicID [MAGICID_SIZE] = { 0x50, 0x53, 0x49, 0x44 };
  memcpy(magicID, _magicID, MAGICID_SIZE);

  byte _version [VERSION_SIZE] = { 0x00, 0x01 };
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

  const byte *titleBytes = title.getBytes();
  memcpy(bytes + TITLE_OFFSET, titleBytes, TITLE_SIZE);
  delete titleBytes;

  const byte *authorBytes = author.getBytes();
  memcpy(bytes + AUTHOR_OFFSET, authorBytes, AUTHOR_SIZE);
  delete authorBytes;

  const byte *copyrightBytes = copyright.getBytes();
  memcpy(bytes + COPYRIGHT_OFFSET, copyrightBytes, COPYRIGHT_SIZE);
  delete copyrightBytes;

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

void SidHeader :: setVersion(const byte version [VERSION_SIZE]) {
  memcpy(this->version, version, VERSION_SIZE);
}

void SidHeader :: setVersionNum(const short int version) {
  SidUtils::intToHex(version, this->version, VERSION_SIZE);
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
  getSidHeaderValue(speed, SPEED_SIZE)
}

const byte *SidHeader :: getTitle() const {
  return title.getBytes();
}

const char *SidHeader :: getTitleString() const {
  return title.getString();
}

const byte *SidHeader :: getAuthor() const {
  return author.getBytes();
}

const char *SidHeader :: getAuthorString() const {
  return author.getString();
}

const byte *SidHeader :: getCopyright() const {
  return copyright.getBytes();
}

const char *SidHeader :: getCopyrightString() const {
  return copyright.getString();
}

const char *SidHeader :: dataDump() const {
  const byte *dataBytes       = get();
  const unsigned int dataSize = size();

  const char *dump = SidUtils::dumpData(dataBytes, dataSize);

  delete dataBytes;

  return dump;
}

void SidHeader :: showCommonDataDump() const {
  showValueDump("magicID", magicID, MAGICID_SIZE)
  showValueDump("version", version, VERSION_SIZE)
  showValueDump("dataOffset", dataOffset, DATA_OFFSET_SIZE)
  showValueDump("loadAddress", loadAddress, LOAD_ADDRESS_SIZE)
  showValueDump("initAddress", initAddress, INIT_ADDRESS_SIZE)
  showValueDump("playAddress", playAddress, PLAY_ADDRESS_SIZE)
  showValueDump("songs", songs, SONGS_SIZE)
  showValueDump("startSong", startSong, START_SONG_SIZE)
  showValueDump("speed", speed, SPEED_SIZE)

  showSidStringDump("title", title)
  showSidStringDump("author", author)
  showSidStringDump("copyright", copyright)
}
