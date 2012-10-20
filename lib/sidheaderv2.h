#ifndef SidHeaderV2_h
#define SidHeaderV2_h

#define HEADER_V2_SIZE 0x7C

#include "sidheader.h"

class SidHeaderV2 : public SidHeader {

  private:
    /*** TODO: implementation missing! ***/
    /*** TODO: add missing properties! ***/

    friend bool operator==(const SidHeaderV2& a, const SidHeaderV2& b);

  public:
    const byte *get() const;

    const short int size() const;
};

#endif // SidHeaderV2_h
