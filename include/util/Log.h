#include <stdio.h>

//using namespace lang;
namespace util {
class Log/*: public Object */{
public:
	Log();
	Log(int logLevel);
	virtual ~Log();
	static const int LOG_LEVEL_NONE = 0;
	static const int LOG_LEVEL_VERBOSE = 1;
	static const int LOG_LEVEL_DEBUG = 1 << 1;
	static const int LOG_LEVEL_INFO = 1 << 2;
	static const int LOG_LEVEL_WARNING = 1 << 3;
	static const int LOG_LEVEL_ERROR = 1 << 4;
	static const int LOG_LEVEL_ALL = 0xFFFFFFFF;

	void V(const char *tag, const char *msg);
	void D(const char *tag, const char *msg);
	void I(const char *tag, const char *msg);
	void W(const char *tag, const char *msg);
	void E(const char *tag, const char *msg);
	void SetCurrentLogLevel(int logLevel);
	int GetCurrentLogLevel();

private:
	void PrintLog(const char *tag, const char *msg);
	int mCurrentLogLevel;
};

}
