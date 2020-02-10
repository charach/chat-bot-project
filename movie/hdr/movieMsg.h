#include "commonInclude.h"
#ifndef __MOVIE_MSG_H__
#define __MOVIE_MSG_H__

class MovieMsg : public CommonMsg
{
    public :
        int processMsg(string receiveMsg,string sendMsg);
    private :
};

#endif