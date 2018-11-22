#include "UtilMachine.h"
#include <stdio.h>
#include <array>
#include <vector>
#include <string>
#include <string.h>

#ifdef _WIN32
# include <intrin.h>
# include <Windows.h>
# pragma comment(lib, "Netapi32.lib")
#endif

#ifdef __linux__
# include <cpuid.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <net/if.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/socket.h>
#endif

namespace util {
namespace machine {

static void get_cpuinfo(unsigned int ext, unsigned int out[]) {
#ifdef __linux__
    __get_cpuid(ext, out, out+1, out+2, out+3);
#endif

#ifdef _WIN32
    __cpuid((int*)out, ext);
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

bool getMacInfo(std::string &mac)
{
#ifdef __linux__
    mac.clear();

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        return(false);
    }

    struct ifreq ifr = {};
    strncpy(ifr.ifr_name, "eth0", sizeof(ifr.ifr_name) - 1);
    bool ret = (ioctl(sock, SIOCGIFHWADDR, &ifr) >= 0);

    close(sock);

    const char hex[] = {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };
    char macBuf[16] = { 0 };
    for (int index = 0; index < 6; ++index) {
        size_t value = ifr.ifr_hwaddr.sa_data[index] & 0xFF;
        macBuf[2 * index + 0] = hex[value / 16];
        macBuf[2 * index + 1] = hex[value % 16];
    }
    std::string(macBuf).swap(mac);
    return ret;
#else
    // 取得网卡列表
    LANA_ENUM adapterList;
    NCB Ncb;
    memset(&Ncb, 0, sizeof(NCB));
    Ncb.ncb_command = NCBENUM;
    Ncb.ncb_buffer = (unsigned char *)&adapterList;
    Ncb.ncb_length = sizeof(adapterList);
    Netbios(&Ncb);

    // 取得MAC
    for (int i = 0; i < adapterList.length; ++i)
    {
        memset(&Ncb, 0, sizeof(Ncb));
        Ncb.ncb_command = NCBRESET; // 重置网卡，以便我们可以查询
        Ncb.ncb_lana_num = adapterList.lana[i];
        UCHAR rv = Netbios(&Ncb);
        if (rv != NRC_GOODRET) {
            printf("ret=%d\n", rv);
            return false;
        }

        // 准备取得接口卡的状态块
        memset(&Ncb, sizeof(Ncb), 0);
        Ncb.ncb_command = NCBASTAT;
        Ncb.ncb_lana_num =adapterList.lana[i];
        strcpy((char *) Ncb.ncb_callname, "*");

        struct ASTAT{
            ADAPTER_STATUS adapt;
            NAME_BUFFER nameBuff[30];
        } adapter;

        memset(&adapter, sizeof(adapter), 0);
        Ncb.ncb_buffer = (unsigned char *)&adapter;
        Ncb.ncb_length = sizeof(adapter);
        if (Netbios(&Ncb) != 0) {
            continue;
        }

        char acMAC[32] = {};
        sprintf(acMAC, "%02X-%02X-%02X-%02X-%02X-%02X",
                int (adapter.adapt.adapter_address[0]),
                int (adapter.adapt.adapter_address[1]),
                int (adapter.adapt.adapter_address[2]),
                int (adapter.adapt.adapter_address[3]),
                int (adapter.adapt.adapter_address[4]),
                int (adapter.adapt.adapter_address[5]));
        mac = acMAC;

        break;
    }
    return true;
#endif
}

} // namespace machine
} // namespace util
