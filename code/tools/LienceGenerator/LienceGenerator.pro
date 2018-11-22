TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

include (../../public.pri)
DESTDIR = $$VAR_BINDIR


SOURCES += \
    $$PWD/main.cpp

include (../../util/util.pri)

win32 {
SOURCES += \
    $$PWD/WinGetopt.cpp

HEADERS += \
    $$PWD/WinGetopt.h
}


# libs
INCLUDEPATH += ../../LienceKit/inc/
LIBS += -L$$VAR_LIBSDIR -lLienceKit

win32 {
    LIBS += -ladvapi32 -luser32
    PRE_TARGETDEPS += $$VAR_LIBSDIR/LienceKit.lib
}
unix {
    PRE_TARGETDEPS += $$VAR_LIBSDIR/libLienceKit.a
    LIBS += -lpthread
}

