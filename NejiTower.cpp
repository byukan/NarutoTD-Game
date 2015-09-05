/** @file NejiTower.cpp
@brief This file contains member function definitions for the NejiTower class.

NejiTower fires multiple projectiles in a spread.
*/

#include "NejiTower.h"
#include <QTimer>
#include "Projectile.h"
#include "Game.h"

extern Game* game;




NejiTower::NejiTower(QGraphicsItem *parent)
{
    // connect a timer to attack_target
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(2000);  //fire rate
}

void NejiTower::fire()
{
    // create the Projectiles
    Projectile * Projectile2 = new Projectile();
    Projectile * Projectile3 = new Projectile();
    Projectile * Projectile4 = new Projectile();


    // set the graphics
    Projectile2->setPixmap(QPixmap(":/images/trigram.png"));
    Projectile3->setPixmap(QPixmap(":/images/trigram.png"));
    Projectile4->setPixmap(QPixmap(":/images/trigram.png"));





    Projectile2->setPos(x()+40,y()+50);
    Projectile3->setPos(x()+40,y()+50);
    Projectile4->setPos(x()+40,y()+50);


    QLineF ln(QPointF(x()+40,y()+50),attack_dest);
    int angle = -1 * ln.angle();

    Projectile2->setRotation(angle+50);
    Projectile3->setRotation(angle-50);
    Projectile4->setRotation(angle);

    game->scene->addItem(Projectile2);
    game->scene->addItem(Projectile3);
    game->scene->addItem(Projectile4);

}

void NejiTower::aquire_target()
{
    Tower::aquire_target();
}
