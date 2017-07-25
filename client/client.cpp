#include "client.h"

Client::Client(qintptr socketDescriptor, QObject *parent) : QObject(parent)
{
    socket_descriptor_ = socketDescriptor;

    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socket_descriptor_);

    // TODO: find out why none of the signal and slots seem to be working...

    connect(socket, SIGNAL(readyRead()), this, SLOT(socketReadyRead()),
            Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()),
            Qt::DirectConnection);

    qDebug() << "Socket connection # " << socket_descriptor_ << " connected";

    socket->write("\nWelcome to stanDB.\n\n");
    socket->flush();
}

void Client::socketDisconnected()
{
    qDebug() << "Socket connection # " << socket_descriptor_ << " disconnected";

    socket->deleteLater();
    this->deleteLater();
}

void Client::socketReadyRead()
{
    QByteArray data = socket->readAll();
    qDebug() << socket_descriptor_ << ": " << data;
}
