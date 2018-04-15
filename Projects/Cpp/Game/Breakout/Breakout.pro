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
    BreakoutWall.cpp \
    BreakoutBrick.cpp \
    MainMenuState.cpp \
    AssetManager.cpp \
    Globals.cpp \
    TitleState.cpp

HEADERS += \
    GameState.hpp \
    LevelState.hpp \
    BreakoutPad.hpp \
    BreakoutBall.hpp \
    BreakoutWall.hpp \
    BreakoutBrick.hpp \
    raymath.h \
    MainMenuState.h \
    easings.h \
    AssetManager.h \
    Globals.h \
    TitleState.h
