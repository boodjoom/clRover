QT += core
QT -= gui

CONFIG += c++11

TARGET = clRover
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    commander.cpp \
    fakeapp.cpp

HEADERS += \
    commander.h \
    fakeapp.h

INCLUDEPATH += ../RoboBody

win32 {
LIBS += ../build-RoboBody-Qt_5_5_1_MinGW_32bit-Debug/debug/RoboBody.dll
}

unix {
LIBS += -L../RoboBody
LIBS += -lRoboBody
}

DISTFILES += \
    rover.ini
