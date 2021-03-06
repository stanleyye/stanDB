#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QThreadPool>

#include "client/client.h"
#include "cmd/command_manager.h"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject *parent = 0);
    void startServer();

protected:
    void incomingConnection(qintptr socket_descriptor) override;

private:
    CommandManager *command_manager;
    int max_thread_count = 4;
    quint16 port_num = 3001;
};

#endif // SERVER_H
