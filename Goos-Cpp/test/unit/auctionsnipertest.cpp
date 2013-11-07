#include "auctionsnipertest.h"

#include <QtTest/QtTest>

#include <auction.h>
#include <auctionsniper.h>

class AuctionMock : public Auction
{
public:
    AuctionMock() : countBidCalled(0), lastAmount(0) {}

    void bid(int amount) { countBidCalled++; lastAmount = amount; }

    int count() const { return countBidCalled; }
    int amount() const { return lastAmount; }

private:
    int countBidCalled;
    int lastAmount;
};


void AuctionSniperTest::initTestCase()
{
    auction = new AuctionMock();
    sniper = new AuctionSniper(auction, this);
}

void AuctionSniperTest::reportsLostWhenAuctionCloses()
{
    QSignalSpy spy(sniper, SIGNAL(sniperLost()));

    sniper->auctionClosed();

    QCOMPARE(spy.count(), 1);
}

void AuctionSniperTest::bidsHigherAndReportsBiddingWhenNewPriceArrives()
{
    int price = 1001;
    int increment = 25;

    QSignalSpy spy(sniper, SIGNAL(sniperBidding()));

    sniper->currentPrice(price, increment);

    QCOMPARE(spy.count(), 1);
    QCOMPARE(((AuctionMock*)auction)->count(), 1);
    QCOMPARE(((AuctionMock*)auction)->amount(), price+increment);
}

void AuctionSniperTest::cleanupTestCase()
{
    delete sniper;
}

