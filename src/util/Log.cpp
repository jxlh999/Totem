#include "../../include/util/Log.h"
#include <string.h>
#include <time.h>

Log::Log() {
	mCurrentLogLevel = LOG_LEVEL_ALL;
}

Log::Log(int logLevel) :
	mCurrentLogLevel(logLevel) {
}

void Log::SetCurrentLogLevel(int logLevel) {
	mCurrentLogLevel = logLevel;
}

int Log::GetCurrentLogLevel() {
	return mCurrentLogLevel;
}

void Log::PrintLog(const char *tag, const char *msg) {
	time_t t;
	time(&t);
	char *time = ctime(&t);
	char *buf = malloc(strlen(time) + 1);
	memset(buf, 0, strlen(time) + 1);
	strncpy(buf, time, strlen(time) - 1);
	printf("[%s]\t%s\t%s\n", buf, tag, msg);
	free(buf);
}

void Log::V(const char *tag, const char *msg) {
	if ((mCurrentLogLevel & LOG_LEVEL_VERBOSE) == LOG_LEVEL_VERBOSE) {
		PrintLog(tag, msg);
	} else {
		// do nothing.
	}
}

void Log::D(const char *tag, const char *msg) {
	if ((mCurrentLogLevel & LOG_LEVEL_DEBUG) == LOG_LEVEL_DEBUG) {
		PrintLog(tag, msg);
	}
}

void Log::I(const char *tag, const char *msg) {
	if ((mCurrentLogLevel & LOG_LEVEL_INFO) == LOG_LEVEL_INFO) {
		PrintLog(tag, msg);
	} else {
		// do nothing.
	}
}

void Log::W(const char *tag, const char *msg) {
	if ((mCurrentLogLevel & LOG_LEVEL_WARNING) == LOG_LEVEL_WARNING) {
		PrintLog(tag, msg);
	} else {
		// do nothing.
	}
}

void Log::E(const char *tag, const char *msg) {
	if ((mCurrentLogLevel & LOG_LEVEL_ERROR) == LOG_LEVEL_ERROR) {
		PrintLog(tag, msg);
	} else {
		// do nothing.
	}
}
