#ifndef AUTH_H
#define AUTH_H

#include <string>
#include <vector>


namespace encrypt_kit {

bool rsaCreateKey(const char* pubKeyFile, const char* priKeyFile);

bool rsaEncrypt(const char* pubKeyFile, const void* data, size_t len, std::vector<uint8_t>& output);
bool rsaDecrypt(const char* priKeyFile, const void* data, size_t len, std::vector<uint8_t>& output);
bool rsaEncrypt(const std::vector<uint8_t>& pubkey, const void* data, size_t len, std::vector<uint8_t>& output);
bool rsaDecrypt(const std::vector<uint8_t>& prikey, const void* data, size_t len, std::vector<uint8_t>& output);

bool md5Hash(const void* data, size_t len, std::string& output);
bool sha224Hash(const void* data, size_t len, std::string& output);
bool sha256Hash(const void* data, size_t len, std::string& output);

bool base64Encode(const void *addr, size_t size, std::string& output);
bool base64Decode(const std::string& str, std::vector<uint8_t> &output);

} // namespace encrypt_kit

#endif // AUTH_H
