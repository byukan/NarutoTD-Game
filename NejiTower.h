/** @file Neji.h
@brief This file contains class and member function declarations for Neji class.

NejiTower fires multiple projectiles in a spread.
*/

#ifndef NejiTOWER_H
#define NejiTOWER_H

#include "Tower.h"
#include <QTimer>

class NejiTower: public Tower
{
    Q_OBJECT
public:
    NejiTower(QGraphicsItem* parent = 0);
    void fire();
    public slots:
    void aquire_target();
};

#endif // NejiTOWER_H
