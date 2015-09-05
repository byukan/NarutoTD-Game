/** @file Enemy.h
@brief This file contains class and member function declarations for Enemy class.

The Enemy constructor creates an Enemy with a random image and speed.
They move to points along a path.
*/

#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>

//Types of enemies
//enum class Enemy_Type{NORMAL, BADASS};

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QList<QPointF> pointsToFollow, QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);

    //SpawnDelay getter
    //inline int getSpawnDelay() const { return spawnDelay; }

    // enemy's health
    int hp;


public slots:
    void move_forward();
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;

    bool dead;
    int score;
    int speed;


};

#endif // ENEMY_H
