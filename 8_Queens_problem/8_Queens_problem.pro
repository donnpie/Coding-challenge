TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        gameboard.cpp \
        gamestate.cpp \
        main.cpp \
        nqueensproblem.cpp \
        nqueenssolution.cpp

HEADERS += \
    gameboard.h \
    gamestate.h \
    nqueensproblem.h \
    nqueenssolution.h
