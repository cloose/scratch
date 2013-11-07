#-------------------------------------------------
#
# Project created by QtCreator 2013-11-06T15:51:20
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = xmpp-server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

##################################################
# Use external shared library: qxmpp
##################################################
LIBS += -L$$QXMPP_LIB
CONFIG(release, debug|release): LIBS += -lqxmpp0
CONFIG(debug, debug|release): LIBS += -lqxmpp_d0

INCLUDEPATH += $$QXMPP_INCLUDE/base $$QXMPP_INCLUDE/client $$QXMPP_INCLUDE/server
DEPENDPATH += $$QXMPP_INCLUDE/base $$QXMPP_INCLUDE/client $$QXMPP_INCLUDE/server
