#ifndef LIENCEVALIDATOR_H
#define LIENCEVALIDATOR_H

#include <time.h>
#include <string>
#include <vector>

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

class LienceValidator
{
public:
    LienceValidator();
    bool isVaild(const char* path);
    time_t authTime() { return m_lience.start; }
    time_t vaildTime() { return m_lience.end; }

private:
    size_t decrypt(const std::string &key, void **p);
    bool isRuleValid(const void *d, size_t len);
    bool isLienceValid();

private:
    std::vector<uint8_t> m_privateKey;
    LienceInfo_t m_lience;
};

#endif // LIENCEVALIDATOR_H
