/** @file Player.h
@brief This file contains class and member function declarations for Player class.

Click on the player to move left and right, spacebar to shoot Bullets at enemies.
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
private:
    QMediaPlayer * bulletsound;
};

#endif // PLAYER_H
