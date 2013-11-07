#ifndef FAKEAUCTIONSERVER_H
#define FAKEAUCTIONSERVER_H

#include <QObject>

class QSignalSpy;
class QXmppClient;
class QXmppMessage;
class QXmppPresence;


class FakeAuctionServer : public QObject
{
    Q_OBJECT

public:
    explicit FakeAuctionServer(const QString &itemId, QObject *parent = 0);
    ~FakeAuctionServer();

    void startSellingItem();
    void hasReceivedJoinRequestFrom(const QString &sniperId);
    void reportPrice(int price, int increment, const QString &bidder);
    void hasReceivedBid(int bid, const QString &sniperId);
    void announceClosed();
    void stop();

    QString itemId() const;

private slots:
    void messageReceived(const QXmppMessage &message);

private:
    void receivesAMessageMatching(const QString &sniperId, const QString &messageExpected);

    QString id;
    QString fromJid;
    QString messageBody;
    QXmppClient *connection;
    QSignalSpy *messageListener;
};

#endif // FAKEAUCTIONSERVER_H
