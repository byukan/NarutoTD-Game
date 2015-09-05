/** @file TentenTower.cpp
@brief This file contains member function definitions for the TentenTower class.

TentenTower fires multiple projectiles all around.
*/

#include "TentenTower.h"
#include <QTimer>
#include "Projectile.h"
#include "Game.h"

extern Game* game;




TentenTower::TentenTower(QGraphicsItem *parent)
{
    // connect a timer to attack_target
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(7000);  //fire rate
}

void TentenTower::fire()
{
    // create the Projectiles
    Projectile * Projectile2 = new Projectile();
    Projectile * Projectile3 = new Projectile();
    Projectile * Projectile4 = new Projectile();
    Projectile * Projectile5 = new Projectile();

    // set the graphics
    Projectile2->setPixmap(QPixmap(":/images/kunai.png"));
    Projectile3->setPixmap(QPixmap(":/images/kunai.png"));
    Projectile4->setPixmap(QPixmap(":/images/kunai.png"));
    Projectile5->setPixmap(QPixmap(":/images/kunai.png"));

    Projectile2->setPos(x()+40,y()+50);
    Projectile3->setPos(x()+40,y()+50);
    Projectile4->setPos(x()+40,y()+50);
    Projectile5->setPos(x()+40,y()+50);


    QLineF ln(QPointF(x()+40,y()+50),attack_dest);
    int angle = -1 * ln.angle();

    Projectile2->setRotation(angle);
    Projectile3->setRotation(angle-90);
    Projectile4->setRotation(angle+90);
    Projectile5->setRotation(angle+180);


    game->scene->addItem(Projectile2);
    game->scene->addItem(Projectile3);
    game->scene->addItem(Projectile4);

    game->scene->addItem(Projectile5);


}

void TentenTower::aquire_target()
{
    Tower::aquire_target();
}
