//#include <QApplication>
#include <QtTest/QtTest>

#include "auctionmessagetranslatortest.h"
#include "auctionsnipertest.h"

int main(int argc, char *argv[])
{
//    QApplication app(argc, argv);

    AuctionMessageTranslatorTest test;
    QTest::qExec(&test, argc, argv);

    AuctionSniperTest test2;
    QTest::qExec(&test2, argc, argv);

    return 0;
}
