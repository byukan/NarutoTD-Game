/** @file BuildTentenTowerIcon.h
@brief This file contains class and member function declarations for BuildTentenTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#ifndef BuildTentenTowerIcon_H
#define BuildTentenTowerIcon_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildTentenTowerIcon: public QGraphicsPixmapItem{
public:
    BuildTentenTowerIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BuildTentenTowerIcon_H
