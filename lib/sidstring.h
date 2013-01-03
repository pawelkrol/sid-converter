#ifndef SidString_h
#define SidString_h

#include <string.h>

#include "constants.h"

// Consider setting up this data as properties of SidString class:
#define SID_STRING_SIZE 0x20
#define MAX_SID_STRING_SIZE 0x1f

class SidString {

  private:
    byte data [SID_STRING_SIZE];

    friend bool operator==(const SidString& a, const SidString& b);
    friend bool operator!=(const SidString& a, const SidString& b);

  public:
    SidString();
    SidString(const byte *bytes);

    void empty();

    const byte getLength() const;

    const char *getString() const;
    void setString(const char *str);

    const byte *getBytes() const;
};

#endif // SidString_h
