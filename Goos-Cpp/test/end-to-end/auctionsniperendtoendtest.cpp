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
    auction->hasReceivedJoinRequestFrom("sniper@localhost/Auction");
    auction->announceClosed();
    application->hasShownSniperHasLostAuction();

    after();
}

void AuctionSniperEndToEndTest::sniperMakesAHigherBidButLoses()
{
    auction->startSellingItem();

    application->startBiddingIn(auction);
    auction->hasReceivedJoinRequestFrom("sniper@localhost/Auction");

    auction->reportPrice(1000, 98, "other bidder");
    application->hasShownSniperIsBidding();

    auction->hasReceivedBid(1098, "sniper@localhost/Auction");

    auction->announceClosed();
    application->hasShownSniperHasLostAuction();

    after();
}

void AuctionSniperEndToEndTest::cleanupTestCase()
{
    delete application;
    delete auction;
}

void AuctionSniperEndToEndTest::after()
{
    auction->stop();
    application->stop();
}
