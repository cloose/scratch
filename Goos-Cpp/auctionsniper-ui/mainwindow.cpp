#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QXmppClient.h>

#include "auction.h"
#include "auctionmessagetranslator.h"
#include "auctionsniper.h"

const QString MainWindow::AUCTION_RESOURCE = QStringLiteral("Auction");
const QString MainWindow::AUCTION_ID_FORMAT = QStringLiteral("auction-%1@%2/%3");

class XmppAuction : public Auction
{
public:
    XmppAuction(const QString &auctionId, QXmppClient *chat)
    {
        this->auctionId = auctionId;
        this->chat = chat;
    }

    void bid(int amount)
    {
        chat->sendMessage(auctionId, QString("SOLVersion: 1.1; Command: BID; Price: %1;").arg(amount));
    }

private:
    QString auctionId;
    QXmppClient *chat;
};

MainWindow::MainWindow(const QString &hostname, const QString &username, const QString &password, const QString &id, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    itemId(id),
    connection(new QXmppClient(this)),
    translator(new AuctionMessageTranslator(this)),
    sniper(0)
{
    setObjectName(MAIN_WINDOW_NAME);
    ui->setupUi(this);

    connect(connection, SIGNAL(connected()),
            SLOT(connectionEstablished()));
    connect(connection, SIGNAL(messageReceived(QXmppMessage)),
            translator, SLOT(messageReceived(QXmppMessage)));

    // connect to message broker
    connectTo(hostname, username, password);
}

MainWindow::~MainWindow()
{
    connection->disconnectFromServer();
    delete connection;

    delete translator;

    delete ui;
}

void MainWindow::connectionEstablished()
{
    sniper = new AuctionSniper(new XmppAuction(auctionId(), connection), this);

    connect(translator, SIGNAL(auctionClosed()),
            sniper, SLOT(auctionClosed()));
    connect(translator, SIGNAL(currentPrice(int,int)),
            sniper, SLOT(currentPrice(int,int)));

    connect(sniper, SIGNAL(sniperLost()),
            SLOT(sniperLost()));
    connect(sniper, SIGNAL(sniperBidding()),
            SLOT(sniperBidding()));

    // send empty message to join auction
    connection->sendMessage(auctionId(), QString());
}

void MainWindow::sniperBidding()
{
    ui->sniperStatusLabel->setText("Bidding");
}

void MainWindow::sniperLost()
{
    // auction closed so we lost
    ui->sniperStatusLabel->setText("Lost");
}

void MainWindow::connectTo(const QString &hostname, const QString &username, const QString &password)
{
    QXmppConfiguration configuration;
    configuration.setHost(hostname);
    configuration.setUser(username);
    configuration.setDomain(hostname);
    configuration.setResource(AUCTION_RESOURCE);
    configuration.setPassword(password);

    connection->connectToServer(configuration);
}

QString MainWindow::auctionId() const
{
    return QString(AUCTION_ID_FORMAT).arg(itemId).arg(connection->configuration().domain()).arg(AUCTION_RESOURCE);
}

