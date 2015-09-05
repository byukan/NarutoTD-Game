/** @file Enemy.cpp
@brief This file contains member function definitions for the Enemy class.

The Enemy constructor creates an Enemy with a random image and speed.
They move to points along a path.
*/

#include "Enemy.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QGraphicsScene>
#include "Game.h"
#include <stdlib.h> // rand() -> really large int


extern Game* game; // there is an external global object called game




Enemy::Enemy(QList<QPointF> pointsToFollow, QGraphicsItem *parent) : dead(false)
{
    //spawnDelay= 2000;
    //set graphics
    int enemyID = rand() % 7;

   // hp = 2;

    if(enemyID == 0)
    setPixmap(QPixmap(":/images/pein.png"));
    if(enemyID == 1)
    setPixmap(QPixmap(":/images/zetsu.png"));
    if(enemyID == 2)
    setPixmap(QPixmap(":/images/itachi.png"));
    if(enemyID == 3)
    setPixmap(QPixmap(":/images/sasuke.png"));
    if(enemyID == 4)
    setPixmap(QPixmap(":/images/orochimaru.png"));
    if(enemyID == 5)
    setPixmap(QPixmap(":/images/deidara.png"));
    if(enemyID == 6)
    setPixmap(QPixmap(":/images/zabuza.png"));







    //setTransformOriginPoint(boundingRect().width()/2, boundingRect().height()/2);
    //setRotation(180);

    //set points
    points = pointsToFollow;

    //points<< QPointF(200,200)<<QPointF(400,200); //move down-right
    point_index = 0;
    dest = points[0];
    rotateToPoint(dest);

    // connect timer to move_forward
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));

    if(enemyID == 0)
    timer->start(20);  //this controls enemy travel speed
    if(enemyID == 1)
    timer->start(45);  //this controls enemy travel speed
    if(enemyID == 2)
    timer->start(70);  //this controls enemy travel speed
    if(enemyID == 3)
    timer->start(95);  //this controls enemy travel speed
    if(enemyID == 4)
    timer->start(120);  //this controls enemy travel speed
    if(enemyID == 5)
    timer->start(145);  //this controls enemy travel speed
    if(enemyID == 6)
    timer->start(180);  //this controls enemy travel speed

}



void Enemy::rotateToPoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());
}


void Enemy::move_forward(){
    // if close to dest, rotate to next dest
    QLineF ln(pos(),dest);
    if (ln.length() < 5){
        point_index++;
        if(point_index>=points.size()){
            return;
        }
        dest = points[point_index];
        rotateToPoint(dest);
    }

    // move enemy forward at current angle
    int STEP_SIZE = 11;
    double theta = rotation(); // degrees

    double dy = (STEP_SIZE * qSin(qDegreesToRadians(theta)));
    double dx = (STEP_SIZE * qCos(qDegreesToRadians(theta)));

    setPos(x()+dx, y()+dy);


    // destroy enemy when it goes out of the screen
    if (pos().x() < 0){
        //decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }



}
