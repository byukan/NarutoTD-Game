/** @file Tobi.h
@brief This file contains class and member function declarations for Tobi class.

Tobi spawns on the left side of the map and can be destroyed by the Player's Bullet.
*/

#ifndef Tobi_H
#define Tobi_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Tobi: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tobi(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // Tobi_H
