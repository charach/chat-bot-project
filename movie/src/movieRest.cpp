#include "movieRest.h"

MovieRest::MovieRest()
{

}

int MovieRest::requestRest(Json::Value receiveMsg,Json::Value sendMsg)
{
    getResponseByJSON(KMDB_URL,sendMsg,(void*)MovieRest::restCallBack);

    return CHAT_BOT_SUCCESS;
}

size_t MovieRest::restCallBack(void *contents, size_t size, size_t nmemb, void *userp)
{
    string str((char*)contents);
    printf("%s",str.c_str());
    return size * nmemb;
}
