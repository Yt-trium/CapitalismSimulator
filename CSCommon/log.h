#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdarg.h>

char me[6];
void writeLog(const char* format, ...);

#endif // LOG_H
