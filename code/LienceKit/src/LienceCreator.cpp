#include "LienceCreator.h"
#include <time.h>
#include <string.h>
#include <chrono>

#include "common.h"
#include "EncryptKit.h"
#include "UtilMachine.h"

static void init_pub_key(std::vector<uint8_t>& key) {
    std::string s31 = "RgCMZ7ITBD822";
    std::string s32 = "5RZNQIDAQAB";
    std::string k4 = s31 + s32 + "\n";

    std::string s11 = "tZIAkV0TgoenIbVHpV3KOV/dh";
    std::string s12 = "284HkTtgczYcWMfh";
    std::string s13 = "PAo0Xr+XpUcmSSxFlVSexHG";
    std::string k2 = s13 + s11 + s12 + "\n";

    std::string s01 = "MIGfMA0GCSqGSIb3DQE";
    std::string s02 = "KDzsZ3Sbg";
    std::string s03 = "BAQUAA4GNADCBiQKBgQDAZ";
    std::string s04 = "u2RqoaxY4GWRiz";
    std::string k1 = s01 + s03 + s02 + s04 + "\n";

    std::string s22 = "UPRgrahqeZxi/hBpB7Styoc";
    std::string s23 = "O/iMjUL+SN4I/5qnCYZ";
    std::string s24 = "RRnT0Qlm92xgS";
    std::string k3 = s23 + s22 + "8MMIlqtGA"+ s24 +" \n";

    std::string s = "-----BEGIN PUBLIC KEY-----\n"
                    + k1 + k2 + k3 + k4
                    + "-----END PUBLIC KEY-----\n";

    // LOG("%s", s.c_str());
    key.resize(s.size());
    memcpy(key.data(), s.data(), key.size());
}

LienceCreator::LienceCreator()
{
    init_pub_key(m_publicKey);
}

bool LienceCreator::create(const char *path, MachineInfo_t* info, uint16_t days)
{
    LienceInfo_t lf;
    if (0 != days) {
        lf.start = time(nullptr);
        lf.end = lf.start + days * 24 * 60 * 60;
    }

    if (nullptr == info) {
        util::machine::CpuInfo_t cpui;
        std::string mac;
        util::machine::getCpuInfo(cpui);
        util::machine::getMacInfo(mac);
        snprintf(lf.mac, sizeof(lf.mac), "%s", mac.c_str());
        snprintf(lf.cpuid, sizeof(lf.cpuid), "%s", cpui.guid.c_str());
        snprintf(lf.brand, sizeof(lf.brand), "%s", cpui.brand.c_str());
        snprintf(lf.vendor, sizeof(lf.vendor), "%s", cpui.vendor.c_str());
    } else {
        snprintf(lf.mac, sizeof(lf.mac), "%s", info->mac.c_str());
        snprintf(lf.cpuid, sizeof(lf.cpuid), "%s", info->cpuid.c_str());
        snprintf(lf.brand, sizeof(lf.brand), "%s", info->brand.c_str());
        snprintf(lf.vendor, sizeof(lf.vendor), "%s", info->vendor.c_str());
    }

    createRule(lf.rule, sizeof(lf.rule));

    std::string content = encrypt(&lf, sizeof(lf));

    FILE* fp = fopen(path, "w+");
    if (nullptr == fp) {
        LOG("open faile failed: %s", strerror(errno));
        return false;
    }

    LOG("lience is: %s", content.c_str());
    fwrite(content.data(), content.size(), 1, fp);
    fclose(fp);
    return true;
}

std::string LienceCreator::encrypt(const void *data, size_t len)
{
    std::vector<uint8_t> out;
    if (!encrypt_kit::rsaEncrypt(m_publicKey, data, len, out)) {
        return "";
    }
    std::string str;
    if (!encrypt_kit::base64Encode(out.data(), out.size(), str)) {
        return "";
    }
    return str;
}

void LienceCreator::createRule(char *buff, size_t len)
{
    /**
     * @brief 总长64字节，4字节为一组
     * 每组中，0+1=2+3
     */
    auto now = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(
                  now.time_since_epoch());
    srand(us.count());
    size_t i = 0;
    while (i < len/4) {
        buff[i+0] = rand() % 256;
        buff[i+1] = rand() % 256;
        buff[i+2] = rand() % 256;
        buff[i+3] = buff[i+0] + buff[i+1] - buff[i+2];
        i += 4;
    }
}
