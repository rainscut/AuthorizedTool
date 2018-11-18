#include "Auth.h"
#include "botan_all.h"

Auth::Auth()
{
}

bool Auth::rsaCreateKey(const char *pubKeyFile, const char *priKeyFile)
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

bool Auth::rsaEncrypt(const char *pubKeyFile, const char *inputAddr,
                      size_t inputLen, char *outputAddr, size_t& maxOutputLen)
{
    try {
        Botan::AutoSeeded_RNG rng;
        Botan::X509_PublicKey* temp_pub = Botan::X509::load_key(pubKeyFile);
        Botan::PK_Encryptor_EME enc(*temp_pub, "EME1(SHA-256)");
        Botan::SecureVector<Botan::byte> en = enc.encrypt((uint8_t*)inputAddr, inputLen, rng);

        if (en.size() > maxOutputLen) {
            return false;
        }

        maxOutputLen = en.size();
        for (size_t i=0; i<maxOutputLen; i++) {
            outputAddr[i] = en[i];
        }

        return true;
    } catch (Botan::Exception &e) {
        printf("%s\n", e.what());
        return false;
    }
}

bool Auth::rsaDecrypt(const char *priKeyFile, const char *inputAddr,
                      size_t inputLen, char *outputAddr, size_t &maxOutputLen)
{
    try {
        Botan::AutoSeeded_RNG rng;
        Botan::PKCS8_PrivateKey* temp_pri = Botan::PKCS8::load_key(priKeyFile, rng);
        Botan::PK_Decryptor_EME dec(*temp_pri, "EME1(SHA-256)");
        Botan::SecureVector<Botan::byte> temp_mem;
        temp_mem.resize(inputLen);

        uint8_t* in = (uint8_t*)inputAddr;
        for(int i = 0; i < inputLen; ++i){
            temp_mem[i] = in[i];
        }

        Botan::SecureVector<Botan::byte> re = dec.decrypt(temp_mem, temp_mem.size());
        if (re.size() > maxOutputLen) {
            return false;
        }

        maxOutputLen = re.size();
        for (size_t i=0; i<maxOutputLen; i++) {
            outputAddr[i] = re[i];
        }
        return true;
    } catch (Botan::Exception &e) {
        printf("%s\n", e.what());
        return false;
    }
}

bool Auth::base64Encode(const char *addr, size_t size, std::string &output)
{
    try {
        output = Botan::base64_encode((const uint8_t*)addr, size);
        return true;
    } catch (Botan::Exception &e) {
        printf("%s\n", e.what());
        return false;
    }
}

bool Auth::base64Decode(const std::string &str, char* output)
{
    try {
        Botan::base64_decode((uint8_t*)output, str);
        return true;
    } catch (Botan::Exception &e) {
        printf("%s\n", e.what());
        return false;
    }
}

bool Auth::createFileWithContent(const char *path, const std::string &content)
{
    FILE* fp = fopen(path, "w+");
    if (nullptr == fp) {
        return false;
    }
    int rv = fwrite(content.c_str(), content.size(), 1, fp);
    fflush(fp);
    fclose(fp);
    return 1 == rv;
}
