#-------------------------------------------------
#
# Project created by QtCreator 2013-11-20T12:52:36
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = basematchertest
CONFIG   += console exceptions
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += basematchertest.cpp \
    main.cpp \
    basedescriptiontest.cpp \
    isequaltest.cpp \
    matcherasserttest.cpp \
    istest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    basematchertest.h \
    basedescriptiontest.h \
    isequaltest.h \
    matcherasserttest.h \
    istest.h \
    abstractmatcher.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../hamcrest-qt-core/release/ -lhamcrest-qt-core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../hamcrest-qt-core/debug/ -lhamcrest-qt-core
else:unix: LIBS += -L$$OUT_PWD/../../hamcrest-qt-core/ -lhamcrest-qt-core

INCLUDEPATH += $$PWD/../../hamcrest-qt-core
DEPENDPATH += $$PWD/../../hamcrest-qt-core
