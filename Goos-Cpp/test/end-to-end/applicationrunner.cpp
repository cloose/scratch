#include "applicationrunner.h"

#include <QtTest/QtTest>

#include <mainwindow.h>

#include "auctionsniperdriver.h"
#include "fakeauctionserver.h"

#define XMPP_HOSTNAME   "localhost"
#define SNIPER_ID       "sniper"
#define SNIPER_PASSWORD "sniper"


ApplicationRunner::ApplicationRunner() :
    driver(0),
    window(0)
{
}

void ApplicationRunner::startBiddingIn(FakeAuctionServer *auction)
{
    window = new MainWindow(XMPP_HOSTNAME, SNIPER_ID, SNIPER_PASSWORD, auction->itemId());
    window->show();

    QTest::qWaitForWindowActive(window, 1000);

    driver = new AuctionSniperDriver(MAIN_WINDOW_NAME);
    driver->showsSniperStatus("Joining");
}

void ApplicationRunner::hasShownSniperIsBidding()
{
    driver->showsSniperStatus("Bidding");
}

void ApplicationRunner::hasShownSniperHasLostAuction()
{
    driver->showsSniperStatus("Lost");
}

void ApplicationRunner::stop()
{
    delete driver;

    window->close();
    window->deleteLater();
}
