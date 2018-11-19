TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

include (../public.pri)
DESTDIR = $$VAR_BINDIR

SOURCES += main.cpp

INCLUDEPATH += ../EncryptKit/inc/
LIBS += -L$$VAR_LIBSDIR -lEncryptKit

win32 {
    PRE_TARGETDEPS += $$VAR_LIBSDIR/EncryptKit.lib
    LIBS += -ladvapi32 -luser32
}
unix {
    PRE_TARGETDEPS += $$VAR_LIBSDIR/libEncryptKit.a
    LIBS += -lpthread
}
