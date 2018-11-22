#include <stdio.h>
#include <string.h>

#include "UtilBase64.h"
#include "UtilMachine.h"

#ifndef QT_NO_DEBUG
// debug mode
# define LOG(f, ...) do{\
    printf(f, ##__VA_ARGS__);\
    printf("\n");\
    }while(0)
#else
// release mode
# define LOG(format, ...)
#endif

int main(int argc, char** argv)
{
    std::string out = "machine_code";
    std::string macid;

    if (argc >= 2) {
        out = std::string(argv[1]);
    }

    util::machine::CpuInfo_t cpuinfo;
    util::machine::getCpuInfo(cpuinfo);
    if ( cpuinfo.guid.empty()
         || !util::machine::getMacInfo(macid)) {
        printf("get machine information failed!\n");
        return -1;
    }

    char buf[128] = {};
    size_t len = sprintf(buf, "%s;%s;%s;%s",
                         macid.c_str(),
                         cpuinfo.guid.c_str(),
                         cpuinfo.vendor.c_str(),
                         cpuinfo.brand.c_str());
    for (size_t i=0; i<len; i++) {
        // 高4位和低4位交换
        char c = buf[i];
        buf[i] = (char)(((c & 0x0F)<<4) | ((c & 0xF0)>>4));
    }

    std::string str = util::base64::encode(buf, len);
    printf("You machine code is:\n"
           "%s\n", str.c_str());

    FILE* fp = fopen(out.c_str(), "wb+");
    if (nullptr == fp) {
        printf("create file failed: %s\n", strerror(errno));
        return -1;
    }

    fwrite(str.c_str(), 1, str.size(), fp);
    fflush(fp);
    fclose(fp);
    fp = nullptr;

    return 0;
}
