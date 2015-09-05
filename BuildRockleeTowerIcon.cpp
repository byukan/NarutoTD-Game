/** @file BuildRockleeTowerIcon.cpp
@brief This file contains member function definitions for the BuildRockleeTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#include "BuildRockleeTowerIcon.h"
#include "Game.h"
#include "RockleeTower.h"

extern Game * game;

BuildRockleeTowerIcon::BuildRockleeTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/rocklee_icon.png"));
}

void BuildRockleeTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!game->building && game->score->score >=6000){
        game->score->decrease(6000);
        game->building = new RockleeTower();
        game->setCursor(QString(":/images/rocklee.png"));
    }
}
