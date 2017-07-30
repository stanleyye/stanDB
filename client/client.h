#ifndef CLIENT_H
#define CLIENT_H

#include <QByteArray>
#include <QObject>
#include <QTcpSocket>
#include <QThreadPool>

#include "server/task_runnable.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    void setSocketDescriptor(qintptr socket_descriptor);
    qintptr getSocketDescriptor();

private:
    QString command_buffer_;
    QTcpSocket *socket_;
    qintptr socket_descriptor_;
signals:
    void commandRequestReady(QString &qString);

public slots:
    void commandResponseReady(QString &qString);
    void socketDisconnected();
    void socketReadyRead();
};

#endif // CLIENT_H
