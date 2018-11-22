#ifndef LIENCEVALIDATOR_H
#define LIENCEVALIDATOR_H

#include <string>
#include <vector>

#include "common.h"

class LienceValidator
{
public:
    LienceValidator();
    bool isVaild(const char* path);

private:
    size_t decrypt(const std::string &key, void **p);
    bool isRuleValid(const void *d, size_t len);
    bool isLienceValid();

private:
    std::vector<uint8_t> m_privateKey;
    LienceInfo_t m_lience;
};

#endif // LIENCEVALIDATOR_H
