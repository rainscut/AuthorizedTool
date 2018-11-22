#include <stdio.h>
#include <string.h>
#include <string>

#ifdef _WIN32
#include "WinGetopt.h"
#else
#include <getopt.h>
#endif

#include "EncryptKit.h"


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

typedef struct {
    std::string input;
    std::string output;
    std::string type;
} AppArg_t;

void printUsage(const char* app) {
    printf("Usage: %s [options]\n"
           "  read input file, do encrypt and decode base64 or decode file and\n"
           "do decrypt\n"
           "options:\n"
           "  -t encrypt|decrypt\n"
           "             do encrypt or do decrypt, default encrypt\n"
           "  -f file    the file to encrypt\n"
           "  -o file    the file to output\n",
           app);
}

int parseArgs(int argc, char** argv, AppArg_t& arg)
{
    int c;
    char optstr[] = "t:f:o:h";
    while ((c = getopt(argc, argv, optstr)) != -1) {
        switch (c) {
            case 'h':
                printUsage(argv[0]);
                return -1;

            case 't':
                arg.type = std::string(optarg);
                break;

            case 'f':
                arg.input = std::string(optarg);
                break;

            case 'o':
                arg.output = std::string(optarg);
                break;

            default:
                LOG("Unknown args, -h for help");
                return -1;
        }
    }
    return 0;
}

bool doDecodeAndDecrypt(FILE* in, FILE* out) {
    std::vector<uint8_t> priKey;
    std::string priStr =
            "-----BEGIN PRIVATE KEY-----\n"
            "MIICdgIBADANBgkqhkiG9w0BAQEFAASCAmAwggJcAgEAAoGBAMrITwLJ/eB2SD5+\n"
            "BG36D2uIX7BbUlML2X1BgdTKl8ukF6UFN0n8XqlbRaVf8n0gUhyaFdyeDPY71quB\n"
            "l62GjivbE66XNFyIFtjUsyWXCfYHtncS/cyIolHZHHGJt3JLjPFf1Xg4BUz4d+ZD\n"
            "E4ggR8bBWVLSIKXf0oa1S53FxBK3AgMBAAECgYBDgcq34XnIk2f6keY0nIYspMJC\n"
            "SiyOZAf76GZp6iX9j7ulXqao1UDIPY/ifZ4S5MMhLXSwtNcY1BPjlalihcRnImd9\n"
            "iUdNZXOJFVBeCYn++V2jC8YH70iR7dcB/0XJoGaJfcPY30QSnGYmkLCtmB3BY8RY\n"
            "pQZLMrem+CDQy84FMQJBAOt1ywKyiuI8aFHUoTi6lEcNuDsWhQ1rQq9lK5fo8p78\n"
            "rop5VpdzlLB4UmG8FmhX5shsY7MntelBq+QhyhwwWbECQQDceMUmxoMHcvopN+x6\n"
            "DFRXsy2CxMeaj8T1yIYPYMoxThEROKQjzLBigfCCCCB+j5yOXnhrJHd+PQ5sp7Bx\n"
            "OmTnAkA2/M5JNfr7NJJEMfzoq6H/KfQRUIQICzmKjnzswAkRGf+E9StEuUhLIf5T\n"
            "NsKg4Y5S1gU+jJKOA7kp0L5LcPsxAkEAjGj11m4SwMm+/EU7e7cieAAK+f9sx8jM\n"
            "PWQJzP1th90aDYevMYWIyBPNImMenrvDjwAnXMUKvQERkK1zN4li/QJAb3Ie0kK3\n"
            "kSuuCCObQi6Ae6SNCbzD/g84YSZm8h/TUNL3z1nxmTZoONQdE1L5Kmy01NavWGEl\n"
            "opSX12V03ePN1g==\n"
            "-----END PRIVATE KEY-----\n";
    priKey.resize(priStr.size());
    memcpy(priKey.data(), priStr.data(), priKey.size());

    constexpr size_t blocksize = 1024; // 必须是4的倍数
    char inBuf[blocksize];
    while (true) {
        // read block
        size_t tmp = fread(inBuf, 1, blocksize, in);
        if (tmp == 0) {
            if (0 != ferror(in)) {
                LOG("read file failed: %s", strerror(errno));
                return false;
            }
            break;
        }

        // decode
        std::string base64(inBuf, tmp);
        std::vector<uint8_t> outVec;
        if (!encrypt_kit::base64Decode(base64, outVec)) {
            LOG("base64 decode failed!");
            return false;
        }

        // decrypt
        std::vector<uint8_t> decrypt;
        if (!encrypt_kit::rsaDecrypt(priKey, outVec.data(), outVec.size(), decrypt)) {
            LOG("rsa decrypt failed!");
            return false;
        }

        // write
        fwrite(decrypt.data(), decrypt.size(), 1, out);

        if (tmp < blocksize) {
            break;
        }
    }

    return true;
}

bool doEncrypAndEncode(FILE* in, FILE* out) {
    std::vector<uint8_t> pubKey;
    std::string pubStr =
            "-----BEGIN PUBLIC KEY-----\n"
            "MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDKyE8Cyf3gdkg+fgRt+g9riF+w\n"
            "W1JTC9l9QYHUypfLpBelBTdJ/F6pW0WlX/J9IFIcmhXcngz2O9argZetho4r2xOu\n"
            "lzRciBbY1LMllwn2B7Z3Ev3MiKJR2RxxibdyS4zxX9V4OAVM+HfmQxOIIEfGwVlS\n"
            "0iCl39KGtUudxcQStwIDAQAB\n"
            "-----END PUBLIC KEY-----\n";
    pubKey.resize(pubStr.size());
    memcpy(pubKey.data(), pubStr.data(), pubKey.size());



    constexpr size_t blocksize = 1024;
    char inBuf[blocksize];
    while (true) {
        // read block
        size_t tmp = fread(inBuf, 1, blocksize, in);
        if (tmp == 0) {
            if (0 != ferror(in)) {
                LOG("read file failed: %s", strerror(errno));
                return false;
            }
            break;
        }

        // encrypt
        std::vector<uint8_t> enVec;
        if (!encrypt_kit::rsaEncrypt(pubKey, inBuf, tmp, enVec)) {
            LOG("rsa encrypt failed!");
            return false;
        }

        // to base64
        std::string base64;
        if (!encrypt_kit::base64Encode(enVec.data(), enVec.size(), base64)) {
            LOG("base64 encode failed!");
            return false;
        }

        // write
        fwrite(base64.data(), base64.size(), 1, out);

        if (tmp < blocksize) {
            break;
        }
    }

    return true;
}

int main(int argc, char *argv[])
{
    AppArg_t arg;
    if (0 != parseArgs(argc, argv, arg)) {
        return -1;
    }

    if (arg.input.empty() || arg.output.empty()) {
        printUsage(argv[0]);
        return -1;
    }

    if (arg.input == arg.output) {
        LOG("input file and output file is the same file");
        return -1;
    }

    FILE* in = fopen(arg.input.c_str(), "rb");
    if (nullptr == in) {
        LOG("open file failed: %s", strerror(errno));
        return -1;
    }
    FILE* out = fopen(arg.output.c_str(), "w+");
    if (nullptr == out) {
        LOG("open file failed: %s", strerror(errno));
        fclose(in);
        in = nullptr;
        return -1;
    }

    bool rv;
    if (arg.type == "encrypt") {
        rv = doEncrypAndEncode(in, out);
    } else if (arg.type == "decrypt") {
        rv = doDecodeAndDecrypt(in, out);
    } else {
        printUsage(argv[0]);
        rv = false;
    }

    fclose(in);
    in = nullptr;
    fclose(out);
    out = nullptr;

    if (!rv) {
        remove(arg.output.c_str());
    }

    return 0;
}
