TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

include (../../public.pri)
DESTDIR = $$VAR_BINDIR

SOURCES += main.cpp


# libs
INCLUDEPATH += ../../EncryptKit/inc/
LIBS += -L$$VAR_LIBSDIR -lEncryptKit

win32 {
    LIBS += -ladvapi32 -luser32
    PRE_TARGETDEPS += $$VAR_LIBSDIR/EncryptKit.lib
}
unix {
    PRE_TARGETDEPS += $$VAR_LIBSDIR/libEncryptKit.a
    LIBS += -lpthread
}
