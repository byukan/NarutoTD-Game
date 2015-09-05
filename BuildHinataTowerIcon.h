/** @file BuildHinataTowerIcon.h
@brief This file contains class and member function declarations for BuildHinataTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#ifndef BuildHinataTowerIcon_H
#define BuildHinataTowerIcon_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildHinataTowerIcon: public QGraphicsPixmapItem{
public:
    BuildHinataTowerIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BuildHinataTowerIcon_H
