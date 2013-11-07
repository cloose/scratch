#include "auctionmessagetranslator.h"

#include <QXmppMessage.h>


AuctionMessageTranslator::AuctionMessageTranslator(QObject *parent) :
    QObject(parent)
{
}

void AuctionMessageTranslator::messageReceived(const QXmppMessage &message)
{
    QMap<QString, QString> event = unpackEventFrom(message);

    QString type = event.value("Event");
    if (type == "CLOSE") {
        emit auctionClosed();
    } else if (type == "PRICE") {
        emit currentPrice(event.value("CurrentPrice").toInt(),
                          event.value("Increment").toInt());
    }
}

QMap<QString, QString> AuctionMessageTranslator::unpackEventFrom(const QXmppMessage &message)
{
    QMap<QString, QString> event;

    foreach (const QString &element, message.body().split(";", QString::SkipEmptyParts)) {
        QStringList parts = element.split(":");
        event.insert(parts[0].trimmed(), parts[1].trimmed());
    }

    return event;
}
