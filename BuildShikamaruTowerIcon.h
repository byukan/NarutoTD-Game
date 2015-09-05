/** @file BuildShikamaruTowerIcon.h
@brief This file contains class and member function declarations for BuildShikamaruTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#ifndef BuildShikamaruTowerIcon_H
#define BuildShikamaruTowerIcon_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildShikamaruTowerIcon: public QGraphicsPixmapItem{
public:
    BuildShikamaruTowerIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BuildShikamaruTowerIcon_H
