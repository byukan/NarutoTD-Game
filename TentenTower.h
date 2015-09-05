/** @file Tenten.h
@brief This file contains class and member function declarations for Tenten class.

TentenTower fires multiple projectiles all around.
*/

#ifndef TentenTOWER_H
#define TentenTOWER_H

#include "Tower.h"
#include <QTimer>

class TentenTower: public Tower
{
    Q_OBJECT
public:
    TentenTower(QGraphicsItem* parent = 0);
    void fire();
    public slots:
    void aquire_target();
};

#endif // TentenTOWER_H
