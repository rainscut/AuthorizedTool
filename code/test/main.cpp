#include <stdio.h>
#include "EncryptKit.h"
#include <string.h>

void testCpu() {
    std::string id = encrypt_kit::getCpuId();
    printf("cpu id is: %s\n", id.c_str());
}

void testMemRsa() {
    const char* data = "abcdefgadfasdfa889adf98a98d65asd4f684s65adsdf";
    size_t len = strlen(data);

    std::string pub =
            "-----BEGIN PUBLIC KEY-----\n"
            "MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDAZKDzsZ3Sbgu2RqoaxY4GWRiz\n"
            "PAo0Xr+XpUcmSSxFlVSexHGtZIAkV0TgoenIbVHpV3KOV/dh284HkTtgczYcWMfh\n"
            "O/iMjUL+SN4I/5qnCYZUPRgrahqeZxi/hBpB7Styoc8MMIlqtGARRnT0Qlm92xgS\n"
            "RgCMZ7ITBD8225RZNQIDAQAB\n"
            "-----END PUBLIC KEY-----\n";
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

    std::vector<uint8_t> pk;
    pk.resize(pub.size());
    memcpy(pk.data(), pub.data(), pk.size());

    std::vector<uint8_t> vk;
    vk.resize(pri.size());
    memcpy(vk.data(), pri.data(), vk.size());

    std::vector<uint8_t> output;
    encrypt_kit::rsaEncrypt(pk, data, len, output);

    std::vector<uint8_t> output1;
    encrypt_kit::rsaDecrypt(vk, (char*)output.data(), output.size(), output1);

    std::string xx((char*)output1.data(), output1.size());
    printf("raw: %s\n", data);
    printf("new: %s\n", xx.data());
}

int main(int argc, char *argv[])
{
    testCpu();
    testMemRsa();

    const char* pub = "rsa_pub.key";
    const char* pri = "rsa_pri.key";
    if (!encrypt_kit::rsaCreateKey(pub, pri)) {
        printf("create key failed\n");
        return -1;
    }

    if (argc == 1) {
        return 0;
    }
    printf("raw: \"%s\"\n", argv[1]);

    std::string hash;
    encrypt_kit::md5Hash(argv[1], strlen(argv[1]), hash);
    printf("md5: %s\n", hash.c_str());

    encrypt_kit::sha256Hash(argv[1], strlen(argv[1]), hash);
    printf("sha256: %s\n", hash.c_str());

    encrypt_kit::sha224Hash(argv[1], strlen(argv[1]), hash);
    printf("sha224: %s\n", hash.c_str());

    std::vector<uint8_t> env;
    if (!encrypt_kit::rsaEncrypt(pub, argv[1], strlen(argv[1]), env)) {
        printf("encrypt failed\n");
    }

    std::string en;
    encrypt_kit::base64Encode((char*)env.data(), env.size(), en);
    printf("encrypt: len=%zu %s\n", env.size(), en.c_str());

    env.clear();
    encrypt_kit::base64Decode(en, env);

    std::vector<uint8_t> dev;
    if (!encrypt_kit::rsaDecrypt(pri, (char*)env.data(), env.size(), dev)) {
        printf("encrypt failed\n");
    }
    std::string out((char*)dev.data(), dev.size());
    printf("decrypt: \"%s\"\n", out.c_str());

    fflush(stdout);

    return 0;
}
