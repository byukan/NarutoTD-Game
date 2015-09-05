/** @file Shikamaru.h
@brief This file contains class and member function declarations for Shikamaru class.

ShikamaruTower fires multiple projectiles in a spread.
*/

#ifndef ShikamaruTOWER_H
#define ShikamaruTOWER_H

#include "Tower.h"
#include <QTimer>

class ShikamaruTower: public Tower
{
    Q_OBJECT
public:
    ShikamaruTower(QGraphicsItem* parent = 0);
    void fire();
    public slots:
    void aquire_target();
};

#endif // ShikamaruTOWER_H
