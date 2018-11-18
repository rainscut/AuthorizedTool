#ifndef AUTH_H
#define AUTH_H

#include <string>
#include <vector>


namespace encrypt_kit {

bool rsaCreateKey(const char* pubKeyFile, const char* priKeyFile);

bool rsaEncrypt(const char* pubKeyFile, const char* data, size_t len, std::vector<uint8_t>& output);
bool rsaDecrypt(const char* priKeyFile, const char* data, size_t len, std::vector<uint8_t>& output);
bool rsaEncrypt(const std::vector<uint8_t>& pubkey, const char* data, size_t len, std::vector<uint8_t>& output);
bool rsaDecrypt(const std::vector<uint8_t>& prikey, const char* data, size_t len, std::vector<uint8_t>& output);

bool md5Hash(const char* data, size_t len, std::string& output);
bool sha224Hash(const char* data, size_t len, std::string& output);
bool sha256Hash(const char* data, size_t len, std::string& output);

bool base64Encode(const char* addr, size_t size, std::string& output);
bool base64Decode(const std::string& str, std::vector<uint8_t> &output);

std::string getCpuId();

} // namespace encrypt_kit

#endif // AUTH_H
