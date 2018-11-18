#ifndef LIENCEKIT_H
#define LIENCEKIT_H

#include <string>
#include <vector>

class LienceKit
{
public:
    LienceKit();
    bool createLienceFile(const char* path);
    bool isLienceFileVaild(const char* path);

private:
    std::string encrypt(const char *data, size_t len);
    std::string decrypt(const std::string &key);
    std::string createRuleString();
    bool isRuleStringValid(const std::string &rule);
    std::string createFullKeyString();
    bool isKeyValid(const std::string &key);

private:
    std::vector<uint8_t> m_publicKey;
    std::vector<uint8_t> m_privateKey;
};

#endif // LIENCEKIT_H
