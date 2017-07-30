#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include <QObject>
#include <QDir>

class CommandManager : public QObject
{
    Q_OBJECT
public:
    explicit CommandManager(QObject *parent = nullptr);
    enum CommandLineParseResult
    {
        CommandLineOk,
        CommandLineError,
        CommandLineHelpRequested
    };

private:
    QCommandLineParser parser;

signals:
    void commandResponseReady(QString &qstring);

public slots:
    void parseCommandLine(QString &qstring);
    CommandLineParseResult commandLineErrorCheck(
            const QStringList &qstring_list, const QString &error_message
    );
};

#endif // COMMAND_MANAGER_H
