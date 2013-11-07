#-------------------------------------------------
#
# Project created by QtCreator 2013-11-06T11:34:12
#
#-------------------------------------------------

QT       += widgets network

TARGET = auctionsniper-ui
TEMPLATE = lib
CONFIG += staticlib

SOURCES += mainwindow.cpp \
    auctionmessagetranslator.cpp

HEADERS += mainwindow.h \
    auctionmessagetranslator.h

FORMS += \
    mainwindow.ui


unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

##################################################
# Use external shared library: qxmpp
##################################################
LIBS += -L$$QXMPP_LIB
CONFIG(release, debug|release): LIBS += -lqxmpp0
CONFIG(debug, debug|release): LIBS += -lqxmpp_d0

INCLUDEPATH += $$QXMPP_INCLUDE/base $$QXMPP_INCLUDE/client $$QXMPP_INCLUDE/server
DEPENDPATH += $$QXMPP_INCLUDE/base $$QXMPP_INCLUDE/client $$QXMPP_INCLUDE/server
