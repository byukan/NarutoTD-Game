/** @file Hinata.h
@brief This file contains class and member function declarations for Hinata class.

HinataTower fires multiple projectiles in a spread.
*/

#ifndef HINATATOWER_H
#define HINATATOWER_H

#include "Tower.h"
#include <QTimer>

class HinataTower: public Tower
{
    Q_OBJECT
public:
    HinataTower(QGraphicsItem* parent = 0);
    void fire();
    public slots:
    void aquire_target();
};

#endif // HINATATOWER_H
