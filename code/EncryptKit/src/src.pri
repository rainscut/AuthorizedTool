INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS += \
    $$PWD/CpuTool.h

SOURCES += \
    $$PWD/EncryptKit.cpp \
    $$PWD/CpuTool.cpp


include (botan/botan.pri)
