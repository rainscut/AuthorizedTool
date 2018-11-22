#ifndef CPUTOOL_H
#define CPUTOOL_H

#include <string>

namespace util {
namespace machine {

typedef struct {
    std::string vendor;
    std::string brand;
    std::string guid;
} CpuInfo_t;

void getCpuInfo(CpuInfo_t& info);
bool getMacInfo(std::string& mac);

} // namespace machine
} // namespace util

#endif // CPUTOOL_H
