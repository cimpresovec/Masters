TEMPLATE = app
CONFIG += c++17
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lraylib

SOURCES += \
    Main.cpp \
    GameState.cpp \
    LevelState.cpp \
    BreakoutPad.cpp \
    BreakoutBall.cpp \
    BreakoutWall.cpp

HEADERS += \
    GameState.hpp \
    LevelState.hpp \
    BreakoutPad.hpp \
    BreakoutBall.hpp \
    BreakoutWall.hpp
