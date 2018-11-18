CONFIG(debug, debug|release) {
    UI_DIR      = ./tmp/debug/ui
    MOC_DIR     = ./tmp/debug/moc
    OBJECTS_DIR = ./tmp/debug/obj
} else:CONFIG(release, debug|release) {
    UI_DIR      = ./tmp/release/ui
    MOC_DIR     = ./tmp/release/moc
    OBJECTS_DIR = ./tmp/release/obj
}

CONFIG += debug_and_release
CONFIG += c++11

# release 下生成调试信息
# mingws
win32:win32-g++:CONFIG(release, debug|release) {
    QMAKE_CXXFLAGS_RELEASE += -O0 -g
    QMAKE_CFLAGS_RELEASE += -O0 -g
    #QMAKE_LFLAGS_RELEASE +=
}

win32:!win32-g++:CONFIG(release, debug|release) { # msvc
    QMAKE_CXXFLAGS_RELEASE += /Zi
    QMAKE_CFLAGS_RELEASE += /Od
    QMAKE_LFLAGS_RELEASE += /DEBUG
}

unix:CONFIG(release, debug|release) { # unix gcc
    QMAKE_CXXFLAGS_RELEASE += -O0 -g
    QMAKE_CFLAGS_RELEASE += -O0 -g
    #QMAKE_LFLAGS_RELEASE +=
}

VAR_DISTDIR=$$PWD/../dist

CONFIG(debug, debug|release) {
  VAR_BINDIR    = $$VAR_DISTDIR/debug
  VAR_LIBSDIR   = $$VAR_DISTDIR/debug/libs
  VAR_PLUGINDIR = $$VAR_DISTDIR/debug/plugins
} else: CONFIG(release, debug|release) {
  VAR_BINDIR    = $$VAR_DISTDIR/release
  VAR_LIBSDIR   = $$VAR_DISTDIR/release/libs
  VAR_PLUGINDIR = $$VAR_DISTDIR/release/plugins
}
