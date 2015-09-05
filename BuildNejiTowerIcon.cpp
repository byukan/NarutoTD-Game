/** @file BuildNejiTowerIcon.cpp
@brief This file contains member function definitions for the BuildNejiTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#include "BuildNejiTowerIcon.h"
#include "Game.h"
#include "NejiTower.h"

extern Game * game;

BuildNejiTowerIcon::BuildNejiTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/neji_icon.png"));
}

void BuildNejiTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!game->building && game->score->score >=8000){
        game->score->decrease(8000);
        game->building = new NejiTower();
        game->setCursor(QString(":/images/neji.png"));
    }
}
