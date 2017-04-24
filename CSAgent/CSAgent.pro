TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    csagent.c

HEADERS += \
    csagent.h \
    ../CSCommon/define.h

LIBS += -lrpcsvc -lnsl
