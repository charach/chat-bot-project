#ifndef __COMMON_LOG_H__
#define __COMMON_LOG_H__

class CommonLog
{
    public:
        void writeErrLog(string log);
        void writeLog(string log);
    private:
        void writeLogToFile(string log);
};

#endif