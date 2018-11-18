#ifndef CPUTOOL_H
#define CPUTOOL_H

#include <string>

namespace cpu_tool {

typedef struct {
    std::string vendor;
    std::string brand;
    std::string guid;
} CpuInfo_t;

void getCpuInfo(CpuInfo_t& info);

} // namespace cpu_tool

#endif // CPUTOOL_H
