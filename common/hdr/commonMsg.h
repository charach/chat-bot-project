#ifndef __COMMON_MSG_H__
#define __COMMON_MSG_H__

#include "commonInclude.h"

class CommonMsg
{
    public:
        virtual int processMsg(Json::Value receiveMsg,Json::Value sendMsg);
    private:

};

#endif