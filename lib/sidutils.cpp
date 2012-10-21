#include "sidutils.h"

const short int SidUtils :: hexToInt(const byte *hex) {
  char val[6];
  sprintf(val, "%5d", *(hex + 0) * 256 + *(hex + 1));
  return atoi(val);
}

const bool SidUtils :: compareData(const byte *dataA, const byte *dataB, const unsigned int size) {
  bool result = true;

  for (int i = 0; i < size; i++) {
    byte valueA = *(dataA + i);
    byte valueB = *(dataB + i);

    if (valueA != valueB) {
      result = false;
      break;
    }
  }

  return result;
}

const char *SidUtils :: dumpData(const byte *data, const unsigned int size, const unsigned int bytesPerLine) {
  std::string buffer = std::string();

  for (unsigned int i = 0; i < size; i++) {
    if (i % bytesPerLine == 0) {
      buffer += "\n";
    }
    char val [3];
    sprintf (val, "$%02x", *(data + i));
    buffer += val;
    if (i + 1 != size && (i + 1) % bytesPerLine != 0) {
      buffer += ",";
    }
  }

  size_t length = buffer.length() + 1;
  char *dump = new char [length];

  memcpy(dump, buffer.c_str(), length);
  return dump;
}
