#ifndef AUCTIONSNIPER_H
#define AUCTIONSNIPER_H

#include <QObject>

class Auction;


class AuctionSniper : public QObject
{
    Q_OBJECT
public:
    explicit AuctionSniper(Auction *auction, QObject *parent = 0);
    
signals:
    void sniperBidding();
    void sniperLost();

public slots:
    void auctionClosed();
    void currentPrice(int price, int increment);

private:
    Auction *auction;
};

#endif // AUCTIONSNIPER_H
