#include "auctionmessagetranslatortest.h"

#include <QtTest/QtTest>

#include <QXmppMessage.h>

#include <auctionmessagetranslator.h>


void AuctionMessageTranslatorTest::initTestCase()
{
    translator = new AuctionMessageTranslator(this);
}

void AuctionMessageTranslatorTest::notifiesAuctionCloseWhenCloseMessageReceived()
{
    QSignalSpy spy(translator, SIGNAL(auctionClosed()));

    QXmppMessage message;
    message.setBody("SOLVersion: 1.1; Event: CLOSE;");

    translator->messageReceived(message);

    QCOMPARE(spy.count(), 1);
}

void AuctionMessageTranslatorTest::notifiesBidDetailsWhenCurrentPriceMessageReceived()
{
    QSignalSpy spy(translator, SIGNAL(currentPrice(int, int)));

    QXmppMessage message;
    message.setBody("SOLVersion: 1.1; Event: PRICE; CurrentPrice: 192; Increment: 7; Bidder: Someone else;");

    translator->messageReceived(message);

    QCOMPARE(spy.count(), 1);

    QList<QVariant> arguments = spy.takeFirst();
    QVERIFY(arguments.at(0).type() == QVariant::Int);
    QCOMPARE(arguments.at(0).toInt(), 192);
    QVERIFY(arguments.at(1).type() == QVariant::Int);
    QCOMPARE(arguments.at(1).toInt(), 7);
}

void AuctionMessageTranslatorTest::cleanupTestCase()
{
    delete translator;
}

