#ifndef COMMON_H
#define COMMON_H

#include <time.h>

#ifndef QT_NO_DEBUG
// debug mode
# define LOG(f, ...) do{\
    printf(f, ##__VA_ARGS__);\
    printf("\n");\
    }while(0)
#else
// release mode
# define LOG(format, ...)
#endif

#endif // COMMON_H
