#include "LienceKit.h"

int main()
{
    LienceKit helper;
    if (!helper.createLienceFile("lience.dat")) {
        printf("create lience file failed!\n");
        return -1;
    }
    printf("create lience file success!\n");

    getchar();

//    bool rv = helper.isLienceFileVaild("lience.dat");
//    printf("lience is %s\n", rv ? "valid" : "invalid");

    return 0;
}

