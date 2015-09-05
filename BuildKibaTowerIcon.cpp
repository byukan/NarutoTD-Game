/** @file BuildKibaTowerIcon.cpp
@brief This file contains member function definitions for the BuildKibaTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#include "BuildKibaTowerIcon.h"
#include "Game.h"
#include "KibaTower.h"

extern Game * game;

BuildKibaTowerIcon::BuildKibaTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/kiba_icon.png"));
}

void BuildKibaTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!game->building && game->score->score >=4000){
        game->score->decrease(4000);
        game->building = new KibaTower();
        game->setCursor(QString(":/images/kiba.png"));
    }
}
