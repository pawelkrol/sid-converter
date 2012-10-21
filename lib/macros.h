#ifndef Macros_h
#define Macros_h

#define bool2str(value) value ? "true" : "false"

#define getSidHeaderValue(value,size) \
  byte *_value = new byte[size];      \
  memcpy(_value, value, size);        \
  return _value;

#define getSidHeaderNumValue(getValue)         \
  const byte *v       = getValue();            \
  const short int num = SidUtils::hexToInt(v); \
  delete v;                                    \
  return num;

#endif // Macros_h
