#include "siddata.h"

bool operator==(const SidData& a, const SidData& b) {
  return SidData::compare(a, b);
}

bool operator!=(const SidData& a, const SidData& b) {
  return !SidData::compare(a, b);
}

const bool SidData :: compare(const SidData& a, const SidData& b) {
  short int lengthA, lengthB;
  const byte *dataA = a.getFileData(lengthA);
  const byte *dataB = b.getFileData(lengthB);

  if (lengthA != lengthB) {
    delete dataA;
    delete dataB;

    return false;
  }

  bool result = SidUtils::compareData(dataA, dataB, lengthA);

  delete dataA;
  delete dataB;

  return result;
}

// TODO: implementation missing for all other SidData methods...
