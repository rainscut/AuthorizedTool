#include "UtilString.h"

namespace util {
namespace string {

std::vector<std::string> split(const std::string &str, char spliter) {
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

} // namespace string
} // namespace util

