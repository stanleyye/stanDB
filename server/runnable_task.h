#ifndef RUNNABLE_TASK_H
#define RUNNABLE_TASK_H

#include <QRunnable>
#include <QTcpSocket>

// A task that runs on a thread in a threadpool

class RunnableTask : public QRunnable
{
public:
    RunnableTask();
    qintptr getSocketDescriptor();
    void setSocketDescriptor(qintptr socket_descriptor);

protected:
    void run();

private:
    qintptr socket_descriptor_;
};

#endif // RUNNABLE_TASK_H
