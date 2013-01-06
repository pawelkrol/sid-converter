#ifndef Macros_h
#define Macros_h

#define bool2str(value) value ? "true" : "false"

#define safeStringCopy(source,target)          \
{                                              \
  size_t length = strlen(source);              \
  target = new char(length + 1);               \
  if (target == NULL) {                        \
    throw SidException("Insufficient memory"); \
  }                                            \
  strncpy(target, source, length);             \
  *(target + length) = 0;                      \
}

#define getSidHeaderValue(value,size)          \
  byte *_value = new byte[size];               \
  if (_value == NULL) {                        \
    throw SidException("Insufficient memory"); \
  }                                            \
  memcpy(_value, value, size);                 \
  return _value;

#define getSidHeaderNumValue(getValue)         \
  const byte *v       = getValue();            \
  const short int num = SidUtils::hexToInt(v); \
  delete v;                                    \
  return num;

#define getSidHeaderNumValue_1byte(getValue) \
  const byte *v       = getValue();          \
  const short int num = *v;                  \
  delete v;                                  \
  return num;

#define showValueDump(label,value,size) \
printf("\n  * %s = ", label);           \
for (int n = 0; n < size; n++) {        \
  printf("$%02x ", value[n]);           \
}

#define showStringDump(label,value)          \
if (value != NULL) {                         \
  printf("\n  * %s = \"%s\"", label, value); \
}                                            \
else {                                       \
  printf("\n  * %s = \"\"", label);          \
}

#define showSidStringDump(label,value)                   \
if (value.getLength() > 0) {                             \
  printf("\n  * %s = \"%s\"", label, value.getString()); \
}                                                        \
else {                                                   \
  printf("\n  * %s = \"\"", label);                      \
}

#endif // Macros_h
