#ifndef APPLICATIONRUNNER_H
#define APPLICATIONRUNNER_H

class AuctionSniperDriver;
class FakeAuctionServer;
class MainWindow;


class ApplicationRunner
{
public:
    ApplicationRunner();

    void startBiddingIn(FakeAuctionServer *auction);
    void hasShownSniperIsBidding();
    void hasShownSniperHasLostAuction();
    void stop();

private:
    AuctionSniperDriver *driver;
    MainWindow *window;
};

#endif // APPLICATIONRUNNER_H
