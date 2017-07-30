#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include <QObject>

class CommandManager : public QObject
{
    Q_OBJECT
public:
    explicit CommandManager(QObject *parent = nullptr);

signals:
    void commandResponseReady(QString &qString);
public slots:
    void parseCommand(QString &qString);
};

#endif // COMMAND_MANAGER_H
