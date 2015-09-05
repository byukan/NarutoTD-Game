/** @file BuildSaiTowerIcon.h
@brief This file contains class and member function declarations for BuildSaiTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#ifndef BuildSaiTowerIcon_H
#define BuildSaiTowerIcon_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildSaiTowerIcon: public QGraphicsPixmapItem{
public:
    BuildSaiTowerIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BuildSaiTowerIcon_H
