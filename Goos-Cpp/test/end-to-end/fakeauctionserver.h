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

    void startSellingItem();
    void hasReceivedJoinRequestFromSniper();
    void announceClosed();
    void stop();

    QString itemId() const;

private slots:
    void messageReceived(const QXmppMessage &message);

private:
    QString id;
    QString fromJid;
    QXmppClient *connection;
    QSignalSpy *messageListener;
};

#endif // FAKEAUCTIONSERVER_H
