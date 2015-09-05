/** @file BuildKibaTowerIcon.h
@brief This file contains class and member function declarations for BuildKibaTowerIcon class.

The TowerIcons set the image and make the game go into building mode when clicked.
*/

#ifndef BuildKibaTowerIcon_H
#define BuildKibaTowerIcon_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildKibaTowerIcon: public QGraphicsPixmapItem{
public:
    BuildKibaTowerIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BuildKibaTowerIcon_H
