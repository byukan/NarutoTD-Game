/** @file KibaTower.cpp
@brief This file contains member function definitions for the KibaTower class.

KibaTower fires projectiles at enemies.
*/

#include "KibaTower.h"
#include <QTimer>
#include "Projectile.h"
#include "Game.h"

extern Game* game;




KibaTower::KibaTower(QGraphicsItem *parent)
{
    // connect a timer to attack_target
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1800);  //fire rate
}

void KibaTower::fire()
{
    // create the Projectiles
    Projectile * projectile = new Projectile();
    // set the graphics
    projectile->setPixmap(QPixmap(":/images/akamaru.png"));
    projectile->setPos(x()+40,y()+50);
    QLineF ln(QPointF(x()+40,y()+50),attack_dest);
    int angle = -1 * ln.angle();
    projectile->setRotation(angle+(rand()%41-20));
    game->scene->addItem(projectile);
}

void KibaTower::aquire_target()
{
    Tower::aquire_target();
}
