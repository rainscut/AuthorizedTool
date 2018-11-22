#ifndef LIENCECREATOR_H
#define LIENCECREATOR_H

#include <string>
#include <vector>

#include "LienceKit.h"

class LienceCreator
{
public:
    LienceCreator();
    bool create(const char* path, MachineInfo_t *info = nullptr, uint16_t days = 0);

private:
    std::string encrypt(const void *data, size_t len);
    void createRule(char *buff, size_t len);

private:
    std::vector<uint8_t> m_publicKey;

};

#endif // LIENCECREATOR_H
