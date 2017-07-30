#include "server.h"

Server::Server(QObject *parent)
    : QTcpServer(parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(max_thread_count_);
    // Initialize a command manager
    // TODO: memory leak. deallocate command manager
    command_manager_ = new CommandManager(this);
}

void Server::startServer()
{
    if (this->listen(QHostAddress::Any, port_num_)) {
        qDebug() << "Server started at port" << port_num_;
    } else {
        qDebug() << "Server did not start at port " << port_num_;
    }

    qDebug() << "Ideal thread count: " << QThread::idealThreadCount();
    qDebug() << "Max thread count: " <<
                QThreadPool::globalInstance()->maxThreadCount();
}

void Server::incomingConnection(qintptr socket_descriptor)
{
    qDebug() << "Incoming connection to socket " << socket_descriptor;

    Client *client = new Client(this);
    client->setSocketDescriptor(socket_descriptor);

    // Chaining grandchild (task runnable instance) to the command manager
    connect(client, SIGNAL(commandRequestReady(QString&)), command_manager_,
            SLOT(parseCommand(QString&)));
    connect(command_manager_, SIGNAL(commandResponseReady(QString&)), client,
            SLOT(commandResponseReady(QString&)));
}
