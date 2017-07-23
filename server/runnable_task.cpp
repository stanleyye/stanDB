#include "runnable_task.h"

RunnableTask::RunnableTask()
{

}

void RunnableTask::setSocketDescriptor(qintptr socket_descriptor)
{
    socket_descriptor_ = socket_descriptor;
}

void RunnableTask::run()
{
    if (!socket_descriptor_) {
        qDebug() << "Socket not defined";
    }

    QTcpSocket socket;
    socket.setSocketDescriptor(socket_descriptor_);

    socket.write("\nWelcome to stanDB.\n\n");
    socket.flush();
    socket.waitForBytesWritten();
    socket.close();
}

qintptr RunnableTask::getSocketDescriptor()
{
    return socket_descriptor_;
}
