/** @file InoTower.h
@brief This file contains class and member function declarations for InoTower class.

InoTower fires projectiles at enemies.
*/

#ifndef InoTOWER_H
#define InoTOWER_H

#include "Tower.h"
#include <QTimer>

class InoTower: public Tower
{
    Q_OBJECT
public:
    InoTower(QGraphicsItem* parent = 0);
    void fire();
    public slots:
    void aquire_target();
};

#endif // InoTOWER_H
