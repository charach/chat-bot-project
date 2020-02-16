#include "commonLog.h"

CommonLog::CommonLog()
{
    if(mkdir(LOG_FILE_PATH.c_str(),0777) == -1 && errno != EEXIST)
    {
        char errorLogBuf[STRERROR_LOG_BUF];
        fprintf(stderr,"%s directory create error\n",LOG_FILE_PATH.c_str());
        fprintf(stderr,"%s\n",strerror_r(errno,errorLogBuf,sizeof(errorLogBuf)));
    }

}

void CommonLog::writeErrLog(char *fmt, ...)
{
    char logBuf[LOG_BUF_SIZE];
    va_list ap;

    va_start(ap, fmt);
    if (vsprintf(logBuf, fmt, ap) < 0)
    {
        char strErrBuf[LOG_BUF_SIZE];
        memset(strErrBuf, 0x00, sizeof(strErrBuf));
        fprintf(stderr, "%s[%d] vsprintf fail (%s)", __func__, __LINE__, strerror_r(errno, strErrBuf, sizeof(strErrBuf)));
        return;
    }

    va_end(ap);

    string log = "";
    log = string("ERR").append(string(logBuf));

    writeLogToFile(log);
}

void CommonLog::writeLog(char *fmt, ...)
{
    char logBuf[LOG_BUF_SIZE];
    va_list ap;

    va_start(ap, fmt);
    if (vsprintf(logBuf, fmt, ap) < 0)
    {
        char strErrBuf[LOG_BUF_SIZE];
        memset(strErrBuf, 0x00, sizeof(strErrBuf));
        fprintf(stderr, "%s[%d] vsprintf fail (%s)", __func__, __LINE__, strerror_r(errno, strErrBuf, sizeof(strErrBuf)));
        return;
    }

    va_end(ap);

    string log = "";
    log = string(logBuf);

    writeLogToFile(log);
}

void CommonLog::writeLogToFile(string log)
{
    
    time_t t = time(0);
    struct tm *lt = localtime(&t);
    char time_str[TIME_BUF_SIZE] = { 0, };   
    char logBuf[LOG_BUF_SIZE] = { 0, };

    snprintf(time_str, TIME_BUF_SIZE, "[%04d%02d%02d]", lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday);
    string logFilePath = LOG_FILE_PATH + string(time_str);

    ofstream writeFile(logFilePath.data());

    if (!writeFile.is_open())
    {
        char strErrBuf[LOG_BUF_SIZE];
        memset(strErrBuf, 0x00, sizeof(strErrBuf));
        fprintf(stderr, "%s[%d] writeFile.is_open error (%s)", __func__, __LINE__, strerror_r(errno, strErrBuf, sizeof(strErrBuf)));
        return;
    }

    snprintf(time_str, TIME_BUF_SIZE, "[%04d%02d%02d%02d%02d%02d]", lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
    log = string(time_str).append(log);
    writeFile << log.c_str() << endl;

    writeFile.close();

}
