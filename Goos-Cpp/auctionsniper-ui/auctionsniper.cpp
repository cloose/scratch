#include "auctionsniper.h"

#include "auction.h"

AuctionSniper::AuctionSniper(Auction *auction, QObject *parent) :
    QObject(parent)
{
    this->auction = auction;
}


void AuctionSniper::auctionClosed()
{
    emit sniperLost();
}

void AuctionSniper::currentPrice(int price, int increment)
{
    auction->bid(price + increment);
    emit sniperBidding();
}
