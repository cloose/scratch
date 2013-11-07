QT += gui widgets network testlib

# make check
CONFIG += testcase

HEADERS += \
    auctionsniperendtoendtest.h \
    fakeauctionserver.h \
    applicationrunner.h \
    auctionsniperdriver.h

SOURCES += \
    auctionsniperendtoendtest.cpp \
    main.cpp \
    fakeauctionserver.cpp \
    applicationrunner.cpp \
    auctionsniperdriver.cpp

##################################################
# Use internal static library: auctionsniper-ui
##################################################
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../auctionsniper-ui/release/ -lauctionsniper-ui
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../auctionsniper-ui/debug/ -lauctionsniper-ui
else:unix: LIBS += -L$$OUT_PWD/../../auctionsniper-ui/ -lauctionsniper-ui

INCLUDEPATH += $$PWD/../../auctionsniper-ui
DEPENDPATH += $$PWD/../../auctionsniper-ui

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../auctionsniper-ui/release/libauctionsniper-ui.a
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../auctionsniper-ui/debug/libauctionsniper-ui.a
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../auctionsniper-ui/libauctionsniper-ui.a

##################################################
# Use external shared library: qxmpp
##################################################
LIBS += -L$$QXMPP_LIB
CONFIG(release, debug|release): LIBS += -lqxmpp0
CONFIG(debug, debug|release): LIBS += -lqxmpp_d0

INCLUDEPATH += $$QXMPP_INCLUDE/base $$QXMPP_INCLUDE/client $$QXMPP_INCLUDE/server
DEPENDPATH += $$QXMPP_INCLUDE/base $$QXMPP_INCLUDE/client $$QXMPP_INCLUDE/server
