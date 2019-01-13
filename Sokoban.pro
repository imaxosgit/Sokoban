QT += core
QT -= gui

TARGET = Sokoban
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    board.cpp \
    filehandler.cpp \
    player.cpp \
    direction.cpp

HEADERS += \
    filehandler.h \
    board.h \
    player.h \
    cell.h \
    wall.h \
    boxspot.h \
    emptycell.h \
    direction.h

DISTFILES += \
    level

