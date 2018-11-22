#-------------------------------------------------
#
# Project created by QtCreator 2018-11-20T16:57:24
#
#-------------------------------------------------

QT       -= core gui

TARGET = LienceValidator
TEMPLATE = lib
CONFIG += staticlib

include (../public.pri)
DESTDIR = $$VAR_LIBSDIR

include (inc/inc.pri)
include (src/src.pri)

include (../EncryptKit/inc/inc.pri)
include (../EncryptKit/src/src.pri)

include (../util/util.pri)
