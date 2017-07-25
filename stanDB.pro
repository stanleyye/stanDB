QT += core
QT += network
QT -= gui

CONFIG += c++11

TARGET = stanDB
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

HEADERS = \
    access/user.h \
    cmd/command_options.h \
    server/server.h \
    client/client.h \
    server/task_runnable.h

SOURCES = \
    access/user.cpp \
    cmd/command_loop.cpp \
    cmd/command_options.cpp \
    main.cpp \
    server/server.cpp \
    client/client.cpp \
    server/task_runnable.cpp

INCLUDEPATH += /usr/local/lib/boost_1_64_0

LIBS += -L/usr/local/lib/ \
        -lboost_date_time \
        -lboost_filesystem \
        -lboost_program_options \
        -lboost_serialization \
        -lboost_system

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_LFLAGS += -Wl,-rpath,"'\$$ORIGIN'"

