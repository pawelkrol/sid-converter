#include "testutils.h"

int TestUtils :: compare(const byte *a, const byte *b, unsigned int size = -1) {
  unsigned int totalSize = size;
  const byte *startA = a;
  const byte *startB = b;

  do {
    if (*a != *b) {
      printf("\n*** TestUtils::compare ***");
      printf("\n  Difference found at offset = $%02x", totalSize - size);
      printf("\n  Expected: $%02x at *(b + $%02x)", *b, totalSize - size);
      printf("\n  But got: $%02x at *(a + $%02x)", *a, totalSize - size);
      const char *aDump = SidUtils::dumpData(startA, totalSize, 16);
      const char *bDump = SidUtils::dumpData(startB, totalSize, 16);
      printf("\n\n  *a data dump (a = %p):\n%s\n", startA, aDump);
      printf("\n  *b data dum (b = %p):\n%s\n", startB, bDump);
      delete aDump;
      delete bDump;
      printf("\n  Comparison result = %s", bool2str(false));
      return (*a < *b) ? -1 : 1;
    }
    a++;
    b++;
  }
  while (--size > 0);
  return 0;
}

/*const char *TestUtils :: getcwd() {
  char buffer [PATH_MAX];

  // TODO: add missing implementation...

  return NULL;
}*/
