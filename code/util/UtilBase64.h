#ifndef UTILBASE64_H
#define UTILBASE64_H

#include <iostream>

namespace util {
namespace base64 {
std::string encode(const char* data, size_t len);
size_t decode(const std::string& src, char** outBuf);
size_t decode(const char* data, size_t len, char** outBuf);
} // namespace base64
} // namespace Util


#endif // UTILBASE64_H
