TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    cscoordinator.c \
    ../CSCommon/types.c \
    ../CSCommon/log.c

HEADERS += \
    cscoordinator.h \
    ../CSCommon/define.h \
    ../CSCommon/types.h \
    ../CSCommon/log.h

LIBS += -lrpcsvc -lnsl
