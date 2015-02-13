QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++0x

TARGET = SPACEDEFENSE
TEMPLATE = app


SOURCES += main.cpp \
    Player.cpp \
    Enemy.cpp \
    Score.cpp \
    OpenWindow.cpp \
    Money.cpp \
    Game.cpp \
    Life.cpp \
    Shoot.cpp \
    Ship.cpp \
    ShipSimple.cpp \
    ShipDouble.cpp \
    ShipMaster.cpp \
    BuildShipIcon.cpp \
    BuildShipIconSimple.cpp \
    BuildShipIconDouble.cpp \
    BuildShipIconMaster.cpp

HEADERS  += \
    Player.h \
    Enemy.h \
    Score.h \
    OpenWindow.h \
    Money.h \
    Game.h \
    Life.h \
    Shoot.h \
    Ship.h \
    ShipSimple.h \
    ShipDouble.h \
    ShipMaster.h \
    BuildShipIcon.h \
    BuildShipIconSimple.h \
    BuildShipIconDouble.h \
    BuildShipIconMaster.h

FORMS    +=

RESOURCES += \
    Resources.qrc
