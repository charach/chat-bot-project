#ifndef __COMMON_REST_H__
#define __COMMON_REST_H__

#include "commonInclude.h"

class CommonRest
{
    public:
        int getResponseOnlyUrl(string URL,void *callBack);
        int getResponseByJSON(string URL,Json::Value data,void *callBack);
    private:
        int getResponse(string URL,string data,void *callBack);
};

#endif