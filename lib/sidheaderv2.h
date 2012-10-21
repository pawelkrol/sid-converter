#ifndef SidHeaderV2_h
#define SidHeaderV2_h

#include "sidheader.h"
#include "sidflags.h"

#define HEADER_V2_SIZE 0x7c

#define FLAGS_OFFSET 0x76
#define START_PAGE_OFFSET 0x78
#define PAGE_LENGTH_OFFSET 0x79
#define RESERVED_OFFSET 0x7a

#define START_PAGE_SIZE 0x01
#define PAGE_LENGTH_SIZE 0x01
#define RESERVED_SIZE 0x02

class SidHeaderV2 : public SidHeader {

  private:
    SidFlags flags; // offset: 0x76
    byte startPage [START_PAGE_SIZE]; // offset: 0x78
    byte pageLength [PAGE_LENGTH_SIZE]; // offset: 0x79
    byte reserved [RESERVED_SIZE]; // offset: 0x7a

    friend bool operator==(const SidHeaderV2& a, const SidHeaderV2& b);
    friend bool operator!=(const SidHeaderV2& a, const SidHeaderV2& b);

    static const bool compare(const SidHeaderV2& a, const SidHeaderV2& b);

  public:
    SidHeaderV2();

    const byte *get() const;

    const byte *getFlags() const;

    /*** TODO: implementation missing! ***/
    // TODO: add missing accessor/setter methods...
    //  * startPage
    //  * pageLength
    //  * reserved
    /*** TODO: implementation missing! ***/

    const short int size() const;
};

#endif // SidHeaderV2_h
