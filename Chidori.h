/** @file Chidori.h
@brief This file contains class and member function declarations for Chidori class.

The Chidori destroys any Enemies or Tobis that collide with it.
*/

#ifndef Chidori_H
#define Chidori_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Chidori: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Chidori(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // Chidori_H
