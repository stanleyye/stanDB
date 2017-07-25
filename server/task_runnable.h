#ifndef TASK_RUNNABLE_H
#define TASK_RUNNABLE_H

#include <QRunnable>
#include <QTcpSocket>

#include "client/client.h"

// A task that runs on a thread in a threadpool

class TaskRunnable : public QRunnable
{
public:
    TaskRunnable();
    qintptr getSocketDescriptor();
    void setSocketDescriptor(qintptr socket_descriptor);

protected:
    void run();

private:
    qintptr socket_descriptor_;
};

#endif // TASK_RUNNABLE_H
