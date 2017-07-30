#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{

}


qintptr Client::getSocketDescriptor()
{
    return socket_descriptor;
}

void Client::commandResponseReady(QByteArray &byteArray)
{
    // TODO: check if socket is present. If not, return an error
    socket->write(response);
}

void Client::sendResponse(QByteArray response)
{
    socket->write(response);
}

void Client::setSocketDescriptor(qintptr socket_descriptor)
{
    this->socket_descriptor = socket_descriptor;

    // Create a new socket to connect to the client
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(this->socket_descriptor);

    connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(socketReadyRead()));

    qDebug() << "Socket connection # " << socket_descriptor << " connected";
    socket->write("\nWelcome to stanDB.\n");
    socket->write("For more options, enter --help\n\n");
    socket->flush();
}

void Client::socketDisconnected()
{
    qDebug() << "Socket connection # " << socket_descriptor << " disconnected";

    socket->deleteLater();
    this->deleteLater();
}

void Client::socketReadyRead()
{
    QByteArray data = socket->readAll();
    qDebug() << socket_descriptor << ": " << data;

    command_buffer.append(data);

    qDebug() << command_buffer;

    // Each command statement ends with a semi colon (;) and return
    if (command_buffer.endsWith('\n')) {
        qDebug() << "Creating task with command: " << command_buffer;

        TaskRunnable *task = new TaskRunnable();
        task->setCommand(command_buffer);
        task->setAutoDelete(true);

        // chain signal from the task to server.cpp
        connect(task, SIGNAL(responseReady(QByteArray&)),
                SIGNAL(responseReady(QByteArray&)));

        QThreadPool::globalInstance()->start(task);
        qDebug() << "Active connections(threads): " <<
                    QThreadPool::globalInstance()->activeThreadCount();
        command_buffer.clear();
    }
}
