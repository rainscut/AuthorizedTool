#include <stdio.h>
#include <string.h>

#include "LienceValidator.h"

#define LIENCE_FILE "lience.dat"


std::string formatTime(time_t t)
{
    char buf[32] = {0};
    struct tm result;
#ifdef _WIN32
    localtime_s(&result, &t);
#else
    localtime_r(&t, &result);
#endif
    sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d",
            (1900+result.tm_year), (1+result.tm_mon), result.tm_mday,
            result.tm_hour, result.tm_min, result.tm_sec);
    return std::string(buf);
}

int main()
{
    LienceValidator v;
    bool rv = v.isVaild(LIENCE_FILE);
    printf("lience check result: %s\n", rv ? "true" : "false");

    if (rv) {
        std::string start = formatTime(v.authTime());
        std::string end = formatTime(v.vaildTime());
        printf("auth time : %s\n"
               "vaild time: %s\n", start.c_str(), end.c_str());
    }

    return 0;
}
