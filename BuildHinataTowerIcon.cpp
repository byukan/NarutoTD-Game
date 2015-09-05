/** @file BuildHinataTowerIcon.cpp
@brief This file contains member function definitions for the BuildHinataTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#include "BuildHinataTowerIcon.h"
#include "Game.h"
#include "HinataTower.h"

extern Game * game;

BuildHinataTowerIcon::BuildHinataTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/hinata_icon.png"));
}

void BuildHinataTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!game->building && game->score->score >=3000){
        game->score->decrease(3000);
        game->building = new HinataTower();
        game->setCursor(QString(":/images/hinata.png"));
    }
}
