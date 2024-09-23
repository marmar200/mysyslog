#include "mysyslog.h"
#include <stdio.h>
#include <time.h>

int mysyslog(const char* msg, int level, int driver, int format, const char* path) {
    // Пример базовой реализации
    FILE* file = fopen(path, "a");
    if (!file) return -1;

    time_t now = time(NULL);
    fprintf(file, "%ld %d %d %d %s\n", now, level, driver, format, msg);
    fclose(file);
    return 0;
}