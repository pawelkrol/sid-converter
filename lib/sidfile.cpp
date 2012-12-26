#include "sidfile.h"

bool operator==(const SidFile& a, const SidFile& b) {
  return SidFile::compare(a, b);
}

bool operator!=(const SidFile& a, const SidFile& b) {
  return !SidFile::compare(a, b);
}

const bool SidFile :: compare(const SidFile& a, const SidFile& b) {
  // TODO: fix "segmentation fault" implementation here...
  return !strcmp(a.file, b.file) && a.data == b.data && a.header == b.header;
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

const char *SidFile :: getFile() const {
  // TODO: add missing implementation...
}

void SidFile :: setFile(const char *filename) {
  // TODO: add missing implementation...
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
