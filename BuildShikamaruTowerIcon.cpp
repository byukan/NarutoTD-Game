/** @file BuildShikamaruTowerIcon.cpp
@brief This file contains member function definitions for the BuildShikamaruTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#include "BuildShikamaruTowerIcon.h"
#include "Game.h"
#include "ShikamaruTower.h"

extern Game * game;

BuildShikamaruTowerIcon::BuildShikamaruTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/shikamaru_icon.png"));
}

void BuildShikamaruTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!game->building && game->score->score >=7000){
        game->score->decrease(7000);
        game->building = new ShikamaruTower();
        game->setCursor(QString(":/images/shikamaru.png"));
    }
}
