#ifndef AUCTIONSNIPERENDTOENDTEST_H
#define AUCTIONSNIPERENDTOENDTEST_H

#include <QObject>

class ApplicationRunner;
class FakeAuctionServer;


class AuctionSniperEndToEndTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();

    void sniperJoinsAuctionUntilAuctionCloses();
    void sniperMakesAHigherBidButLoses();

    void cleanupTestCase();

private:
    void after();

    FakeAuctionServer *auction;
    ApplicationRunner *application;
};

#endif // AUCTIONSNIPERENDTOENDTEST_H
