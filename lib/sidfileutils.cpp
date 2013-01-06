#include "sidfileutils.h"

const bool SidFileUtils :: exists(const char *filename) {
  FILE *pFile = fopen(filename, "rb");
  if (pFile == NULL) {
    return false;
  }
  fclose(pFile);
  return true;
}

const byte *SidFileUtils :: read(const char *filename, unsigned long int &filesize) {
  FILE *pFile = fopen(filename, "rb");
  if (pFile == NULL) {
    throw SidException("File open error");
  }

  fseek(pFile, 0, SEEK_END);
  filesize = ftell(pFile);
  rewind(pFile);

  byte *data = new byte [filesize];
  if (data == NULL) {
    throw SidException("Memory allocation error");
  }

  size_t result = fread(data, 1, filesize, pFile);
  if (result != filesize) {
    throw SidException("File read error");
  }

  fclose(pFile);
  return data;
}

void SidFileUtils :: write(const char *filename, const unsigned int filesize, const byte *data) {
  FILE *pFile = fopen(filename, "w");
  if (pFile == NULL) {
    throw SidException("File open error");
  }

  for (unsigned int n = 0; n < filesize; n++) {
    fprintf(pFile, "%c", *(data + n));
  }

  fclose(pFile);
}
