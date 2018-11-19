#include "LienceKit.h"
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>  // max
#include <random>
#include <time.h>
#include <string.h>

#include "EncryptKit.h"

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

LienceKit::LienceKit()
{
    std::string pub =
            "-----BEGIN PUBLIC KEY-----\n"
            "MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDAZKDzsZ3Sbgu2RqoaxY4GWRiz\n"
            "PAo0Xr+XpUcmSSxFlVSexHGtZIAkV0TgoenIbVHpV3KOV/dh284HkTtgczYcWMfh\n"
            "O/iMjUL+SN4I/5qnCYZUPRgrahqeZxi/hBpB7Styoc8MMIlqtGARRnT0Qlm92xgS\n"
            "RgCMZ7ITBD8225RZNQIDAQAB\n"
            "-----END PUBLIC KEY-----\n";
    m_publicKey.resize(pub.size());
    memcpy(m_publicKey.data(), pub.data(), m_publicKey.size());

    std::string pri =
            "-----BEGIN PRIVATE KEY-----\n"
            "MIICeAIBADANBgkqhkiG9w0BAQEFAASCAmIwggJeAgEAAoGBAMBkoPOxndJuC7ZG\n"
            "qhrFjgZZGLM8CjRev5elRyZJLEWVVJ7Eca1kgCRXROCh6chtUelXco5X92HbzgeR\n"
            "O2BzNhxYx+E7+IyNQv5I3gj/mqcJhlQ9GCtqGp5nGL+EGkHtK3KhzwwwiWq0YBFG\n"
            "dPRCWb3bGBJGAIxnshMEPzbblFk1AgMBAAECgYBM9NN2tuDIp9ESf5CSNdx6CJB7\n"
            "PTRdv1qGx4s+sr09Nh7LhQttjoo9PxUjf1B6pdPCcQK3ElO3NotidoLYMS1+llfr\n"
            "LMklT2+rfJPTSQcItxcLBdTIhOUFLoAAt2PC0Qnsn8Vp4SpV76/FpRR1ulDVUYNc\n"
            "B1bYVinlsyHzIAMm/wJBAOwfvlswV8s7jkMImvhNYDI+M+1aVEwocsxsJWASjgLO\n"
            "SJpVuB5LZ13b2L2tTNgQQnfqWhH3cz5hcqBLiC8I918CQQDQloYZbJlbedZanZEt\n"
            "IrEGni8yCpqqj29CjrohBIMnKYCsJpLGe8yGA6dUyrFklpW6CXCiW85kHbwIGaX+\n"
            "JdvrAkEAqgSNVzGu9YpTfBb1Jvbn3iWF1FDnQ9MYHfN80flqQcDw7Bfus/mNWzrS\n"
            "jHj9TNIgWiHnaupnE7KtC5h3XY6yNwJBAIST1+IbA5J/6z2nPtoYXbpeGpNM6CeW\n"
            "iVodi7JmwtHGcFF7JvlfQIzBj762InBTwhD/5QZdId7Cg3wGiVnzSEcCQQDT7vqe\n"
            "2qR3r6cHehLiKPC32z8n7KuWC0jVcT9rEDecPAD+gGtfofa6FXZcUX5pFL1R3yn+\n"
            "DQuV3tePwY8ZxaEj\n"
            "-----END PRIVATE KEY-----\n";
    m_privateKey.resize(pri.size());
    memcpy(m_privateKey.data(), pri.data(), m_privateKey.size());
}

bool LienceKit::createLienceFile(const char *path)
{
    std::string key = createFullKeyString();
    std::string content = encrypt(key.data(), key.size());

    FILE* fp = fopen(path, "w+");
    if (nullptr == fp) {
        return false;
    }

    fwrite(content.data(), content.size(), 1, fp);
    fclose(fp);
    return true;
}

bool LienceKit::isLienceFileVaild(const char *path)
{
    FILE* fp = fopen(path, "rb");
    if (nullptr == fp) {
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

    std::string key = decrypt(content);
    if (!isKeyValid(key)) {
        return false;
    }

    return true;
}

std::string LienceKit::encrypt(const char* data, size_t len) {
    std::vector<uint8_t> out;
    if (!encrypt_kit::rsaEncrypt(m_publicKey, data, len, out)) {
        return "";
    }
    std::string str;
    if (!encrypt_kit::base64Encode((char*)out.data(), out.size(), str)) {
        return "";
    }
    return str;
}

std::string LienceKit::decrypt(const std::string& key) {
    std::vector<uint8_t> out;
    if (!encrypt_kit::base64Decode(key, out)) {
        return "";
    }

    std::vector<uint8_t> out1;
    if (!encrypt_kit::rsaDecrypt(m_privateKey, (char*)out.data(), out.size(), out1)) {
        return "";
    }
    return std::string((char*)out1.data(), out1.size());
}

std::string LienceKit::createRuleString() {
    /**
     * @brief 总长64字节，4字节为一组
     * 每组中，0+1=2+3
     */
    srand((int)time(nullptr));
    std::vector<uint8_t> buff;
    buff.resize(64);
    int i = 0;
    while (i < 64/4) {
        buff[i+0] = rand() % 256;
        buff[i+1] = rand() % 256;
        buff[i+2] = rand() % 256;
        buff[i+3] = buff[i+0] + buff[i+1] - buff[i+2];
        i += 4;
    }
    std::string rule;
    encrypt_kit::base64Encode((char*)buff.data(), buff.size(), rule);
    return rule;
}

bool LienceKit::isRuleStringValid(const std::string& rule) {
    std::vector<uint8_t> out;
    if (!encrypt_kit::base64Decode(rule, out)) {
        return false;
    }
    if (64 != out.size()) {
        return false;
    }
    int i = 0;
    while (i < 64/4) {
        if (out[i+0] + out[i+1] != out[i+2] + out[i+3]) {
            return false;
        }
        i += 4;
    }
    return true;
}

std::string LienceKit::createFullKeyString() {
    // cpuid;rule
    std::string cpuid = encrypt_kit::getCpuId();
    std::string rule = createRuleString();
    return cpuid + ";" + rule;
}

bool LienceKit::isKeyValid(const std::string& key) {
    std::vector<std::string> values = splitString(key, ';');
    if (values.size() != 2) {
        return false;
    }

    std::string cpuid = encrypt_kit::getCpuId();
    if (cpuid != values[0]) {
        return false;
    }

    if (!isRuleStringValid(values[1])) {
        return false;
    }

    return true;
}

