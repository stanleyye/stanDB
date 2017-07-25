#ifndef CLIENT_H
#define CLIENT_H

#include <QByteArray>
#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(qintptr socketDescriptor, QObject *parent = nullptr);

private:
    QTcpSocket *socket;
    qintptr socket_descriptor_;
signals:

public slots:
    void socketDisconnected();
    void socketReadyRead();
};

#endif // CLIENT_H
