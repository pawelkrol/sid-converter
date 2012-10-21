#ifndef SidHeader_h
#define SidHeader_h

#include <string.h>

#include "memaddr.h"
#include "sidstring.h"
#include "sidutils.h"

#define HEADER_COMMON_SIZE 0x76

#define MAGICID_OFFSET 0x00
#define VERSION_OFFSET 0x04
#define DATA_OFFSET_OFFSET 0x06
#define LOAD_ADDRESS_OFFSET 0x08
#define INIT_ADDRESS_OFFSET 0x0a
#define PLAY_ADDRESS_OFFSET 0x0c
#define SONGS_OFFSET 0x0e
#define START_SONG_OFFSET 0x10
#define SPEED_OFFSET 0x12
#define TITLE_OFFSET 0x16
#define AUTHOR_OFFSET 0x36
#define COPYRIGHT_OFFSET 0x56

#define MAGICID_SIZE 0x04
#define VERSION_SIZE 0x02
#define DATA_OFFSET_SIZE 0x02
#define LOAD_ADDRESS_SIZE 0x02
#define INIT_ADDRESS_SIZE 0x02
#define PLAY_ADDRESS_SIZE 0x02
#define SONGS_SIZE 0x02
#define START_SONG_SIZE 0x02
#define SPEED_SIZE 0x04
#define TITLE_SIZE 0x20
#define AUTHOR_SIZE 0x20
#define COPYRIGHT_SIZE 0x20

class SidHeader {

  protected:
    byte magicID [MAGICID_SIZE]; // offset: 0x00
    byte version [VERSION_SIZE]; // offset: 0x04
    byte dataOffset [DATA_OFFSET_SIZE]; // offset: 0x06
    byte loadAddress [LOAD_ADDRESS_SIZE]; // offset: 0x08
    byte initAddress [INIT_ADDRESS_SIZE]; // offset: 0x0a
    byte playAddress [PLAY_ADDRESS_SIZE]; // offset: 0x0c
    byte songs [SONGS_SIZE]; // offset: 0x0e
    byte startSong [START_SONG_SIZE]; // offset: 0x10
    byte speed [SPEED_SIZE]; // offset: 0x12
    SidString title; // offset: 0x16
    SidString author; // offset: 0x36
    SidString copyright; // offset: 0x56

    /*** TODO: implementation missing! ***/
    // Use dedicated classes to store memory address data:
    // MemoryAddress initAddr;
    // MemoryAddress playAddr;

  public:
    SidHeader();

    virtual const byte *get() const {};
    const byte *getCommon() const;

    const byte *getMagicID() const;

    const byte *getVersion() const;
    const short int getVersionNum() const;

    const byte *getDataOffset() const;
    const short int getDataOffsetNum() const;

    const byte *getLoadAddress() const;
    const short int getLoadAddressNum() const;

    const byte *getInitAddress() const;
    const short int getInitAddressNum() const;

    const byte *getPlayAddress() const;
    const short int getPlayAddressNum() const;

    const byte *getSongs() const;
    const short int getSongsNum() const;

    const byte *getStartSong() const;
    const short int getStartSongNum() const;

    const byte *getSpeed() const;

    const byte *getTitle() const;
    const char *getTitleString() const;

    const byte *getAuthor() const;
    const char *getAuthorString() const;

    const byte *getCopyright() const;
    const char *getCopyrightString() const;

    const char *dataDump() const;

    virtual const short int size() const {};

    virtual void validate() const {};
};

#endif // SidHeader_h
