#-------------------------------------------------
#
# Project created by QtCreator 2018-11-13T14:07:13
#
#-------------------------------------------------

QT       -= core gui

TARGET = EncryptKit
TEMPLATE = lib
CONFIG += staticlib

include (../public.pri)
DESTDIR = $$VAR_LIBSDIR


include (src/src.pri)
include (inc/inc.pri)
