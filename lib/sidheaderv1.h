#ifndef SidHeaderV1_h
#define SidHeaderV1_h

#include "sidheader.h"

#define HEADER_V1_SIZE HEADER_COMMON_SIZE

class SidHeaderV1 : public SidHeader {

  private:
    friend bool operator==(const SidHeaderV1& a, const SidHeaderV1& b);
    friend bool operator!=(const SidHeaderV1& a, const SidHeaderV1& b);

  public:
    SidHeaderV1();
    SidHeaderV1(const byte *bytes);

    ~SidHeaderV1();

    SidHeaderV1& operator=(const SidHeaderV1& sidHeader);

    const byte *get() const;

    const short int size() const;

    void validate() const;

    void showDataDump() const;
};

#endif // SidHeaderV1_h
