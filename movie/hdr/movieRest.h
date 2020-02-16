#ifndef __MOVIE_REST_H__
#define __MOVIE_REST_H__

#include "commonInclude.h"
#include "commonRest.h"

class MovieRest : public CommonRest
{
    public :
        size_t restCallBack(void *contents, size_t size, size_t nmemb, void *userp);

    private :
        bool callBackFlag = false;
        const string KMDB_URL = "http://api.koreafilm.or.kr/openapi-data2/wisenut/search_api/search_xml.jsp?collection=kmdb_new&detail=N&director=%EB%B0%95%EC%B0%AC%EC%9A%B1&ServiceKey=51WVUH6XA1E6BJZ6E90S";
};

#endif