//#include <QApplication>
#include <QtTest/QtTest>

#include "auctionmessagetranslatortest.h"

int main(int argc, char *argv[])
{
//    QApplication app(argc, argv);

    AuctionMessageTranslatorTest test;
    return QTest::qExec(&test, argc, argv);
}
