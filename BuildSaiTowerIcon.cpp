/** @file BuildSaiTowerIcon.cpp
@brief This file contains member function definitions for the BuildSaiTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#include "BuildSaiTowerIcon.h"
#include "Game.h"
#include "SaiTower.h"

extern Game * game;

BuildSaiTowerIcon::BuildSaiTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/sai_icon.png"));
}

void BuildSaiTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!game->building && game->score->score >=5000){
        game->score->decrease(5000);
        game->building = new SaiTower();
        game->setCursor(QString(":/images/sai.png"));
    }
}
