#include "task_runnable.h"

TaskRunnable::TaskRunnable()
{

}

void TaskRunnable::setCommand(QString command_to_parse)
{
    command_to_parse_ = command_to_parse;
}

void TaskRunnable::run()
{
    if (command_to_parse_.isEmpty() || command_to_parse_.isNull()) {
        qDebug() << "Command not defined";
        return;
    }

    qDebug() << "Starting task.";

    int endTime = clock() + 6000000;
    do { /* do nothing */ } while (clock() < endTime);

    qDebug() << "Task finished";
    // TODO: parse the commands
}

void TaskRunnable::responseReady(QByteArray response)
{

}
