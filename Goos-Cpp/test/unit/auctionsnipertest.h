#ifndef AUCTIONSNIPERTEST_H
#define AUCTIONSNIPERTEST_H

#include <QObject>

class Auction;
class AuctionSniper;


class AuctionSniperTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();

    void reportsLostWhenAuctionCloses();
    void bidsHigherAndReportsBiddingWhenNewPriceArrives();

    void cleanupTestCase();

private:
    Auction *auction;
    AuctionSniper *sniper;
};

#endif // AUCTIONSNIPERTEST_H
