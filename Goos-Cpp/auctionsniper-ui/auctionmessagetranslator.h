#ifndef AUCTIONMESSAGETRANSLATOR_H
#define AUCTIONMESSAGETRANSLATOR_H

#include <QObject>

class QXmppMessage;


class AuctionMessageTranslator : public QObject
{
    Q_OBJECT
public:
    explicit AuctionMessageTranslator(QObject *parent = 0);
    
signals:
    void auctionClosed();
    void currentPrice(int price, int increment);

public slots:
    void messageReceived(const QXmppMessage &message);

private:
    QMap<QString, QString> unpackEventFrom(const QXmppMessage &message);
};

#endif // AUCTIONMESSAGETRANSLATOR_H
