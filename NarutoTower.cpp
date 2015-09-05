/** @file NarutoTower.cpp
@brief This file contains member function definitions for the NarutoTower class.

NarutoTower fires projectiles at enemies.
*/

#include "NarutoTower.h"
#include <QTimer>
#include "Projectile.h"
#include "Game.h"

extern Game* game;




NarutoTower::NarutoTower(QGraphicsItem *parent)
{
    // connect a timer to attack_target
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(200);  //fire rate
}

void NarutoTower::fire()
{
    Projectile* projectile = new Projectile();
    projectile->setPos(x()+40,y()+50);

    QLineF ln(QPointF(x()+40,y()+50),attack_dest);
    int angle = -1 * ln.angle();

    projectile->setRotation(angle+(rand()%41-20));
    game->scene->addItem(projectile);

}

void NarutoTower::aquire_target()
{
    Tower::aquire_target();
}
