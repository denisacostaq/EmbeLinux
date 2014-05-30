#include <QtCore/QCoreApplication>
#include <QTimer>
#include <QDebug>
#include <QStringList>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>

#define PORT_TCP 9091

QStringList m_listServer {"10.58.20.150", "10.58.24.232"};

void serverLog(const QString &msg)
{
    qDebug() << "-- [SERVIDOR] -- " << msg;
}

bool startSlave()
{
    serverLog(u8"Starting server");
    QTcpServer *server{new QTcpServer};
    QObject::connect(server, &QTcpServer::newConnection, [server]{
        QTcpSocket *cliSock = server->nextPendingConnection();
        serverLog(QString(u8"Acepted conection from %1").arg(cliSock->peerAddress().toString()));
        serverLog(u8"Sending server Address: " + cliSock->localAddress().toString());
        cliSock->write(cliSock->localAddress().toString().toLocal8Bit());
        cliSock->waitForBytesWritten();
        cliSock->disconnectFromHost();
        cliSock->close();
    });

    if (server->listen (QHostAddress::Any, PORT_TCP))
    {
        serverLog (u8"Server listening...");
    }
    else
    {
        serverLog (QString(u8"Error starting server: %1").arg (server->errorString()));
    }
    return true;
}

bool checkServers()
{
    qDebug() << u8"Testing slaves";
    bool found{false};
    QTcpSocket *sock{nullptr};
    auto funClose = [&sock]{
        sock->close();
        if (sock && sock->state () != QTcpSocket::UnconnectedState)
        {
            sock->waitForDisconnected(100);
        }
        delete sock;
        sock = nullptr;
    };

    for (auto it: m_listServer)
    {
        sock = new QTcpSocket;
        sock->connectToHost(it, PORT_TCP);
        qDebug() << QString("Testing servers %1").arg (it);
        if (sock->waitForConnected(100))
        {
            sock->waitForReadyRead();
            QByteArray readed{sock->readAll()};
            if (!readed.isNull() && !readed.isEmpty())
            {
                qDebug() << u8"Server found in: " << QString{readed};
                found = true;
            }
            else
            {
                qDebug() << u8"Erroneous answeare from server";
            }
        }
        else
        {
            qDebug() << u8"Timeout in server response for: " << it;
        }
        funClose();
    }

    if (!found)
    {
        startSlave();
        return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QTimer t;
    t.setInterval(1000);
    QObject::connect(&t, &QTimer::timeout, [&t]{
        if (checkServers())
        {
            t.stop ();
        }
    });
    t.start();
    return app.exec();
}
