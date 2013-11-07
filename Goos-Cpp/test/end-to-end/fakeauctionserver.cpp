#include "fakeauctionserver.h"

#include <QtTest/QtTest>

#include <QXmppClient.h>
#include <QXmppMessage.h>

Q_DECLARE_METATYPE(QXmppMessage)


FakeAuctionServer::FakeAuctionServer(const QString &itemId, QObject *parent) :
    QObject(parent),
    id(itemId),
    fromJid(QString()),
    connection(new QXmppClient(this)),
    messageListener(0)
{
    qRegisterMetaType<QXmppMessage>();
}

void FakeAuctionServer::startSellingItem()
{
    connection->connectToServer(QString("auction-%1@localhost/Auction").arg(id), "auction");

    // wait until we are connected
    QSignalSpy spy(connection, SIGNAL(connected()));
    QVERIFY2(spy.wait(5000), "auction failed to connect to message broker server");

    // register message listener
    messageListener = new QSignalSpy(connection, SIGNAL(messageReceived(QXmppMessage)));

    connect(connection, SIGNAL(messageReceived(QXmppMessage)),
            SLOT(messageReceived(QXmppMessage)));
}

void FakeAuctionServer::hasReceivedJoinRequestFromSniper()
{
    // wait 5 seconds for any message
    QVERIFY2(messageListener->wait(5000), "No join request received from sniper");
}

void FakeAuctionServer::announceClosed()
{
    // send empty message signalling that the auction is closed
    connection->sendMessage(fromJid, QString());
}

void FakeAuctionServer::stop()
{
    connection->disconnectFromServer();
}

QString FakeAuctionServer::itemId() const
{
    return id;
}

void FakeAuctionServer::messageReceived(const QXmppMessage &message)
{
    fromJid = message.from();
}
