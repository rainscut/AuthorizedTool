INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS += \
    $$PWD/botan_all.h \
    $$PWD/botan_all_internal.h

SOURCES += \
    $$PWD/botan_all.cpp

DEFINES += BOTAN_DLL=

LIBS += -ladvapi32 -luser32
