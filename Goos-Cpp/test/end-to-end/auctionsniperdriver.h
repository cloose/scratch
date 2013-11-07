#ifndef AUCTIONSNIPERDRIVER_H
#define AUCTIONSNIPERDRIVER_H

#include <QObject>

class QString;
class QWidget;


class AuctionSniperDriver : public QObject
{
    Q_OBJECT

public:
    explicit AuctionSniperDriver(const QString &name, QObject *parent = 0);

    void showsSniperStatus(const QString &statusText);

private:
    QWidget *mainWindow;
};

#endif // AUCTIONSNIPERDRIVER_H
