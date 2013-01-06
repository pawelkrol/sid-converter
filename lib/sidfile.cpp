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

SidFile :: SidFile() : file(NULL), data(new SidData()), header(new SidHeaderV2()) {}

SidFile :: SidFile(const char *filename) : file(NULL), data(new SidData()), header(new SidHeaderV2()) {
  loadFile(filename);
}

SidFile :: SidFile(const byte *siddata, unsigned short int dataSize) {
  // TODO: add missing implementation...
  throw SidException("Not implemented yet!");
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
  cleanup();
}

void SidFile :: cleanup() {
  if (data != NULL) {
    delete data;
    data = NULL;
  }

  if (file != NULL) {
    delete file;
    file = NULL;
  }

  if (header != NULL) {
    switch (header->getVersionNum()) {
      case 1: {
        SidHeaderV1 *headerV1 = (SidHeaderV1 *)header;
        delete headerV1;
        break;
      }
      case 2: {
        SidHeaderV2 *headerV2 = (SidHeaderV2 *)header;
        delete headerV2;
        break;
      }
      default: {
        throw SidException("Invalid SID file version header");
      }
    }
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

  return *this;
}

const char *SidFile :: getFile() const {
  // TODO: add missing implementation...
  throw SidException("Not implemented yet!");
}

void SidFile :: setFile(const char *filename) {
  if (file != NULL) {
    delete file;
  }
  safeStringCopy(filename,file);
}

SidData *SidFile :: getData() const {
  return data;
}

SidHeader *SidFile :: getHeader() const {
  return header;
}

const byte *SidFile :: getBytes(unsigned int& length) const {
  unsigned short int dataSize;
  const byte *dataBytes = data->getFileData(dataSize);

  const byte *headerBytes = header->get();
  const short int headerSize = header->size();

  length = dataSize + headerSize;

  byte *bytes = new byte [length];
  memcpy(bytes, headerBytes, headerSize);
  memcpy(bytes + headerSize, dataBytes, dataSize);

  delete dataBytes;
  delete headerBytes;

  return bytes;
}

void SidFile :: loadFile(const char *filename) {
  unsigned long int filesize;
  const byte *bytes = SidFileUtils::read(filename, filesize);

  // Remove all references to the data previously held by an object:
  cleanup();

  safeStringCopy(filename, this->file)

  const short int headerVersionNum = SidHeader::checkVersionNum(bytes);
  switch (headerVersionNum) {
    case 1: {
      header = new SidHeaderV1(bytes);
      break;
    }
    case 2: {
      header = new SidHeaderV2(bytes);
      break;
    }
    default: {
      throw SidException("Invalid SID file version header");
    }
  }

  const short int headerSize = header->size();
  data = new SidData(bytes + headerSize, filesize - headerSize);
}

void SidFile :: load() {
  // TODO: add missing implementation...
  throw SidException("Not implemented yet!");
}

void SidFile :: save() const {
  const bool fileExists = SidFileUtils::exists(file);
  if (fileExists) {
    throw SidException("File already exists");
  }

  unsigned int filesize;
  const byte *data = getBytes(filesize);

  SidFileUtils::write(file, filesize, data);

  delete data;
}

void SidFile :: overwrite() const {
  // TODO: add missing implementation...
  throw SidException("Not implemented yet!");
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
