#include "commonRest.h"

int CommonRest::getResponseOnlyUrl(string URL,void *callBack)
{
    return CommonRest::getResponse(URL,"",callBack);
}

int CommonRest::getResponseByJSON(string URL,Json::Value data,void *callBack)
{
    int ret = 0;
    Json::FastWriter fastWriter;
    string jsonObj = fastWriter.write(data);
   
    return CommonRest::getResponse(URL,jsonObj,callBack);

};

int CommonRest::getResponse(string URL,string data,void *callBack)
{
    CURL *curl;
    CURLcode res;

    struct curl_slist *headerlist = nullptr;
    headerlist = curl_slist_append(headerlist, "Content-Type: application/json");

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);

        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,  callBack);
        if(data != "")
        {
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        }
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
        }

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
};