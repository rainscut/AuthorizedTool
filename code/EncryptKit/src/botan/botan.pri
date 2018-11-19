win32 {
INCLUDEPATH += $$PWD/msvc
DEPENDPATH += $$PWD/msvc

HEADERS += \
    $$PWD/msvc/botan_all.h \
    $$PWD/msvc/botan_all_internal.h

SOURCES += \
    $$PWD/msvc/botan_all.cpp
}

unix {
INCLUDEPATH += $$PWD/gcc
DEPENDPATH += $$PWD/gcc

HEADERS += \
    $$PWD/gcc/botan_all.h \
    $$PWD/gcc/botan_all_internal.h

SOURCES += \
    $$PWD/gcc/botan_all.cpp
}



DEFINES += BOTAN_DLL=

win32 {
    LIBS += -ladvapi32 -luser32
}
