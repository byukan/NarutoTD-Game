/** @file Chidori.cpp
@brief This file contains member function definitions for the Chidori class.

The Chidori destroys any Enemies or Tobis that collide with it.
*/

#include "Chidori.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
#include <typeinfo>
#include <Tobi.h>

extern Game * game; // there is an external global object called game

Chidori::Chidori(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw graphics
    setPixmap(QPixmap(":/images/chidori.png"));

    // make/connect a timer to move() the Chidori every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Chidori::move(){
    // get a list of all the items currently colliding with this Chidori
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the Chidori and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Tobi)||typeid(*(colliding_items[i])) == typeid(Enemy)){


                // increase the score
                game->score->increase(500);

                // remove them from the scene (still on the heap)
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);

                // delete them from the heap to free memory
                delete colliding_items[i];
                delete this;

                // return (all code below refers to a non existint Projectile)
                return;

                scene()->removeItem(this);
                delete this;
                return;



        }
    }

    // if there was no collision with an Enemy, move the Chidori forward
    setPos(x(),y()-20);
    // if the Chidori is off the screen, destroy it
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
