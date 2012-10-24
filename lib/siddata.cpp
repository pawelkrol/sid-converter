#include "siddata.h"

bool operator==(const SidData& a, const SidData& b) {
  return SidData::compare(a, b);
}

bool operator!=(const SidData& a, const SidData& b) {
  return !SidData::compare(a, b);
}

const bool SidData :: compare(const SidData& a, const SidData& b) {
  unsigned short int lengthA, lengthB;
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

void SidData :: setRawData(const byte *raw, unsigned short int rawSize) {
  data = new byte [rawSize];
  memcpy(data, raw, rawSize);
  length = rawSize;
}


SidData :: SidData() :
  address(),
  data(NULL),
  length(0)
{}

SidData :: SidData(const byte *data, unsigned short int dataSize) {
  if (dataSize < 0x02) {
    throw SidException("Insufficient amount of data provided for proper initialization of SidData object instance: *data needs to contain at least two bytes!");
  }

  if (data == NULL) {
    throw SidException("Insufficient data provided for proper initialization of SidData object instance: data pointer value cannot be NULL!");
  }

  const addr memaddr = SidUtils::twoBytesToAddr(data);
  address = memaddr;

  setRawData(data + 2, dataSize - 2);
}

SidData :: SidData(const byte *raw, unsigned short int rawSize, const MemoryAddress addr) {
  address = addr;

  setRawData(raw, rawSize);
}

SidData :: ~SidData() {
  if (data != NULL) {
    delete data;
    data = NULL;
  }
}

const MemoryAddress SidData :: getAddress() const {
  return address;
}

const unsigned short int SidData :: getRawDataLength() const {
  return length;
}

const byte *SidData :: getRawData(unsigned short int &len) const {
  const unsigned short int amount = getRawDataLength();
  len = amount;
  if (amount == 0) {
    return NULL;
  }
  byte *rawData = new byte [amount];
  memcpy(rawData, data, amount);
  return rawData;
}

const byte *SidData :: getFileData(unsigned short int &len) const {
  const byte *addr = getAddress().getLoHi();

  unsigned short int temp;
  const byte *rawData = getRawData(temp);

  byte *fileData = new byte [length + 2];

  memcpy(fileData + 0, addr, 2);
  memcpy(fileData + 2, rawData, length);

  delete addr;
  delete rawData;

  len = length + 2;

  return fileData;
}

void SidData :: showDataDump() const {
  printf("\nSidData :: dataDump");
  printf("\n===================");
  printf("\n  * object = %p", this);
  printf("\n  * address = $%04x", getAddress().get());
  printf("\n  * length = %d", length);
  printf("\n  * data [raw data dump]\n");

  const char *dump = SidUtils::dumpData(data, length);
  printf("%s\n", dump);
}
