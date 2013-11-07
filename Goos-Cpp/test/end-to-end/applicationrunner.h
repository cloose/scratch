#ifndef APPLICATIONRUNNER_H
#define APPLICATIONRUNNER_H

class AuctionSniperDriver;
class FakeAuctionServer;


class ApplicationRunner
{
public:
    ApplicationRunner();

    void startBiddingIn(FakeAuctionServer *auction);
    void hasShownSniperHasLostAuction();
    void stop();

private:
    AuctionSniperDriver *driver;
};

#endif // APPLICATIONRUNNER_H
