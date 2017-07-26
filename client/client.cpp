#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{

}


qintptr Client::getSocketDescriptor()
{
    return socket_descriptor_;
}

void Client::sendResponse(QByteArray response)
{
    socket_->write(response);
}

void Client::setSocketDescriptor(qintptr socket_descriptor)
{
    socket_descriptor_ = socket_descriptor;

    // Create a new socket to connect to the client
    socket_ = new QTcpSocket(this);
    socket_->setSocketDescriptor(socket_descriptor_);

    connect(socket_, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
    connect(socket_, SIGNAL(readyRead()), this, SLOT(socketReadyRead()));

    qDebug() << "Socket connection # " << socket_descriptor_ << " connected";
    socket_->write("\nWelcome to stanDB.\n");
    socket_->write("For more options, enter --help\n\n");
}

void Client::socketDisconnected()
{
    qDebug() << "Socket connection # " << socket_descriptor_ << " disconnected";

    socket_->deleteLater();
    this->deleteLater();
}

void Client::socketReadyRead()
{
    QByteArray data = socket_->readAll();
    qDebug() << socket_descriptor_ << ": " << data;

    command_buffer_.append(data);

    qDebug() << command_buffer_;

    // Each command statement ends with a semi colon (;) and return
    if (command_buffer_.endsWith('\n')) {
        qDebug() << "Creating task with command: " << command_buffer_;

        TaskRunnable *task = new TaskRunnable();
        task->setCommand(command_buffer_);
        task->setAutoDelete(true);

//        connect(task, SIGNAL(responseReady(QByteArray&)), this,
//                SLOT(sendResponse(QByteArray&)));

        QThreadPool::globalInstance()->start(task);
        qDebug() << "Active connections(threads): " <<
                    QThreadPool::globalInstance()->activeThreadCount();
        command_buffer_.clear();
    }
}
