#include "sidstring.h"

#include <stdio.h>

bool operator==(const SidString& a, const SidString& b) {
  const char *strA = a.getString();
  const char *strB = b.getString();

  bool result = strcmp (strA, strB) == 0;

  delete strA;
  delete strB;

  return result;
}

bool operator!=(const SidString& a, const SidString& b) {
  const char *strA = a.getString();
  const char *strB = b.getString();

  bool result = strcmp (strA, strB) != 0;

  delete strA;
  delete strB;

  return result;
}

SidString :: SidString() {
  empty();
}

void SidString :: empty() {
  memset (data, 0x00, SID_STRING_SIZE);
}

const byte SidString :: getLength() const {
  const char *str = getString();
  byte length = strchr (str, 0x00) - str;
  delete str;
  return length;
}

const char *SidString :: getString() const {
  char buffer [SID_STRING_SIZE];

  int i;

  for (i = 0; i < MAX_SID_STRING_SIZE; i++) {
    byte val = data[i];
    buffer[i] = val;

    if (val == 0x00) {
      break;
    }
  }

  char *str = new char [++i];
  strncpy (str, buffer, i);

  return str;
}

void SidString :: setString(const char *str) {
  int i;

  for (i = 0; i < strlen(str) && i < MAX_SID_STRING_SIZE; i++) {
    byte val = *(str + i);
    data[i] = val;

    if (val == 0x00) {
      break;
    }
  }

  data[i] = 0x00;
}

const byte *SidString :: getBytes() const {
  byte *bytes = new byte [SID_STRING_SIZE];
  memcpy (bytes, data, SID_STRING_SIZE);
  return bytes;
}
