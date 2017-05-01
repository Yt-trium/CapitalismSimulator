TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    csproducer.c \
    ../CSCommon/types.c \
    ../CSCommon/log.c \
    csproducer_rpc.c

HEADERS += \
    csproducer.h \
    ../CSCommon/define.h \
    ../CSCommon/types.h \
    ../CSCommon/log.h

LIBS += -lrpcsvc -lnsl
