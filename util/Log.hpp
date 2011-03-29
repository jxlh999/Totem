#include <stdio.h>
#include "Object.hpp"

using namespace lang;
namespace util {
  class Log : public Object {
  public:
    Log(int debug) {}
    ~Log() {}
    static const int VERBOSE = 2;
    static const int DEBUG = 3;
    static const int INFO = 4;
    static const int WARN = 5;
    static const int ERROR = 6;
    static const int ASSERT = 7;
  private:
    int 
  };

}
