#include "command_manager.h"

CommandManager::CommandManager(QObject *parent) : QObject(parent)
{
    parser.setApplicationDescription("A relational database management system");
}

// TODO: create a thread-safe implementation
void CommandManager::parseCommandLine(QString &qstring)
{
    // Split the qstring command by white space
    QStringList qstring_list = qstring.split(" ");
    // The parser requires a list of QStrings containing the application path + arguments.
    // Hence, insert the application path at the beginning of the list
    qstring_list.insert(0, QDir::currentPath());

    QString error_message;
    switch(commandLineErrorCheck(qstring_list, error_message)) {
    case CommandLineOk:
        break;
    case CommandLineError:
        // TODO: emit and then return
        return;
    case CommandLineHelpRequested:
        // TODO: emit help and return
        parser.showHelp();
        return;
    }

    // TODO: parse the arguments...
}

CommandManager::CommandLineParseResult CommandManager::commandLineErrorCheck(
        const QStringList &qstring_list, const QString &error_message)
{
    if (!parser.parse(qstring_list)) {
        error_message = parser.errorText();
        return CommandLineError;
    }

    if (parser.isSet(parser.addHelpOption())) {
        return CommandLineHelpRequested;
    }

    return CommandLineOk;
}
