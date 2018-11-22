#include "EncryptKit.h"
#include "botan_all.h"

#include <list>

namespace encrypt_kit {

static bool createFileWithContent(const char *path, const std::string &content)
{
    FILE* fp = fopen(path, "w+");
    if (nullptr == fp) {
        return false;
    }
    size_t rv = fwrite(content.c_str(), content.size(), 1, fp);
    fflush(fp);
    fclose(fp);
    return 1 == rv;
}

bool rsaCreateKey(const char *pubKeyFile, const char *priKeyFile)
{
    try {
        Botan::AutoSeeded_RNG rng;
        Botan::RSA_PrivateKey privateKey(rng, 1024);

        std::string pub = Botan::X509::PEM_encode(privateKey);
        std::string pri = Botan::PKCS8::PEM_encode(privateKey);

        bool rv = true;
        rv &= createFileWithContent(pubKeyFile, pub);
        rv &= createFileWithContent(priKeyFile, pri);

        return rv;
    }  catch (Botan::Exception &e) {
        printf("%s\n", e.what());
        return false;
    }
}

bool rsaEncrypt(const char *pubKeyFile, const void *data,
                size_t len, std::vector<uint8_t>& output)
{
    bool rv = true;
    Botan::X509_PublicKey* temp_pub = nullptr;
    try {
        Botan::AutoSeeded_RNG rng;
        temp_pub = Botan::X509::load_key(pubKeyFile);
        Botan::PK_Encryptor_EME enc(*temp_pub, rng, "EME1(SHA-256)");

        size_t maxBytes = enc.maximum_input_size();
        size_t off = 0;
        size_t outLen = 0;

        std::list< std::vector<uint8_t> > enList;
        while (len > 0) {
            size_t tmpLen = std::min(maxBytes, len);
            enList.push_back(enc.encrypt((uint8_t*)data+off, tmpLen, rng));
            outLen += enList.back().size();
            len -= tmpLen;
            off += tmpLen;
        }

        output.resize(outLen);
        off = 0;
        for (auto itr=enList.begin(); itr!=enList.end(); ++itr) {
            std::vector<uint8_t>& en = *itr;
            memcpy(output.data() + off, en.data(), en.size() * sizeof(uint8_t));
            off += en.size() * sizeof(uint8_t);
        }
    } catch (Botan::Exception &e) {
        printf("%s\n", e.what());
        rv = false;
    }

    if (nullptr != temp_pub) {
        delete temp_pub;
        temp_pub = nullptr;
    }

    return rv;
}

bool rsaEncrypt(const std::vector<uint8_t> &pubkey, const void *data,
                size_t len, std::vector<uint8_t> &output)
{
    bool rv = true;
    Botan::X509_PublicKey* temp_pub = nullptr;
    try {
        Botan::AutoSeeded_RNG rng;
        temp_pub = Botan::X509::load_key(pubkey);
        Botan::PK_Encryptor_EME enc(*temp_pub, rng, "EME1(SHA-256)");

        size_t maxBytes = enc.maximum_input_size();
        size_t off = 0;
        size_t outLen = 0;

        std::list< std::vector<uint8_t> > enList;
        while (len > 0) {
            size_t tmpLen = std::min(maxBytes, len);
            enList.push_back(enc.encrypt((uint8_t*)data+off, tmpLen, rng));
            outLen += enList.back().size();
            len -= tmpLen;
            off += tmpLen;
        }

        output.resize(outLen);
        off = 0;
        for (auto itr=enList.begin(); itr!=enList.end(); ++itr) {
            std::vector<uint8_t>& en = *itr;
            memcpy(output.data() + off, en.data(), en.size() * sizeof(uint8_t));
            off += en.size() * sizeof(uint8_t);
        }
    } catch (Botan::Exception &e) {
        printf("%s\n", e.what());
        rv = false;
    }

    if (nullptr != temp_pub) {
        delete temp_pub;
        temp_pub = nullptr;
    }

    return rv;
}

bool rsaDecrypt(const char *priKeyFile, const void *data,
                size_t len, std::vector<uint8_t>& output)
{
    bool rv = true;
    Botan::PKCS8_PrivateKey* temp_pri = nullptr;
    try {
        Botan::AutoSeeded_RNG rng;
        temp_pri = Botan::PKCS8::load_key(priKeyFile, rng);
        Botan::PK_Decryptor_EME dec(*temp_pri, rng, "EME1(SHA-256)");

        constexpr size_t maxBytes = 128; // 最大解密长度 128
        size_t off = 0;
        size_t outLen = 0;
        std::list< Botan::secure_vector<uint8_t> > reList;
        while (len > 0) {
            size_t tmpLen = std::min(len, maxBytes);
            reList.push_back(dec.decrypt((uint8_t*)data+off, tmpLen));
            outLen += reList.back().size();
            off += tmpLen;
            len -= tmpLen;
        }

        output.resize(outLen);
        off = 0;
        for (auto itr=reList.begin(); itr!=reList.end(); ++itr) {
            Botan::secure_vector<uint8_t>& re = *itr;
            memcpy(output.data() + off, re.data(), re.size() * sizeof(uint8_t));
            off += re.size() * sizeof(uint8_t);
        }
    } catch (Botan::Exception &e) {
        printf("%s\n", e.what());
        rv = false;
    }

    if (nullptr != temp_pri) {
        delete temp_pri;
        temp_pri = nullptr;
    }

    return rv;
}

bool rsaDecrypt(const std::vector<uint8_t> &prikey, const void *data,
                size_t len, std::vector<uint8_t> &output)
{
    bool rv = true;
    Botan::PKCS8_PrivateKey* temp_pri = nullptr;
    try {
        Botan::AutoSeeded_RNG rng;
        Botan::DataSource_Memory source(prikey);
        temp_pri = Botan::PKCS8::load_key(source, rng);
        Botan::PK_Decryptor_EME dec(*temp_pri, rng, "EME1(SHA-256)");

        constexpr size_t maxBytes = 128; // 最大解密长度 128
        size_t off = 0;
        size_t outLen = 0;
        std::list< Botan::secure_vector<uint8_t> > reList;
        while (len > 0) {
            size_t tmpLen = std::min(len, maxBytes);
            reList.push_back(dec.decrypt((uint8_t*)data+off, tmpLen));
            outLen += reList.back().size();
            off += tmpLen;
            len -= tmpLen;
        }

        output.resize(outLen);
        off = 0;
        for (auto itr=reList.begin(); itr!=reList.end(); ++itr) {
            Botan::secure_vector<uint8_t>& re = *itr;
            memcpy(output.data() + off, re.data(), re.size() * sizeof(uint8_t));
            off += re.size() * sizeof(uint8_t);
        }
    } catch (Botan::Exception &e) {
        printf("%s\n", e.what());
        rv = false;
    }

    if (nullptr != temp_pri) {
        delete temp_pri;
        temp_pri = nullptr;
    }

    return rv;
}

bool base64Encode(const void *addr, size_t size, std::string &output)
{
    try {
        output = Botan::base64_encode((const uint8_t*)addr, size);
        return true;
    } catch (Botan::Exception &e) {
        printf("%s\n", e.what());
        return false;
    }
}

bool base64Decode(const std::string &str, std::vector<uint8_t>& output)
{
    try {
        if (0 != str.size() % 4) { // base64 字符串长度必须是4的倍数
            return false;
        }

        auto tmp = Botan::base64_decode(str);
        output.resize(tmp.size());
        memcpy(output.data(), tmp.data(), tmp.size() * sizeof(uint8_t));
        return true;
    } catch (Botan::Exception &e) {
        printf("%s\n", e.what());
        return false;
    }
}

bool md5Hash(const void *data, size_t len, std::string &output)
{
    try {
        Botan::MD5 hash;
        hash.update((uint8_t*)data, len);
        auto tmp = hash.final_stdvec();
        output.resize(tmp.size() * 2 + 1);
        for (size_t i=0; i<tmp.size(); i++) {
            sprintf((char*)output.data()+2*i, "%02x", tmp[i]);
        }
        return true;
    } catch (Botan::Exception &e) {
        printf("%s\n", e.what());
        return false;
    }
}

bool sha256Hash(const void *data, size_t len, std::string &output)
{
    try {
        Botan::SHA_256 hash;
        hash.update((uint8_t*)data, len);
        auto tmp = hash.final_stdvec();
        output.resize(tmp.size() * 2 + 1);
        for (size_t i=0; i<tmp.size(); i++) {
            sprintf((char*)output.data()+2*i, "%02x", tmp[i]);
        }
        return true;
    } catch (Botan::Exception &e) {
        printf("%s\n", e.what());
        return false;
    }
}

bool sha224Hash(const void *data, size_t len, std::string &output)
{
    try {
        Botan::SHA_224 hash;
        hash.update((uint8_t*)data, len);
        auto tmp = hash.final_stdvec();
        output.resize(tmp.size() * 2 + 1);
        for (size_t i=0; i<tmp.size(); i++) {
            sprintf((char*)output.data()+2*i, "%02x", tmp[i]);
        }
        return true;
    } catch (Botan::Exception &e) {
        printf("%s\n", e.what());
        return false;
    }
}






} // namespace encrypt_kit
