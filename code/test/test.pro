TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

include (../public.pri)
DESTDIR = $$VAR_BINDIR

SOURCES += main.cpp

INCLUDEPATH += ../LienceValidator/inc/
LIBS += -L$$VAR_LIBSDIR -lLienceValidator

win32 {
    PRE_TARGETDEPS += $$VAR_LIBSDIR/LienceValidator.lib
    LIBS += -ladvapi32 -luser32
}
unix {
    PRE_TARGETDEPS += $$VAR_LIBSDIR/libLienceValidator.a
    LIBS += -lpthread
}
