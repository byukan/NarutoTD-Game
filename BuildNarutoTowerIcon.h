/** @file BuildNarutoTowerIcon.h
@brief This file contains class and member function declarations for BuildNarutoTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#ifndef BuildNarutoTowerIcon_H
#define BuildNarutoTowerIcon_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildNarutoTowerIcon: public QGraphicsPixmapItem{
public:
    BuildNarutoTowerIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BuildNarutoTowerIcon_H
