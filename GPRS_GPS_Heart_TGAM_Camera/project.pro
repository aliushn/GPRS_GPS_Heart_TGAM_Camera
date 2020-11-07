#-------------------------------------------------
#
# Project created by QtCreator 2019-03-13T13:41:43
#
#-------------------------------------------------


QT       += core gui
QT       += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project
TEMPLATE = app
OR
CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11
SOURCES += main.cpp\
        mywidget.cpp \
    gps.cpp \
    gprs.cpp \
    data.cpp \
    login.cpp \
    camera.cpp \
    heart.cpp \
    tgam.cpp

HEADERS  += mywidget.h \
    login.h

FORMS    += mywidget.ui \
    login.ui




DISTFILES += \
    yawn_and_pupilla_detection.py \
    call.py

RESOURCES += \
    images.qrc


INCLUDEPATH += C:/Python35-32/include
LIBS += C:/Python35-32/libs/python35.lib





