#include <stdio.h>
#include <time.h>

#include "logFile.h"

const char *logFilename = "logs.log";

void LogMsg(char *msg)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    char buff[60];
    sprintf(buff, "[%d-%d-%d %d:%d:%d] \t%s\n", 
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour,
            tm.tm_min, tm.tm_sec, msg);

    FILE *fp = fopen(logFilename, "a");
    if(fp == NULL) {
        perror("Cannot open logs file\n");
    } else {
        fprintf(fp, "%s", buff);
        fclose(fp);
    }
    fclose(fp);
}
