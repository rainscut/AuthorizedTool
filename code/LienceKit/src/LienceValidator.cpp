#include "LienceValidator.h"

#include <string.h>
#include "common.h"
#include "EncryptKit.h"
#include "UtilMachine.h"

static std::vector<std::string> splitString(const std::string& str, char spliter) {
    std::vector<std::string> rv;
    size_t off = 0;
    while (off < str.size()) {
        size_t pos = str.find(spliter, off);
        if (std::string::npos == pos) {
            rv.push_back(std::string(str.data() + off));
            break;
        } else {
            rv.push_back(std::string(str.data() + off, pos - off));
            off = pos + 1;
        }
    }
    return rv;
}

static void init_pri_key(std::vector<uint8_t>& key) {
    std::string s1;
    std::string s2;
    std::string s3;
    std::string s4;

    s1 = "dPRCWb3bGBJG";
    s2 = "f5CSNdx6CJB7";
    s3 = "MBAAECgYBM9NN2tuDIp9ES";
    s4 = "AIxnshMEPzbblFk1Ag";
    std::string k04 = s1 + s4 + s3 + s2 + "\n";

    s1 = "v5elRyZJLEWVVJ7Ec";
    s2 = "qhrFjgZZGLM8CjRe";
    s3 = "a1kgCRXROCh6chtUelX";
    s4 = "co5X92HbzgeR";
    std::string k02 = s2 + s1 + s3 + s4 + "\n";

    s1 = "EAAoGBAMBkoPO";
    s2 = "kiG9w0BAQEFAASCAmIwggJeAg";
    s3 = "xndJuC7ZG";
    s4 = "MIICeAIBADANBgkqh";
    std::string k01 = s4 + s2 + s1 + s3 + "\n";

    s1 = "wwiWq0YBFG";
    s2 = "5I3gj/mqcJhlQ9GCtqGp";
    s3 = "O2BzNhxYx+E7+IyNQv";
    s4 = "5nGL+EGkHtK3Khzw";
    std::string k03 = s3 + s2 + s4 + s1 + "\n";

    s1 = "JBAOwfvlswV8s7jkMImvhNYDI+M";
    s2 = "B1bYVinlsyHzIAMm/w";
    s3 = "JWASjgLO";
    s4 = "+1aVEwocsxs";
    std::string k07 = s2 + s1 + s4 + s3 + "\n";

    s1 = "pTfBb1Jvbn3iWF";
    s2 = "JdvrAkEAqgSNVzGu9Y";
    s3 = "cDw7Bfus/mNWzrS";
    s4 = "1FDnQ9MYHfN80flqQ";
    std::string k10 = s2 + s1 + s4 + s3 + "\n";

    s1 = "S1+llfr";
    s2 = "ElO3NotidoLYM";
    s3 = "PTRdv1qGx4s+sr09Nh7LhQttjoo9Px";
    s4 = "Ujf1B6pdPCcQK3";
    std::string k05 = s3 + s4 + s2 + s1 + "\n";

    s1 = "LMklT2+rfJPTSQc";
    s2 = "4SpV76/FpRR1ulDVUYNc";
    s3 = "oAAt2PC0Qnsn8Vp";
    s4 = "ItxcLBdTIhOUFL";
    std::string k06 = s1 + s4 + s3 + s2 + "\n";

    s1 = "918CQQDQloYZbJ";
    s2 = "nfqWhH3cz5hcqBLiC8I";
    s3 = "lbedZanZEt";
    s4 = "SJpVuB5LZ13b2L2tTNgQQ";
    std::string k08 = s4 + s2 + s1 + s3 + "\n";

    s1 = "HbwIGaX+";
    s2 = "yrFklpW6CXCiW85k";
    s3 = "IrEGni8yCpqqj29Cjroh";
    s4 = "BIMnKYCsJpLGe8yGA6dU";
    std::string k09 = s3 + s4 + s2 + s1 + "\n";

    s1 = "fa6FXZcUX5pFL1R3yn+";
    s2 = "7KuWC0jVcT9rEDecPAD";
    s3 = "2qR3r6cHehLiKPC32z8n";
    s4 = "+gGtfo";
    std::string k13 = s3 + s2 + s4 + s1 + "\n";

    s1 = "jHj9TNIgWiHnaupnE7KtC5h";
    s2 = "3XY6yNwJBAIS";
    s3 = "6z2nPtoYXbpeGpNM6CeW";
    s4 = "T1+IbA5J/";
    std::string k11 = s1 + s2 + s4 + s3 + "\n";

    s1 = "SEcCQQDT7vqe";
    s2 = "iVodi7JmwtHGcFF7Jvl";
    s3 = "fQIzBj762InBTwhD/";
    s4 = "5QZdId7Cg3wGiVnz";
    std::string k12 = s2 + s3 + s4 + s1 + "\n";

    s1 = "";
    s2 = "DQuV3teP";
    s3 = "";
    s4 = "wY8ZxaEj";
    std::string k14 = s2 + s4 + "\n";

    std::string s = "-----BEGIN PRIVATE KEY-----\n"
            + k01 + k02 + k03 + k04 + k05 + k06 + k07
            + k08 + k09 + k10 + k11 + k12 + k13 + k14
            + "-----END PRIVATE KEY-----\n";

    // LOG("%s", s.c_str());
    key.resize(s.size());
    memcpy(key.data(), s.data(), key.size());
}

LienceValidator::LienceValidator()
{
    init_pri_key(m_privateKey);
}

bool LienceValidator::isVaild(const char *path)
{
    FILE* fp = fopen(path, "rb");
    if (nullptr == fp) {
        LOG("open faile failed: %s", strerror(errno));
        return false;
    }

    std::string content;
    while (true) {
        char buf[1024] = {};
        size_t r = fread(buf, 1, 1024, fp);
        if (r > 0) {
            content += std::string(buf, r);
        }

        if (r < 1024) {
            break;
        }
    }
    fclose(fp);
    fp = nullptr;

    void* p = nullptr;
    size_t len = decrypt(content, &p);
    if (0 == len) {
        return false;
    }

    bool rv = true;
    if (len != sizeof(m_lience)) {
        rv = false;
    } else {
        memcpy(&m_lience, p, sizeof(m_lience));
        rv = isLienceValid();
    }

    free(p);
    p = nullptr;

    return rv;
}

size_t LienceValidator::decrypt(const std::string &key, void** p)
{
    std::vector<uint8_t> out;
    if (!encrypt_kit::base64Decode(key, out)) {
        return 0;
    }

    std::vector<uint8_t> out1;
    if (!encrypt_kit::rsaDecrypt(m_privateKey, out.data(), out.size(), out1)) {
        return 0;
    }

    *p = malloc(out1.size());
    memcpy(*p, out1.data(), out1.size());
    return out1.size();
}

bool LienceValidator::isRuleValid(const void* data, size_t len)
{
    int i = 0;
    uint8_t* d = (uint8_t*)data;
    while (i < len/4) {
        if ((uint8_t)(d[i+0] + d[i+1]) != (uint8_t)(d[i+2] + d[i+3])) {
            LOG("rule not matched: %d %d %d %d %d", i, d[i+0], d[i+1], d[i+2], d[i+3]);
            return false;
        }
        i += 4;
    }
    return true;
}

bool LienceValidator::isLienceValid()
{
    util::machine::CpuInfo_t cpui;
    std::string mac;
    util::machine::getCpuInfo(cpui);
    util::machine::getMacInfo(mac);

    // 硬件检查
    if ( 0 != strncmp(cpui.guid.c_str(), m_lience.cpuid, sizeof(m_lience.cpuid))
         || 0 != strncmp(cpui.vendor.c_str(), m_lience.vendor, sizeof(m_lience.vendor))
         || 0 != strncmp(cpui.brand.c_str(), m_lience.brand, sizeof(m_lience.brand))
         || 0 != strncmp(mac.c_str(), m_lience.mac, sizeof(m_lience.mac))
         ) {
        return false;
    }

    // 规则检查
    if (!isRuleValid(m_lience.rule, sizeof(m_lience.rule))) {
        return false;
    }

    // 时间检查
    time_t now = time(nullptr);
    if ( m_lience.start > 0 ) {
        if ( now < m_lience.start
             || now > m_lience.end ) {
            return false;
        }
    }

    return true;
}
