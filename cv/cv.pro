#-------------------------------------------------
#
# Project created by QtCreator 2016-01-06T15:13:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cv
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    convey.cpp

HEADERS  += mainwindow.h \
    convey.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2
LIBS +=  /usr/local/lib/libopencv_*.so
