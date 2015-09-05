/** @file BuildNarutoTowerIcon.cpp
@brief This file contains member function definitions for the BuildNarutoTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#include "BuildNarutoTowerIcon.h"
#include "Game.h"
#include "NarutoTower.h"

#include "Score.h"


extern Game * game;

BuildNarutoTowerIcon::BuildNarutoTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/naruto_icon.png"));
}

void BuildNarutoTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!game->building && game->score->score >=9000){
        game->score->decrease(9000);
        game->building = new NarutoTower();
        game->setCursor(QString(":/images/naruto.png"));
    }
}
