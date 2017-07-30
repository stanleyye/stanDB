#include "task_runnable.h"

TaskRunnable::TaskRunnable()
{

}

void TaskRunnable::setCommand(QString command_to_parse)
{
    this->command_to_parse = command_to_parse;
}

void TaskRunnable::run()
{
    if (command_to_parse.isEmpty() || command_to_parse.isNull()) {
        qDebug() << "Command not defined";
        return;
    }

    emit commandRequestReady(command_to_parse);
}
