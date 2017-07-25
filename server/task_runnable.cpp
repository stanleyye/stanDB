#include "task_runnable.h"

TaskRunnable::TaskRunnable()
{

}

void TaskRunnable::setSocketDescriptor(qintptr socket_descriptor)
{
    socket_descriptor_ = socket_descriptor;
}

void TaskRunnable::run()
{
    if (!socket_descriptor_) {
        qDebug() << "Socket not defined";
        return;
    }

    Client *client = new Client(socket_descriptor_);
}

qintptr TaskRunnable::getSocketDescriptor()
{
    return socket_descriptor_;
}
