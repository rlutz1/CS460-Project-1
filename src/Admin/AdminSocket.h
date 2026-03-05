#ifndef CS460_PROJECT_1_ADMINSOCKET_H
#define CS460_PROJECT_1_ADMINSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class AdminSocket : public QObject{
    Q_OBJECT

public:
    explicit AdminSocket(QObject *parent = nullptr);
    bool connectToServer(const QString& host, const quint16 port);
    void sendMessage(const QString& message);
    bool isConnected() const;

private slots:
    void connected();
    void disconnected();
    void readyRead();
    void errorOccurred(QAbstractSocket::SocketError socketError);
    bool connection;

private:
    QTcpSocket *socket;

};


#endif //CS460_PROJECT_1_ADMINSOCKET_H