#include "auctionsniperdriver.h"

#include <QtTest/QtTest>

#include <QApplication>
#include <QLabel>
#include <QWidget>


AuctionSniperDriver::AuctionSniperDriver(const QString &name, QObject *parent) :
    mainWindow(0)
{
    foreach(QWidget *widget, qApp->topLevelWidgets()) {
        if (widget->objectName() == name) {
            mainWindow = widget;
        }
    }

    QVERIFY2(mainWindow != 0, qPrintable(QString("Failed to find top level widget with name %1").arg(name)));
}

void AuctionSniperDriver::showsSniperStatus(const QString &statusText)
{
    QLabel *label = mainWindow->findChild<QLabel*>("sniperStatusLabel");
    QVERIFY2(label != 0, qPrintable(QString("Failed to find label with name %1").arg("sniperStatusLabel")));

    QTRY_COMPARE_WITH_TIMEOUT(label->text(), statusText, 1000);
}
