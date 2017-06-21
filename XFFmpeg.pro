#-------------------------------------------------
#
# Project created by QtCreator 2017-06-21T13:05:59
#
#-------------------------------------------------

QT       += core gui



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XFFmpeg
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    xffmpeg.cpp \
    videowidget.cpp

HEADERS  += mainwindow.h \
    xffmpeg.h \
    videowidget.h

FORMS    += mainwindow.ui

macx: LIBS += -L$$PWD/../../../../usr/local/Cellar/ffmpeg/3.3.2/lib/ -lavformat

INCLUDEPATH += $$PWD/../../../../usr/local/Cellar/ffmpeg/3.3.2/include
DEPENDPATH += $$PWD/../../../../usr/local/Cellar/ffmpeg/3.3.2/lib

macx: PRE_TARGETDEPS += $$PWD/../../../../usr/local/Cellar/ffmpeg/3.3.2/lib/libavformat.a



macx: LIBS += -L$$PWD/../../../../usr/local/Cellar/ffmpeg/3.3.2/lib/ -lswscale

INCLUDEPATH += $$PWD/../../../../usr/local/Cellar/ffmpeg/3.3.2/include
DEPENDPATH += $$PWD/../../../../usr/local/Cellar/ffmpeg/3.3.2/lib

macx: PRE_TARGETDEPS += $$PWD/../../../../usr/local/Cellar/ffmpeg/3.3.2/lib/libswscale.a
