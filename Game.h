/** @file Game.h
@brief This file contains class and member function declarations for Game class.

The Game constructor sets up the scene, health, score, tower icons,
background music enemy path, and spawns enemies.
*/

#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QMouseEvent>
#include "Tower.h"
#include "Score.h"
#include "Health.h"
#include "Enemy.h"
#include "Player.h"







class Game: public QGraphicsView
{
    Q_OBJECT
public:
    //member functions
    Game();


    void setCursor(QString filename);
    //void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void createRoad();

    //member attributes
    QGraphicsScene* scene;
    QGraphicsPixmapItem* cursor;
    Tower* building;
    QTimer* spawnTimer;

    QTimer* waveTimer;

    int enemiesSpawned;
    int maxNumberOfEnemies;
    QList<QPointF> pointsToFollow;

    Score* score;
    Health* health;

    Player * player;



public slots:
    void spawnEnemy();

    void createEnemies(int numberOfEnemies);

};

#endif // GAME_H
