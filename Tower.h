/** @file Tower.h
@brief This file contains class and member function declarations for Tower class.

Towers have an attack area and fire a projectile when an enemy gets within range.
*/

#ifndef TOWER_H
#define TOWER_H


#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Tower: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower(QGraphicsItem* parent=0);
    double distanceTo(QGraphicsItem* item);
    virtual void fire();

public slots:
    void aquire_target();
protected:
    QGraphicsPolygonItem* attack_area;
    QPointF attack_dest;
    bool has_target;
};

#endif // TOWER_H
