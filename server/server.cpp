#include "server.h"

Server::Server(QObject *parent)
    : QTcpServer(parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(maxThreadCount);
}

void Server::startServer()
{
    if (this->listen(QHostAddress::Any, portNum)) {
        qDebug() << "Server started at port" << portNum;
    } else {
        qDebug() << "Server did not start at port " << portNum;
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    RunnableTask *task = new RunnableTask();
    task->setAutoDelete(true);
    task->setSocketDescriptor(socketDescriptor);

    QThreadPool::globalInstance()->start(task);
}
