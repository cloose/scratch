#include "auctionsniperendtoendtest.h"

#include <QtTest/QtTest>

#include "applicationrunner.h"
#include "fakeauctionserver.h"


void AuctionSniperEndToEndTest::initTestCase()
{
    auction = new FakeAuctionServer("item-54321");
    application = new ApplicationRunner();
}

void AuctionSniperEndToEndTest::sniperJoinsAuctionUntilAuctionCloses()
{
    auction->startSellingItem();
    application->startBiddingIn(auction);
    auction->hasReceivedJoinRequestFromSniper();
    auction->announceClosed();
    application->hasShownSniperHasLostAuction();
}

void AuctionSniperEndToEndTest::cleanupTestCase()
{
    auction->stop();
    application->stop();
}
