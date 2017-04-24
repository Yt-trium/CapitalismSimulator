TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    csproducer.c

HEADERS += \
    csproducer.h \
    ../CSCommon/define.h

LIBS += -lrpcsvc -lnsl
