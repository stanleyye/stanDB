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

    qDebug() << "Ideal thread count: " << QThread::idealThreadCount();
    qDebug() << "Max thread count: " <<
                QThreadPool::globalInstance()->maxThreadCount();
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "Connecting to socket " << socketDescriptor;

    TaskRunnable *task = new TaskRunnable();
    task->setAutoDelete(true);
    task->setSocketDescriptor(socketDescriptor);

    QThreadPool::globalInstance()->start(task);
    qDebug() << "Active connections(threads): " <<
                QThreadPool::globalInstance()->activeThreadCount();
}
