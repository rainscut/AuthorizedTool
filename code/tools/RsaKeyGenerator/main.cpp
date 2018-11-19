#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>  // max

#if defined _WIN32
#include <direct.h>
# include <io.h>
# define access _access
# define F_OK 2
#elif defined __linux__
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
#endif

#include "EncryptKit.h"

void printUsage(char* appName) {
    printf("Usage: %s [target dir]\n"
           "  Create rsa key, if target dir is not assigned,\n"
           "rsa keys will be created at current work directory.\n"
           "And public key is key_rsa.pub, private key is key_rsa.\n",
           appName);
}

std::string parent(std::string path) {
    size_t pos = path.rfind('/');
    if (std::string::npos == pos) {
        return "";
    }
    return std::string(path.c_str(), pos);
}

bool makePath(std::string path) {
    if (access(path.c_str(), F_OK)) {
        return true;
    }
    std::string pDir = parent(path);
    if (!makePath(pDir)) {
        return false;
    }
#ifdef __linux__
    return 0 == mkdir(path.c_str(), 0755);
#else
    return 0 == mkdir(path.c_str());
#endif
}

int main(int argc, char *argv[])
{
    if (argc > 2) {
        printUsage(argv[0]);
        return -1;
    }

    std::string dir = ".";
    if (2 == argc) {
        dir = argv[1];
        if (!makePath(dir)) {
            return -1;
        }
    }

    std::string pubKeyPath = dir + "/key_rsa.pub";
    std::string priKeyPath = dir + "/key_rsa";

    if (!encrypt_kit::rsaCreateKey(pubKeyPath.c_str(), priKeyPath.c_str())) {
        printf("create failed\n");
        return -1;
    }

    printf("create rsa key success: \n"
           "  public key : %s\n"
           "  private key: %s\n",
           pubKeyPath.c_str(), priKeyPath.c_str());

    getchar();

    return 0;
}

