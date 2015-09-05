/** @file RockleeTower.h
@brief This file contains class and member function declarations for RockleeTower class.

RockleeTower fires projectiles at enemies.
*/

#ifndef RockleeTOWER_H
#define RockleeTOWER_H

#include "Tower.h"
#include <QTimer>

class RockleeTower: public Tower
{
    Q_OBJECT
public:
    RockleeTower(QGraphicsItem* parent = 0);
    void fire();
    public slots:
    void aquire_target();
};

#endif // RockleeTOWER_H
