/** @file KibaTower.h
@brief This file contains class and member function declarations for KibaTower class.

KibaTower fires projectiles at enemies.
*/

#ifndef KibaTOWER_H
#define KibaTOWER_H

#include "Tower.h"
#include <QTimer>

class KibaTower: public Tower
{
    Q_OBJECT
public:
    KibaTower(QGraphicsItem* parent = 0);
    void fire();
    public slots:
    void aquire_target();
};

#endif // KibaTOWER_H
