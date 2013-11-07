#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QXmppClient.h>

const QString MainWindow::AUCTION_RESOURCE = QStringLiteral("Auction");
const QString MainWindow::AUCTION_ID_FORMAT = QStringLiteral("auction-%1@%2/%3");


MainWindow::MainWindow(const QString &hostname, const QString &username, const QString &password, const QString &id, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    itemId(id),
    connection(new QXmppClient(this))
{
    setObjectName(MAIN_WINDOW_NAME);
    ui->setupUi(this);

    connect(connection, SIGNAL(connected()),
            SLOT(connectionEstablished()));
    connect(connection, SIGNAL(messageReceived(QXmppMessage)),
            SLOT(messageReceived(QXmppMessage)));

    // connect to message broker
    connectTo(hostname, username, password);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectionEstablished()
{
    // send empty message to join auction
    connection->sendMessage(auctionId(), QString());
}

void MainWindow::messageReceived(const QXmppMessage &)
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

