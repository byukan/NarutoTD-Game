/** @file Projectile.h
@brief This file contains class and member function declarations for Projectile class.

Projectiles have a chance to destroy enemies when they collide.  GOLD increases when the enemy dies.
*/

#ifndef Projectile_H
#define Projectile_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Projectile: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Projectile(QGraphicsItem* parent=0);
public slots:
    void move();
    double getMaxRange();
    double getDistanceTravelled();
    void setMaxRange(double rng);
    void setDistanceTravelled(double dist);
private:
    double maxRange;
    double distanceTravelled;
};

#endif // Projectile_H
