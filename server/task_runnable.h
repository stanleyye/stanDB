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
    void setCommand(QString command_to_parse);

protected:
    void run();

private:
    QString command_to_parse;

signals:
    void commandRequestReady(QString qstring);

public slots:
};

#endif // TASK_RUNNABLE_H
