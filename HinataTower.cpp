/** @file HinataTower.cpp
@brief This file contains member function definitions for the HinataTower class.

HinataTower fires multiple projectiles in a spread.
*/

#include "HinataTower.h"
#include <QTimer>
#include "Projectile.h"
#include "Game.h"


extern Game * game;




HinataTower::HinataTower(QGraphicsItem *parent)
{
    // connect a timer to attack_target
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(2262);  //fire rate
}

void HinataTower::fire()
{
    // create the Projectiles
    Projectile * Projectile2 = new Projectile();
    Projectile * Projectile3 = new Projectile();

    // set the graphics
    Projectile2->setPixmap(QPixmap(":/images/lion_fist.png"));
    Projectile3->setPixmap(QPixmap(":/images/lion_fist.png"));





    Projectile2->setPos(x()+40,y()+50);
    Projectile3->setPos(x()+40,y()+50);


    QLineF ln(QPointF(x()+40,y()+50),attack_dest);
    int angle = -1 * ln.angle();

    Projectile2->setRotation(angle+5);
    Projectile3->setRotation(angle-5);

    game->scene->addItem(Projectile2);
    game->scene->addItem(Projectile3);



}

void HinataTower::aquire_target()
{
    Tower::aquire_target();
}
