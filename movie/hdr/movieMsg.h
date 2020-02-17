#ifndef __MOVIE_MSG_H__
#define __MOVIE_MSG_H__

#include "commonInclude.h"
#include "commonMsg.h"
#include "movieRest.h"

class MovieMsg : public CommonMsg
{
    public :
        int processMsg(Json::Value receiveMsg,Json::Value sendMsg) override;
    private :
        MovieRest movieRest;
};

#endif