#include "sidexception.h"

#include <stdio.h>

SidException :: SidException() :
  message("")
{}

SidException :: SidException(const char *msg) :
  message(msg)
{}

const char *SidException :: getMessage() const {
  size_t length = message.length() + 1;
  char *buffer = new char [length];
  memcpy(buffer, message.c_str(), length);
  return buffer;
}

void SidException :: setMessage(const char *msg) {
  message = msg;
}
