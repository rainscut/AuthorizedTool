#include "CpuTool.h"
#include <stdio.h>
#include <array>
#include <vector>
#include <string>
#include <string.h>

#ifdef _WIN32
#include <intrin.h>
#endif

#ifdef __linux__
# include <cpuid.h>
# include <arpa/inet.h>
#endif

namespace cpu_tool {

static void get_cpuinfo(unsigned int ext, unsigned int out[]) {
#ifdef __linux__
    __get_cpuid(ext, out, out+1, out+2, out+3);
#endif

#ifdef _WIN32
    __cpuid(out, ext);
#endif
}

void getCpuInfo(CpuInfo_t &info)
{
    unsigned int cpui[4] = {};

    // Capture vendor string
    get_cpuinfo(0x00, cpui);
    char vendor[0x20] = {};
    memset(vendor, 0, sizeof(vendor));
    *reinterpret_cast<int*>(vendor) = cpui[1];
    *reinterpret_cast<int*>(vendor + 4) = cpui[3];
    *reinterpret_cast<int*>(vendor + 8) = cpui[2];
    info.vendor = vendor;

    char cpuStrBuf[32] = {};
    get_cpuinfo(0x01, cpui);
#ifdef __linux__
    sprintf(cpuStrBuf, "%08X", ntohl(cpui[0]));
    sprintf(cpuStrBuf + 8, "%08X", ntohl(cpui[3]));
#endif

#ifdef _WIN32
    sprintf(cpuStrBuf, "%08X", cpui[3]);
    sprintf(cpuStrBuf + 8, "%08X", cpui[0]);
#endif
    info.guid = std::string(cpuStrBuf);

    get_cpuinfo(0x80000000, cpui);
    unsigned int maxIDs = cpui[0];
    if (maxIDs >= 0x80000004) {
        char brand[64] = {};
        int off = 0;
        for (unsigned int i=0x80000002; i<=0x80000004; i++) {
            get_cpuinfo(i, cpui);
            memcpy(brand+off, cpui, sizeof(cpui));
            off += sizeof(cpui);
        }
        info.brand = brand;
    }
}

}
