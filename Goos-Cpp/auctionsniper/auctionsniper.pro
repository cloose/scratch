#-------------------------------------------------
#
# Project created by QtCreator 2013-11-06T11:23:34
#
#-------------------------------------------------

QT       += core gui widgets network

TARGET = auctionsniper
TEMPLATE = app

SOURCES += main.cpp

HEADERS  +=

FORMS    +=

##################################################
# Use internal static library: auctionsniper-ui
##################################################
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../auctionsniper-ui/release/ -lauctionsniper-ui
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../auctionsniper-ui/debug/ -lauctionsniper-ui
else:unix: LIBS += -L$$OUT_PWD/../auctionsniper-ui/ -lauctionsniper-ui

INCLUDEPATH += $$PWD/../auctionsniper-ui
DEPENDPATH += $$PWD/../auctionsniper-ui

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../auctionsniper-ui/release/libauctionsniper-ui.a
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../auctionsniper-ui/debug/libauctionsniper-ui.a
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../auctionsniper-ui/libauctionsniper-ui.a

##################################################
# Use external shared library: qxmpp
##################################################
LIBS += -L$$QXMPP_LIB
CONFIG(release, debug|release): LIBS += -lqxmpp0
CONFIG(debug, debug|release): LIBS += -lqxmpp_d0

INCLUDEPATH += $$QXMPP_INCLUDE/base $$QXMPP_INCLUDE/client $$QXMPP_INCLUDE/server
DEPENDPATH += $$QXMPP_INCLUDE/base $$QXMPP_INCLUDE/client $$QXMPP_INCLUDE/server
