#ifndef __MOVIE_MSG_H__
#define __MOVIE_MSG_H__

#include "commonInclude.h"
#include "commonMsg.h"

class MovieMsg : public CommonMsg
{
    public :
        int processMsg(string receiveMsg,string sendMsg);
    private :
};

#endif