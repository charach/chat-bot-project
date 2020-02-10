#include "movieRest.h"

size_t MovieRest::restCallBack(void *contents, size_t size, size_t nmemb, void *userp)
{
    string str((char*)contents);
    printf("%s",str.c_str());
    return size * nmemb;
}
