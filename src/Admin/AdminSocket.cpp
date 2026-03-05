#include "AdminSocket.h"

AdminSocket::AdminSocket(QObject* parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::connected, this, &AdminSocket::connected);
    connect(socket, &QTcpSocket::disconnected, this, &AdminSocket::disconnected);
    connect(socket, &QTcpSocket::readyRead, this, &AdminSocket::readyRead);
    connect(socket, &QTcpSocket::errorOccurred, this, &AdminSocket::errorOccurred);
}

bool AdminSocket::connectToServer(const QString &hostAddress, quint16 port)
{
    qDebug() << "Connecting to host:" << hostAddress << "port:" << port;
    socket->connectToHost(hostAddress, port);
    if (!socket->waitForConnected(1000))
    {
        return false;
    }
    return true;
}

void AdminSocket::connected()
{
    qDebug() << "Connected";
    socket->write("Connected to Server");
}

bool AdminSocket::isConnected() const
{
    return connection;
}

void AdminSocket::disconnected()
{
    qDebug() << "Disconnected";
    if (socket->isOpen())
    {
        socket->close();
    }
    connection = false;
}

void AdminSocket::readyRead()
{
    QByteArray data = socket->readAll();
    qDebug() << "Reveived: " << data;
}

void AdminSocket::sendMessage(const QString& message)
{
    if (connection)
    {
        QByteArray data = message.toUtf8();
        socket->write(data);
        socket->flush();
    }
}

void AdminSocket::errorOccurred(QAbstractSocket::SocketError socketError)
{
    qDebug() << "Error:" << socket->errorString();
}