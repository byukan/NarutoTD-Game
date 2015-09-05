/** @file Health.h
@brief This file contains class and member function declarations for Health class.

Health keeps track of the number of enemies that move past the screen.
*/

#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent=0);
    void decrease();
    int getHealth();
private:
    int health;
};

#endif // HEALTH_H
