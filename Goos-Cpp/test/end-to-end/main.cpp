#include <QApplication>
#include <QtTest/QtTest>

#include "auctionsniperendtoendtest.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    AuctionSniperEndToEndTest test;
    return QTest::qExec(&test, argc, argv);
}
