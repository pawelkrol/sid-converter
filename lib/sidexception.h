#ifndef SidException_h
#define SidException_h

#include <stddef.h>
#include <string.h>

#include <string>

class SidException {

  private:
    std::string message;

  public:
    SidException();
    SidException(const char *msg);

    const char *getMessage() const;
    void setMessage(const char *msg);
};

#endif // SidException_h
