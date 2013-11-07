#include "applicationrunner.h"

#include <QtTest/QtTest>

#include <mainwindow.h>

#include "auctionsniperdriver.h"
#include "fakeauctionserver.h"

#define XMPP_HOSTNAME   "localhost"
#define SNIPER_ID       "sniper"
#define SNIPER_PASSWORD "sniper"


ApplicationRunner::ApplicationRunner() :
    driver(0)
{
}

void ApplicationRunner::startBiddingIn(FakeAuctionServer *auction)
{
    MainWindow *w = new MainWindow(XMPP_HOSTNAME, SNIPER_ID, SNIPER_PASSWORD, auction->itemId());
    w->show();

    QTest::qWaitForWindowActive(w, 1000);

    driver = new AuctionSniperDriver(MAIN_WINDOW_NAME);
    driver->showsSniperStatus("Joining");
}

void ApplicationRunner::hasShownSniperHasLostAuction()
{
    driver->showsSniperStatus("Lost");
}

void ApplicationRunner::stop()
{
    delete driver;
}
