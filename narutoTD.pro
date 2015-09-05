#-------------------------------------------------
#
# Project created by QtCreator 2015-05-24T15:22:49
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = narutoTD
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Tower.cpp \
    Game.cpp \
    Enemy.cpp \
    BuildNarutoTowerIcon.cpp \
    NarutoTower.cpp \
    BuildHinataTowerIcon.cpp \
    HinataTower.cpp \
    Score.cpp \
    Health.cpp \
    BuildInoTowerIcon.cpp \
    BuildTentenTowerIcon.cpp \
    BuildKibaTowerIcon.cpp \
    BuildSaiTowerIcon.cpp \
    BuildRockleeTowerIcon.cpp \
    BuildShikamaruTowerIcon.cpp \
    BuildNejiTowerIcon.cpp \
    InoTower.cpp \
    TentenTower.cpp \
    KibaTower.cpp \
    SaiTower.cpp \
    RockleeTower.cpp \
    ShikamaruTower.cpp \
    NejiTower.cpp \
    Projectile.cpp \
    Player.cpp \
    Tobi.cpp \
    Chidori.cpp

HEADERS  += mainwindow.h \
    Tower.h \
    Game.h \
    Enemy.h \
    BuildNarutoTowerIcon.h \
    NarutoTower.h \
    BuildHinataTowerIcon.h \
    HinataTower.h \
    Score.h \
    Health.h \
    BuildInoTowerIcon.h \
    BuildTentenTowerIcon.h \
    BuildKibaTowerIcon.h \
    BuildSaiTowerIcon.h \
    BuildRockleeTowerIcon.h \
    BuildShikamaruTowerIcon.h \
    BuildNejiTowerIcon.h \
    InoTower.h \
    TentenTower.h \
    KibaTower.h \
    SaiTower.h \
    RockleeTower.h \
    ShikamaruTower.h \
    NejiTower.h \
    Projectile.h \
    Player.h \
    Tobi.h \
    Chidori.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

CONFIG += C++11
