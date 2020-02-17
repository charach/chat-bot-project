#include "movieMsg.h"

int MovieMsg::processMsg(Json::Value receiveMsg,Json::Value sendMsg)
{
    int retVal = 0;

    movieRest.requestRest(receiveMsg,sendMsg);

    return CHAT_BOT_SUCCESS;
}