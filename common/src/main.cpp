#include "commonInclude.h"
#include "movieMsg.h"

int main(int argc,char *argv[])
{
    int retVal = 0;
    string msgFromUser = "";
    string answer = "";

    MovieMsg movieMsg;
    
    cout << "HiHi May I Help You?" << endl;

    while(true)
    {
        cin >> msgFromUser;

        if(msgFromUser.find("byebye") != string::npos)
        {
            break;
        }

        if(( retVal = movieMsg.processMsg(msgFromUser,answer)) != CHAT_BOT_SUCCESS)
        {
            break;
        }

        cout << answer << endl;
    }

}