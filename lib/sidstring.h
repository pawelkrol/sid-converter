#ifndef SidString_h
#define SidString_h

#include <string.h>

#include "constants.h"

#define SID_STRING_SIZE 0x20
#define MAX_SID_STRING_SIZE 0x1f

class SidString {

  private:
    byte data [SID_STRING_SIZE];

    friend bool operator==(const SidString& a, const SidString& b);
    friend bool operator!=(const SidString& a, const SidString& b);

  public:
    SidString();

    void empty();

    const byte getLength() const;

    const char *getString() const;
    void setString(const char *str);
};

#endif // SidString_h
