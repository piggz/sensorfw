QT += dbus network

LIBS += -Wl,-rpath,/usr/lib/sensord,-E

include(../common-install.pri)

TEMPLATE = app
TARGET = sensorchains-test

CONFIG += testcase

HEADERS += chainstest.h \



SOURCES += chainstest.cpp \


INCLUDEPATH += ../.. \
    ../../include \
    ../../chains \
    ../../core \
    ../../chains \    
    ../../adaptors \
    ../../datatypes

QMAKE_LIBDIR_FLAGS += -L../../builddir/datatypes -L../../datatypes/ -lsensordatatypes
QMAKE_LIBDIR_FLAGS += -L../../builddir/core -L../../core/ -lsensorfw
