/** @file BuildInoTowerIcon.h
@brief This file contains class and member function declarations for BuildInoTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#ifndef BuildInoTowerIcon_H
#define BuildInoTowerIcon_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildInoTowerIcon: public QGraphicsPixmapItem{
public:
    BuildInoTowerIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BuildInoTowerIcon_H
