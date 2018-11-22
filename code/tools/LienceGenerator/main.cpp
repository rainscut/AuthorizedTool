#include "LienceKit.h"
#include <stdio.h>
#include <string.h>
#include <string>

#include "UtilBase64.h"
#include "UtilString.h"

#ifdef __linux__
# include <getopt.h>
# include <unistd.h>
#else
# include <Windows.h>
# include "WinGetopt.h"
# define usleep(x) Sleep(x/1000)
#endif

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


#define LIENCE_PATH "lience.dat"

typedef struct {
    std::string machineFile;
    std::string outputFile = "lience.dat";
    uint16_t    days = 30;
} AppArgs_t;

AppArgs_t g_appArg;

void printUsage(const char* app) {
    printf("Usage: %s [options]\n"
           "  generator lience\n"
           "options:\n"
           "  -o <output file>   specify output file, default is 'lience.dat'\n"
           "  -m <machine file>  specify machine file, if not specified, \n"
           "                     will get the working machine code for lience.\n"
           "  -d <days>          set authorization time in days, default is 30 days\n"
           "  -h                 show usage information\n",
           app);
}


bool parseMachineFile(const char* path, MachineInfo_t& info) {
    FILE* fp = fopen(path, "rb");
    if (nullptr == fp) {
        LOG("open file failed: %s", strerror(errno));
        return false;
    }

    bool rv = true;
    std::string s;
    char buf[1024];
    size_t maxLen = 1024*10; //10k  生成的机器码长度不应该超过10K
    while (1) {
        size_t tmp = fread(buf, 1, 1024, fp);
        if (tmp == 0) {
            if (0 != ferror(fp)) {
                LOG("read file failed: %s", strerror(errno));
                rv = false;
            }
            break;
        }

        if (tmp > maxLen) {
            rv = false;
            LOG("file size is error");
            break;
        }
        maxLen -= tmp;
        s += std::string(buf, tmp);

        if (tmp < 1024) {
            break;
        }
    }

    fclose(fp);

    char *outBuf = nullptr;
    size_t outLen = util::base64::decode(s, &outBuf);
    if (outLen == 0) {
        LOG("base64 decode failed");
        rv = false;
    } else {
        for (size_t i=0; i<outLen; i++) {
            // 高4位和低4位交换
            char c = outBuf[i];
            outBuf[i] = (char)(((c & 0x0F)<<4) | ((c & 0xF0)>>4));
        }
        std::string str(outBuf, outLen);
        delete [] outBuf;
        outBuf = nullptr;

        // mac;cpuid;vendor;brand
        std::vector<std::string> ls = util::string::split(str, ';');
        if (4 != ls.size()) {
            rv = false;
        } else {
            info.mac = ls[0];
            info.cpuid = ls[1];
            info.vendor = ls[2];
            info.brand = ls[3];
        }
    }

    return rv;
}

int test () {
    LienceKit helper;
    while (1) {
        if (!helper.createLienceFile(LIENCE_PATH)) {
            printf("create lience file failed!\n");
            return -1;
        }
        printf("create lience file success!\n");

        bool rv = helper.isLienceFileVaild(LIENCE_PATH);
        printf("check vaild: %s\n", rv ? "true" : "false");
        if (!rv) {
            break;
        }
        fflush(stdout);
        usleep(100*1000);
    }
    return -1;
}

bool parseArgs(int argc, char** argv) {
    int c;
    char optstr[] = "d:m:o:h";
    while ((c = getopt(argc, argv, optstr)) != -1) {
        switch (c) {
            case 'h':
                printUsage(argv[0]);
                return false;

            case 'd':
                g_appArg.days = atoi(optarg);
                break;

            case 'm':
                g_appArg.machineFile = std::string(optarg);
                break;

            case 'o':
                g_appArg.outputFile = std::string(optarg);
                break;

            default:
                LOG("Unknown args, -h for help");
                return false;
        }
    }
    return true;
}

int main(int argc, char** argv)
{
    if (!parseArgs(argc, argv)) {
        return -1;
    }

    MachineInfo_t machineInfo;
    MachineInfo_t* info = nullptr;
    if (!g_appArg.machineFile.empty()) {
        if (!parseMachineFile(g_appArg.machineFile.c_str(), machineInfo)) {
            return -1;
        }
        info = &machineInfo;
    }

    LienceKit helper;
    if (!helper.createLienceFile(LIENCE_PATH, g_appArg.days, info)) {
        printf("create lience file failed!\n");
        return -1;
    }
    printf("create lience file success!\n");

    return 0;
}

