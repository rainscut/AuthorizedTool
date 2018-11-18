TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

include (../../public.pri)
DESTDIR = $$VAR_BINDIR

# libs
INCLUDEPATH += ../../LienceKit/inc/
LIBS += -L$$VAR_LIBSDIR -lLienceKit
PRE_TARGETDEPS += $$VAR_LIBSDIR/LienceKit.lib
LIBS += -ladvapi32 -luser32

SOURCES += \
    $$PWD/main.cpp
