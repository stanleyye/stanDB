# Created by and for Qt Creator. This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = stanDB
CONFIG += qt

HEADERS = \
   $$PWD/Server/CommandOptions.hpp \
   $$PWD/Server/User.hpp

SOURCES = \
   $$PWD/Server/CommandOptions.cpp \
   $$PWD/Server/Server.cpp \
   $$PWD/Server/User.cpp \

INCLUDEPATH += /usr/local/lib/boost_1_64_0

LIBS += \
        -lboost_date_time \
        -lboost_filesystem \
        -lboost_program_options \
        -lboost_serialization \
        -lboost_system
#DEFINES = 

