TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    csagent.c \
    ../CSCommon/types.c \
    ../CSCommon/log.c \
    csagentia.c \
    csagent_rpc.c

HEADERS += \
    csagent.h \
    ../CSCommon/define.h \
    ../CSCommon/types.h \
    ../CSCommon/log.h

LIBS += -lrpcsvc -lnsl
