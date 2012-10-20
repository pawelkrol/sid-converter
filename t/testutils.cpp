#include "testutils.h"

#include <stdio.h>

int TestUtils :: compare(const byte *a, const byte *b, unsigned int size = -1) {
  do {
    if (*a != *b) {
      return (*a < *b) ? -1 : 1;
    }
    a++;
    b++;
  }
  while (--size > 0);
  return 0;
}
