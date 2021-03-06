#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class AuctionMessageTranslator;
class AuctionSniper;
class QXmppClient;
class QXmppMessage;


// public string constants
#define MAIN_WINDOW_NAME "Auction Sniper Main"


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(const QString &hostname, const QString &username, const QString &password, const QString &id, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void connectionEstablished();
    void sniperBidding();
    void sniperLost();

private:
    void connectTo(const QString &hostname, const QString &username, const QString &password);
    QString auctionId() const;

private:
    Ui::MainWindow *ui;
    QString itemId;
    QXmppClient *connection;
    AuctionMessageTranslator *translator;
    AuctionSniper *sniper;

    static const QString AUCTION_RESOURCE;
    static const QString AUCTION_ID_FORMAT;
};

#endif // MAINWINDOW_H
