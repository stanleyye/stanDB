#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QThreadPool>

#include "client/client.h"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject *parent = 0);
    void startServer();

protected:
    void incomingConnection(qintptr socket_descriptor) override;

private:
    int max_thread_count_ = 4;
    quint16 port_num_ = 3001;
};

#endif // SERVER_H
