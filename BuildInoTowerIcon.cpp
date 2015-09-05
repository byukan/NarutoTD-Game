/** @file BuildInoTowerIcon.cpp
@brief This file contains member function definitions for the BuildInoTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#include "BuildInoTowerIcon.h"
#include "Game.h"
#include "InoTower.h"

extern Game * game;

BuildInoTowerIcon::BuildInoTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/ino_icon.png"));
}

void BuildInoTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!game->building && game->score->score >=1000){
        game->score->decrease(1000);
        game->building = new InoTower();
        game->setCursor(QString(":/images/ino.png"));
    }
}
