#ifndef COMMON_H
#define COMMON_H

#include <time.h>

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

#pragma pack(push,1)
typedef struct {
    time_t start = 0;        // 授权时间
    time_t end = 0;          // 授权结束时间
    char mac[32] = {};       //
    char cpuid[32] = {};     //
    char vendor[32] = {};    // cpu供应商
    char brand[64] = {};     // cpu型号
    char rule[64] = {};      // 随机规则串
} LienceInfo_t;
#pragma pack(pop)

#endif // COMMON_H
