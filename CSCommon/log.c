#include "log.h"

#include <time.h>

void writeLog(const char* format, ...)
{
    char d[64];
    char l[4096];
    va_list args;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(d, sizeof(d), "[%d-%d-%d %d:%d:%d]", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    va_start(args, format);
    vsnprintf(l, sizeof(l), format, args);
    va_end(args);

    printf("%s%s",d,l);

    FILE *fp = fopen("/home/yttrium/Documents/Cours/CapitalismSimulator/build-CapitalismSimulator-Desktop-Debug/log.txt", "ab");
    if (fp != NULL)
    {
        fputs(d, fp);
        fputs(l, fp);
        fclose(fp);
    }

}
