/** @file BuildTentenTowerIcon.cpp
@brief This file contains member function definitions for the BuildTentenTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#include "BuildTentenTowerIcon.h"
#include "Game.h"
#include "TentenTower.h"

extern Game * game;

BuildTentenTowerIcon::BuildTentenTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/tenten_icon.png"));
}

void BuildTentenTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!game->building && game->score->score >=2000){
        game->score->decrease(2000);
        game->building = new TentenTower();
        game->setCursor(QString(":/images/tenten.png"));
    }
}
