/** @file SaiTower.h
@brief This file contains class and member function declarations for SaiTower class.

SaiTower fires projectiles at enemies.
*/

#ifndef SaiTOWER_H
#define SaiTOWER_H

#include "Tower.h"
#include <QTimer>

class SaiTower: public Tower
{
    Q_OBJECT
public:
    SaiTower(QGraphicsItem* parent = 0);
    void fire();
    public slots:
    void aquire_target();
};

#endif // SaiTOWER_H
