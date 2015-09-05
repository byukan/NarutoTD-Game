/** @file NarutoTower.h
@brief This file contains class and member function declarations for NarutoTower class.

NarutoTower fires projectiles at enemies.
*/

#ifndef NARUTOTOWER_H
#define NARUTOTOWER_H

#include "Tower.h"
#include <QTimer>

class NarutoTower: public Tower
{
    Q_OBJECT
public:
    NarutoTower(QGraphicsItem* parent = 0);
    void fire();
    public slots:
    void aquire_target();
};

#endif // NARUTOTOWER_H
