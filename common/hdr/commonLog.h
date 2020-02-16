#ifndef __COMMON_LOG_H__
#define __COMMON_LOG_H__

#include <fstream>
#include <iostream>
#include <stdarg.h>
#include <dirent.h>
#include <sys/stat.h> 
#include <sys/types.h>

#include "commonInclude.h"

class CommonLog
{
    public:
        CommonLog();
        void writeErrLog(char *fmt, ...);
        void writeLog(char *fmt, ...);
    private:
        void writeLogToFile(string log);
        const string LOG_FILE_PATH = "/var/log/chatbot/";
        const int LOG_BUF_SIZE = 500;
        const int TIME_BUF_SIZE = 100;
};

#endif