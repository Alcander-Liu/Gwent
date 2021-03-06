#-------------------------------------------------
#
# Project created by QtCreator 2017-09-08T13:21:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gwent
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        MainWindow.cpp \
    DeckControl.cpp \
    Player.cpp \
    Field.cpp \
    Card.cpp \
    Account.cpp \
    Deck.cpp \
    BattleField.cpp \
    TurnPageButton.cpp \
    CardDataBase.cpp \
    GameControl.cpp \
    MyTimerLoop.cpp

HEADERS += \
        MainWindow.h \
    Player.h \
    Field.h \
    Card.h \
    CardDataBase.h \
    Account.h \
    Deck.h \
    DeckControl.h \
    BattleField.h \
    TurnPageButton.h \
    GameControl.h \
    MyTimerLoop.h

FORMS += \
        MainWindow.ui \
    DeckControl.ui \
    gamecontrol.ui

RESOURCES += \
    cardimages.qrc
