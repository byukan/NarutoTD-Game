/** @file BuildRockleeTowerIcon.h
@brief This file contains class and member function declarations for BuildRockleeTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#ifndef BuildRockleeTowerIcon_H
#define BuildRockleeTowerIcon_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildRockleeTowerIcon: public QGraphicsPixmapItem{
public:
    BuildRockleeTowerIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BuildRockleeTowerIcon_H
