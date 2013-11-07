#include <QCoreApplication>

#include <QXmppLogger.h>
#include <QXmppPasswordChecker.h>
#include <QXmppServer.h>


class PasswordChecker : public QXmppPasswordChecker
{
protected:
    QXmppPasswordReply::Error getPassword(const QXmppPasswordRequest &request, QString &password)
    {
        if (request.username() == QStringLiteral("sniper"))  {
            password = QStringLiteral("sniper");
            return QXmppPasswordReply::NoError;
        } else if (request.username() == QStringLiteral("auction-item-54321")) {
            password = QStringLiteral("auction");
            return QXmppPasswordReply::NoError;
        } else if (request.username() == QStringLiteral("auction-item-65432")) {
            password = QStringLiteral("auction");
            return QXmppPasswordReply::NoError;
        } else {
            return QXmppPasswordReply::AuthorizationError;
        }
    }

    bool hasGetPassword() const
    {
        return true;
    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QXmppLogger logger;
    logger.setLoggingType(QXmppLogger::StdoutLogging);

    PasswordChecker passwordChecker;

    QXmppServer server;
    server.setDomain("localhost");
    server.setLogger(&logger);
    server.setPasswordChecker(&passwordChecker);
    server.listenForClients();

    return a.exec();
}
