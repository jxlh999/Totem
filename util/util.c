#include <stdio.h>
#include "util.h"

const int DEBUG_LEVEL_CLEAN = 0;
const int DEBUG_LEVEL_VERBOSE = 0x01;
const int DEBUG_LEVEL_INFO = (0x01 << 1);
const int DEBUG_LEVEL_DEBUG = (0x01 << 2);
const int DEBUG_LEVEL_WARN = (0x01 << 3);
const int DEBUG_LEVEL_ERROR = (0x01 << 4);
const int DEBUG_LEVEL_ALL = 0xFFFFFFFF;

int current_debug_level = 0xFFFFFFFF;

void print_log(const char *tag, const char *msg) {
    printf ("%s\t%s\n", tag, msg);
}

void set_debug_level(int debug_level) {
    current_debug_level = debug_level;
}

void log_v(const char *tag, const char *msg) {
    if ((current_debug_level & DEBUG_LEVEL_VERBOSE) == DEBUG_LEVEL_VERBOSE)
    {
	print_log(tag, msg);
    }
}

void log_i(const char *tag, const char *msg) {
    if ((current_debug_level & DEBUG_LEVEL_INFO) == DEBUG_LEVEL_INFO)
    {
	print_log(tag, msg);
    }
}

void log_d(const char *tag, const char *msg) {
    if ((current_debug_level & DEBUG_LEVEL_DEBUG) == DEBUG_LEVEL_DEBUG)
    {
	print_log(tag, msg);
    }
}

void log_w(const char *tag, const char *msg) {
    if ((current_debug_level & DEBUG_LEVEL_WARN) == DEBUG_LEVEL_WARN)
    {
	print_log(tag, msg);
    }

}

void log_e(const char *tag, const char *msg) {
    if ((current_debug_level & DEBUG_LEVEL_ERROR) == DEBUG_LEVEL_ERROR)
    {
	print_log(tag, msg);
    }
}

int main(int argc, char *argv[])
{
    set_debug_level(DEBUG_LEVEL_VERBOSE | DEBUG_LEVEL_WARN | DEBUG_LEVEL_ERROR | DEBUG_LEVEL_INFO | DEBUG_LEVEL_DEBUG);
    log_w("warn", "warning");
    log_d("debug", "debug");
    log_i("info", "infomation");
    log_e("error", "error");
    log_v("verbose", "verbose");
    return 0;
}

