TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    log.c \
    types.c

HEADERS += \
    define.h \
    types.h \
    log.h

DISTFILES += \
    ../LICENSE \
    ../README.md \
    ../makefile
