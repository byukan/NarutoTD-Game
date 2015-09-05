/** @file BuildNejiTowerIcon.h
@brief This file contains class and member function declarations for BuildNejiTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#ifndef BuildNejiTowerIcon_H
#define BuildNejiTowerIcon_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildNejiTowerIcon: public QGraphicsPixmapItem{
public:
    BuildNejiTowerIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BuildNejiTowerIcon_H
