#include "commonInclude.h"

#include "movieMsg.h"

int main(int argc,char *argv[])
{
    int retVal = 0;
    string msgFromUser = "";

    MovieMsg movieMsg;
    

    Json::Value msgFromUserJson;
    Json::Value answer;
    cout << "HiHi May I Help You?" << endl;

    while(true)
    {
        cin >> msgFromUser;

        if(msgFromUser.find("byebye") != string::npos)
        {
            break;
        }

        cout << "Movie Name?" << endl;


        if(( retVal = movieMsg.processMsg(msgFromUserJson,answer)) != CHAT_BOT_SUCCESS)
        {
            break;
        }

        cout << answer << endl;
    }

    return 0;

}