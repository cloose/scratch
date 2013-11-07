#ifndef AUCTIONMESSAGETRANSLATORTEST_H
#define AUCTIONMESSAGETRANSLATORTEST_H

#include <QObject>

class AuctionMessageTranslator;


class AuctionMessageTranslatorTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();

    void notifiesAuctionCloseWhenCloseMessageReceived();

    void notifiesBidDetailsWhenCurrentPriceMessageReceived();

    void cleanupTestCase();

private:
    AuctionMessageTranslator *translator;
};

#endif // AUCTIONMESSAGETRANSLATORTEST_H
