/** @file Health.cpp
@brief This file contains member function definitions for the Health class.

Health keeps track of the number of enemies that move past the screen.
*/

#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the health
    health = 25;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::darkRed);
    setFont(QFont("Comic Sans MS",20));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
}

int Health::getHealth(){
    return health;
}
