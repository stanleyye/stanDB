#include "server.h"

Server::Server(QObject *parent)
    : QTcpServer(parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(4);
}

void Server::StartServer()
{
    if (this->listen(QHostAddress::Any, portNum)) {
        qDebug() << "Server started at port" << portNum;
    } else {
        qDebug() << "Server did not start at port " << portNum;
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    //QThreadPool::globalInstance()->start();
}
