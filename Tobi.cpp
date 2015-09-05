/** @file Tobi.cpp
@brief This file contains member function definitions for the Tobi class.

Tobi spawns on the left side of the map and can be destroyed by the Player's Bullet.
*/

#include "Tobi.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;

Tobi::Tobi(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int random_number = rand() % 470;
    setPos(random_number,300);

    setPixmap(QPixmap(":/images/tobi.png"));
//    setTransformOriginPoint(50,50);
//    setRotation(180);

    // make/connect a timer to move() the Tobi every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Tobi::move(){
    // move Tobi down
    setPos(x(),y()+5);

    // destroy Tobi when it goes out of the screen
    if (pos().y() > 700){
        //decrease the health
        //game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
