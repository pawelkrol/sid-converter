#ifndef SidHeader_h
#define SidHeader_h

#include <string.h>

#include "memaddr.h"

#define HEADER_COMMON_SIZE 0x76

#define MAGICID_SIZE 0x04

class SidHeader {

  private:
    byte magicID [MAGICID_SIZE];

    byte version [2];

    /*** TODO: implementation missing! ***/
    /*** TODO: add missing properties! ***/

    MemoryAddress initAddr;
    MemoryAddress playAddr;

  public:
    SidHeader();

    virtual const byte *get() const {};
    const byte *getCommon() const;

    const byte *getMagicID() const;

    virtual const short int size() const {};
};

#endif // SidHeader_h
