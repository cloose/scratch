#-------------------------------------------------
#
# Project created by QtCreator 2013-11-20T11:26:28
#
#-------------------------------------------------

QT       -= gui
QT       += testlib

TARGET = hamcrest-qt-core
TEMPLATE = lib

CONFIG += exceptions
#DEFINES += HAMCRESTQTCORE_LIBRARY

SOURCES += description.cpp \
    basedescription.cpp \
    stringdescription.cpp \
    matcherassert.cpp

HEADERS += description.h\
    selfdescribing.h \
    matcher.h \
    basematcher.h \
    isequal.h \
    basedescription.h \
    stringdescription.h \
    matcherassert.h \
    is.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
