#ifndef LIENCEKIT_H
#define LIENCEKIT_H

#include <string>

typedef struct {
    std::string cpuid;
    std::string vendor;
    std::string brand;
    std::string mac;
} MachineInfo_t;

class LienceCreator;
class LienceValidator;
class LienceKit
{
public:
    LienceKit();
    ~LienceKit();
    bool createLienceFile(const char* path, uint16_t days = 0,
                          MachineInfo_t* info = nullptr);
    bool isLienceFileVaild(const char* path);

private:
    LienceCreator* _c;
    LienceValidator* _v;
};



#endif // LIENCEKIT_H
