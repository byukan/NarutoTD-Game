/** @file Projectile.cpp
@brief This file contains member function definitions for the Projectile class.

Projectiles have a chance to destroy enemies when they collide.  GOLD increases when the enemy dies.
*/

#include "Projectile.h"
#include <QPixMap>
#include <QTimer>
#include <qmath.h>  //qSin, qCos, qTan
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include <typeinfo>
#include "Game.h"
#include <stdlib.h> // rand() -> really large int


extern Game* game; // there is an external global object called game



Projectile::Projectile(QGraphicsItem *parent)
{
    //set graphics
    setPixmap(QPixmap(":/images/rasengan.png"));

    //connect a timer to move()
    QTimer* move_timer = new QTimer(this);

    connect(move_timer, SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);  //Projectile speed  50 is slow

    //initialize values
    maxRange = 100;
    distanceTravelled = 0;

}

void Projectile::move()
{
//    if(distanceTravelled>maxRange){
//        scene()->removeItem(this);
//        delete this;
//        return;
//    }
    // chance to kill enemy
//    int criticalHit = rand()%3;  //1/3 chancce to kill enemy

    // get a list of all the items currently colliding with this Projectile
    QList<QGraphicsItem*> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, chance to destroy both the Projectile and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){

        if (typeid(*(colliding_items[i])) == typeid(Enemy)){


            if(rand()%6 == 1){  // 1/n chance to kill enemy per step
                // increase the score
                game->score->increase(850);

                // remove them from the scene (still on the heap)
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);

                // delete them from the heap to free memory
                delete colliding_items[i];
                delete this;

                // return (all code below refers to a non existint Projectile)
                return;
            }
            else{ //projectile did not kill enemy
                scene()->removeItem(this);
                delete this;
                return;
            }


        }

    }

    // if there was no collision with an Enemy, move the Projectile forward
    setPos(x(),y());
    // if the Projectile is off the screen, destroy it
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }


    int STEP_SIZE = 20;  // projectile step size
    double theta = rotation(); //degrees

    double dy = STEP_SIZE*qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE*qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);
}


double Projectile::getMaxRange(){
    return maxRange;
}

double Projectile::getDistanceTravelled(){
    return distanceTravelled;
}

void Projectile::setMaxRange(double rng){
maxRange = rng;
}

void Projectile::setDistanceTravelled(double dist){
    distanceTravelled = dist;
}
