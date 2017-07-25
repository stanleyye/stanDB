#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QThreadPool>

#include "task_runnable.h"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject *parent = 0);
    void startServer();

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    int maxThreadCount = 4;
    quint16 portNum = 3001;
};

#endif // SERVER_H
