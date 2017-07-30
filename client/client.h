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
    QString command_buffer;
    QTcpSocket *socket;
    qintptr socket_descriptor;
signals:
    void commandRequestReady(QString &qstring);

public slots:
    void commandResponseReady(QString &qstring);
    void socketDisconnected();
    void socketReadyRead();
};

#endif // CLIENT_H
