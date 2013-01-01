#include "sidfile.h"

bool operator==(const SidFile& a, const SidFile& b) {
  return SidFile::compare(a, b);
}

bool operator!=(const SidFile& a, const SidFile& b) {
  return !SidFile::compare(a, b);
}

const bool SidFile :: compare(const SidFile& a, const SidFile& b) {
  const short int headerVersionA = a.header->getVersionNum();
  const short int headerVersionB = b.header->getVersionNum();

  if (headerVersionA != headerVersionB) {
    return false;
  }

  if (a.file != b.file && strcmp(a.file, b.file) != 0) {
    return false;
  }

  if (*a.data != *b.data) {
    return false;
  }

  switch (headerVersionA) {
    case 1: {
      return *(SidHeaderV1 *)a.header == *(SidHeaderV1 *)b.header;
    }
    case 2: {
      return *(SidHeaderV2 *)a.header == *(SidHeaderV2 *)b.header;
    }
    default: {
      throw SidException("Invalid SID file version header");
    }
  }
}

SidFile :: SidFile() : data(new SidData()), file(NULL), header(new SidHeaderV2()) {}

SidFile :: SidFile(const char *filename) {
  // TODO: add missing implementation...
}

SidFile :: SidFile(const byte *siddata, unsigned short int dataSize) {
  // TODO: add missing implementation...
}

SidFile :: SidFile(const SidHeader &sidHeader, const SidData &sidData) : file(NULL) {
  data = new SidData;
  *data = sidData;

  switch (sidHeader.getVersionNum()) {
    case 1: {
      header = new SidHeaderV1();
      break;
    }
    case 2: {
      header = new SidHeaderV2();
      break;
    }
    default: {
      throw SidException("Invalid SID file version header");
    }
  }
  *header = sidHeader;
}

SidFile :: ~SidFile() {
  if (data != NULL) {
    delete data;
    data = NULL;
  }

  if (file != NULL) {
    delete file;
    file = NULL;
  }

  if (header != NULL) {
    delete header;
    header = NULL;
  }
}

SidFile& SidFile :: operator=(const SidFile& sidFile) {
  if (sidFile.file != NULL) {
    safeStringCopy(sidFile.file, this->file)
  }
  else {
    this->file = NULL;
  }

  *(this->data) = *sidFile.data;
  *(this->header) = *sidFile.header;
}

const char *SidFile :: getFile() const {
  // TODO: add missing implementation...
}

void SidFile :: setFile(const char *filename) {
  // TODO: add missing implementation...
}

SidData *SidFile :: getData() const {
  return data;
}

SidHeader *SidFile :: getHeader() const {
  return header;
}

void SidFile :: load() {
  // TODO: add missing implementation...
}

void SidFile :: save() const {
  // TODO: add missing implementation...
}

void SidFile :: showDataDump() const {
  printf("\n***********************");
  printf("\nSidFile :: dataDump");
  printf("\n===================");
  printf("\n  * object = %p", this);

  showStringDump("filename", file)

  printf("\n");
  header->showDataDump();
  data->showDataDump();

  printf("\n***********************\n");
}
