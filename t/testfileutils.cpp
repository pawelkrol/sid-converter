#include "testfileutils.h"

const char *TestFileUtils :: createRandomFile(const unsigned int numBytes) {
  char *fileName = tmpnam(NULL);
  FILE *pFile = fopen(fileName, "w");
  for (uint n = 0; n < numBytes; n++) {
    fprintf(pFile, "%c", rand() % 256);
  }
  fclose(pFile);
  return fileName;
}

const char *TestFileUtils :: createRandomFile(const byte *data, const unsigned int numBytes) {
  char *fileName = tmpnam(NULL);
  FILE *pFile = fopen(fileName, "w");
  for (uint n = 0; n < numBytes; n++) {
    fprintf(pFile, "%c", *(data + n));
  }
  fclose(pFile);
  return fileName;
}

/* Example:
 * #include "testfileutils.h"
 * unsigned int numBytes;
 * const char *fileName = TestFileUtils::createEmptySidFile(numBytes);
 * TestFileUtils::removeRandomFile(fileName);
 */
const char *TestFileUtils :: createEmptySidFile(unsigned int &numBytes) {
  const unsigned int dataSize = 9;
  const byte data [dataSize] = { 0x00, 0x10, 0x4c, 0x06, 0x10, 0x4c, 0x06, 0x10, 0x60 };

  SidHeader *sidHeader = new SidHeaderV2();
  const short int headerSize = sidHeader->size();

  const unsigned int fileSize = dataSize + headerSize;
  byte *sid = new byte(fileSize);

  const byte *headerData = sidHeader->get();
  memcpy(sid, headerData, headerSize);

  memcpy(sid + headerSize, data, dataSize);

  const char *filename = createRandomFile(sid, fileSize);

  delete headerData;
  delete sid;
  delete sidHeader;

  return filename;
}

// TODO
// const char *TestFileUtils :: createRandomSidFile(unsigned int &numBytes)

void TestFileUtils :: removeRandomFile(const char *fileName) {
  if (remove(fileName) != 0) {
    perror("Error deleting tempfile");
    throw SidException("Error deleting tempfile");
  }
}

const byte *TestFileUtils :: getFileContents(const char *fileName, unsigned int &numBytes) {
  FILE *pFile = fopen(fileName, "rb");
  if (pFile == NULL) {
    perror("File open error");
    throw SidException("File open error");
  }

  fseek(pFile, 0, SEEK_END);
  numBytes = ftell(pFile);
  rewind(pFile);

  byte *data = new byte [numBytes];
  if (data == NULL) {
    perror("Memory allocation error");
    throw SidException("Memory allocation error");
  }

  size_t result = fread(data, 1, numBytes, pFile);
  if (result != numBytes) {
    perror("File read error");
    throw SidException("File read error");
  }

  fclose(pFile);
  return data;
}

/* Example:
 * #include "testfileutils.h"
 * TestFileUtils::showFileContents(fileName, 8, 256);
 */
void TestFileUtils :: showFileContents(const char *fileName, unsigned int bytesPerLine, unsigned int maxNumBytes) {
  FILE *pFile = fopen(fileName, "rb");
  if (pFile == NULL) {
    return;
  }

  fseek(pFile, 0, SEEK_END);
  unsigned long int lSize = ftell(pFile);
  if (lSize == 0) {
    fclose(pFile);
    return;
  }
  rewind(pFile);

  printf("\nFILE: %s\n", fileName);
  printf("------");
  for (uint n = 0; n < strlen(fileName); n++) {
    printf("-");
  }
  printf("\n");

  unsigned int offset = 0x0000;
  byte *buffer = new byte [bytesPerLine];
  if (buffer == NULL) {
    perror("Memory allocation error");
    throw SidException("Memory allocation error");
  }

  unsigned int numBytesRead = 0;
  size_t result;
  while ((result = fread(buffer, 1, bytesPerLine, pFile))) {
    printf("$%08x  ", offset);
    bool wasBroken = false;
    for (uint n = 0; n < result; n++) {
      printf("$%02x ", *(buffer + n));
      if (++numBytesRead >= maxNumBytes) {
        wasBroken = true;
        break;
      }
    }
    printf("\n");
    if (wasBroken == true) {
      break;
    }
    offset += bytesPerLine;
  }

  delete buffer;
  fclose(pFile);
}
