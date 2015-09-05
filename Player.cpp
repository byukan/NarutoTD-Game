/** @file Player.cpp
@brief This file contains member function definitions for the Player class.

Click on the player to move left and right, spacebar to shoot Chidoris at enemies.
*/

#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Chidori.h"
#include "Enemy.h"
#include "Tobi.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    // set graphic
    setPixmap(QPixmap(":/images/kakashi.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 520)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        if(!event->isAutoRepeat()){  //make it so you can't hold space bar and fire too many
            // create a Chidori
            Chidori* zap = new Chidori();
            zap->setPos(x()+10,y());  //where Chidori apprears from character
            scene()->addItem(zap);
            }
        }
    }


void Player::spawn(){
    // create a Tobi
    Tobi* tobi = new Tobi();
    scene()->addItem(tobi);
}
