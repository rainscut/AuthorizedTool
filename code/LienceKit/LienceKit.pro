#-------------------------------------------------
#
# Project created by QtCreator 2018-11-18T17:57:42
#
#-------------------------------------------------

QT       -= core gui

TARGET = LienceKit
TEMPLATE = lib
CONFIG += staticlib

include (../public.pri)
DESTDIR = $$VAR_LIBSDIR


include (src/src.pri)
include (inc/inc.pri)

include (../EncryptKit/inc/inc.pri)
include (../EncryptKit/src/src.pri)
