#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QThreadPool>
#include <QDebug>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject *parent = 0);
    void StartServer();

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    quint16 portNum = 3001;
};

#endif // SERVER_H
