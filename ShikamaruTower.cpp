/** @file ShikamaruTower.cpp
@brief This file contains member function definitions for the ShikamaruTower class.

ShikamaruTower fires multiple projectiles in a spread.
*/

#include "ShikamaruTower.h"
#include <QTimer>
#include "Projectile.h"
#include "Game.h"

extern Game* game;




ShikamaruTower::ShikamaruTower(QGraphicsItem *parent)
{
    // connect a timer to attack_target
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(6000);  //fire rate
}

void ShikamaruTower::fire()
{
    // create the Projectiles
    Projectile * Projectile2 = new Projectile();
    Projectile * Projectile3 = new Projectile();
    Projectile * Projectile4 = new Projectile();
    Projectile * Projectile5 = new Projectile();
    Projectile * Projectile6 = new Projectile();


    // set the graphics
    Projectile2->setPixmap(QPixmap(":/images/shadow.png"));
    Projectile3->setPixmap(QPixmap(":/images/shadow.png"));
    Projectile4->setPixmap(QPixmap(":/images/shadow.png"));
    Projectile5->setPixmap(QPixmap(":/images/shadow.png"));
    Projectile6->setPixmap(QPixmap(":/images/shadow.png"));


    Projectile2->setPos(x()+40,y()+50);
    Projectile3->setPos(x()+40,y()+50);
    Projectile4->setPos(x()+40,y()+50);
    Projectile5->setPos(x()+40,y()+50);
    Projectile6->setPos(x()+40,y()+50);



    QLineF ln(QPointF(x()+40,y()+50),attack_dest);
    int angle = -1 * ln.angle();

    Projectile2->setRotation(angle+25);
    Projectile3->setRotation(angle-25);
    Projectile4->setRotation(angle+30);
    Projectile5->setRotation(angle-30);
    Projectile6->setRotation(angle);



    game->scene->addItem(Projectile2);
    game->scene->addItem(Projectile3);
    game->scene->addItem(Projectile4);

    game->scene->addItem(Projectile5);
    game->scene->addItem(Projectile6);

}

void ShikamaruTower::aquire_target()
{
    Tower::aquire_target();
}
