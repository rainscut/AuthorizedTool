#include "UtilBase64.h"

#include "base64.h"

namespace util {
namespace base64 {

std::string encode(const char *data, size_t len)
{
    struct base64_context context;
    base64_init(&context, 78);
    int outLen = base64_get_encode_length(&context, (int)len);

    char *buf = new char[outLen+4];
    base64_encode(&context, data, (int)len, buf, &outLen);

    std::string str(buf, outLen);
    delete [] buf;
    buf = nullptr;

    return str;
}

size_t decode(const std::string &src, char **outBuf)
{
    struct base64_context context;
    base64_init(&context, 78);

    int outLen = (int)((src.length()*3+3)>>2) + 1;
    int realOutLen = 0;
    *outBuf = new char[outLen];
    base64_decode(&context, src.c_str(), (int)src.length(), *outBuf, &realOutLen);
    if (0 >= realOutLen)
    {
        realOutLen = 0;
        delete [] *outBuf;
        *outBuf = nullptr;
    }

    return realOutLen;
}

size_t decode(const char *data, size_t len, char **outBuf)
{
    struct base64_context context;
    base64_init(&context, 78);

    int outLen = (int)((len*3+3)>>2) + 1;
    int realOutLen = 0;
    *outBuf = new char[outLen];
    base64_decode(&context, data, (int)len, *outBuf, &realOutLen);
    if (0 >= realOutLen)
    {
        realOutLen = 0;
        delete [] *outBuf;
        *outBuf = nullptr;
    }

    return realOutLen;
}

} // namespace base64
} // namespace Util
