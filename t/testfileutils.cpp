#include "testfileutils.h"

const char *TestFileUtils :: createRandomFile(const int numBytes) {
  char *fileName = tmpnam(NULL);
  FILE *pFile = fopen(fileName, "w");
  for (int n = 0; n < numBytes; n++) {
    fprintf(pFile, "%c", rand() % 256);
  }
  fclose(pFile);
  return fileName;
}

const char *TestFileUtils :: createRandomFile(const byte *data, const int numBytes) {
  char *fileName = tmpnam(NULL);
  FILE *pFile = fopen(fileName, "w");
  for (int n = 0; n < numBytes; n++) {
    fprintf(pFile, "%c", *(data + n));
  }
  fclose(pFile);
  return fileName;
}

void TestFileUtils :: removeRandomFile(const char *fileName) {
  if (remove(fileName) != 0) {
    perror("Error deleting tempfile");
    throw SidException("Error deleting tempfile");
  }
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
  for (int n = 0; n < strlen(fileName); n++) {
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
  while (result = fread(buffer, 1, bytesPerLine, pFile)) {
    printf("$%08x  ", offset);
    bool wasBroken = false;
    for (int n = 0; n < result; n++) {
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
