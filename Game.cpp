/** @file Game.cpp
@brief This file contains member function definitions for the Game class.

The Game constructor sets up the scene, health, score, tower icons,
background music enemy path, and spawns enemies.
*/

#include "Game.h"
#include "Tobi.h"
#include <QGraphicsScene>
#include "NarutoTower.h"
#include "Projectile.h"
#include "Enemy.h"
#include "BuildNarutoTowerIcon.h"
#include "BuildHinataTowerIcon.h"
#include "BuildInoTowerIcon.h"
#include "BuildTentenTowerIcon.h"
#include "BuildKibaTowerIcon.h"
#include "BuildSaiTowerIcon.h"
#include "BuildRockleeTowerIcon.h"
#include "BuildShikamaruTowerIcon.h"
#include "BuildNejiTowerIcon.h"
#include <QTimer>
#include <QGraphicsLineItem>
#include <QPen>
#include <QGraphicsLineItem>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QGraphicsTextItem>
#include <QFont>
#include <QLabel>

Game::Game(): QGraphicsView()
{


    //wave_value = 0;
    // create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1600,850);
    //set the scene
    setScene(scene);

    // make the background an image
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));

    //create a tower
    //Tower* t = new Tower();
    //t->setPos(250,250);

    //add the tower to scene
    //scene->addItem(t);

    //set cursor
    cursor = nullptr;
    building = nullptr;
    setMouseTracking(true);

    //alter window
    setFixedSize(1600,850);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create the score
    score = new Score();
    score->setPos(score->x()+1050,score->y()+10);
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x()+10,health->y()+140);
    scene->addItem(health);


//    // draw the text
//      QLabel* cost = new QLabel("Level: ");
//    setDefaultTextColor(Qt::darkGreen);
//    setFont(QFont("Comic Sans MS",15));
//      cost->setPos(100,100);
//      scene->addItem(cost);

    //label the costs
//    QLabel *label = new QLabel(this);
//    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
//    label->setText("first line\nsecond line");
//    label->setAlignment(Qt::AlignBottom | Qt::AlignRight);

    //label the costs
    QGraphicsTextItem* costText = new QGraphicsTextItem(QString("$1000 \n\n"
                                                                "$2000 \n\n"
                                                                "$3000 \n\n"
                                                                "$4000 \n\n"
                                                                "$5000 \n\n"
                                                                "$6000 \n\n"
                                                                "$7000 \n\n"
                                                                "$8000 \n\n"
                                                                "$9000 \n\n"));

    QFont costFont("comic sans", 25);
    costText->setFont(costFont);
    int txPos = 1400;
    int tyPos = 15;
    costText->setPos(txPos,tyPos);
    costText->setDefaultTextColor(Qt::darkYellow);
    scene->addItem(costText);


//    inot->setPos(x()+1500,y()+10);
//    tentent->setPos(x()+1500,y()+90);
//    hinatat->setPos(x()+1500,y()+170);
//    kibat->setPos(x()+1500,y()+250);
//    sait->setPos(x()+1500,y()+330);
//    rockleet->setPos(x()+1500,y()+410);
//    shikamarut->setPos(x()+1500,y()+490);
//    nejit->setPos(x()+1500,y()+570);
//    narutot->setPos(x()+1500,y()+650);


    // create the player
    player = new Player();
    player->setPos(420,700);
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);


    // spawn Tobis
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(9000);




    //create enemy
    //Enemy*= new Enemy();
    //scene->addItem(enemy);
    spawnTimer = new QTimer(this);

    waveTimer = new QTimer(this);

    enemiesSpawned = 0;
    maxNumberOfEnemies = 0;
    pointsToFollow << QPointF(1550, 810)
                   << QPointF(1100,810)
                   << QPointF(1100,500)
                   << QPointF(1330,500)
                   << QPointF(1330,300)
                   << QPointF(900,300)
                   << QPointF(900,780)
                   << QPointF(530,780)
                   << QPointF(530,700)
                   << QPointF(530,300)
                   << QPointF(5,300)
                   << QPointF(580,90)
                   << QPointF(-100,90);
    //<< QPointF(500,415)
//                      << QPointF(-100,120);
    //<< QPointF(1,400)
   // << QPointF(500,80)
    //<< QPointF(1,230)



    // create road
    createRoad();

    setCursor(":/images/leaf_symbol.png");

    //sidebar icons
    BuildInoTowerIcon * inot = new BuildInoTowerIcon();
    BuildTentenTowerIcon * tentent = new BuildTentenTowerIcon();
    BuildHinataTowerIcon * hinatat = new BuildHinataTowerIcon();
    BuildKibaTowerIcon * kibat = new BuildKibaTowerIcon();
    BuildSaiTowerIcon * sait = new BuildSaiTowerIcon();
    BuildRockleeTowerIcon * rockleet = new BuildRockleeTowerIcon();
    BuildShikamaruTowerIcon * shikamarut = new BuildShikamaruTowerIcon();
    BuildNejiTowerIcon * nejit = new BuildNejiTowerIcon();
    BuildNarutoTowerIcon * narutot = new BuildNarutoTowerIcon();

    inot->setPos(x()+1500,y()+10);
    tentent->setPos(x()+1500,y()+90);
    hinatat->setPos(x()+1500,y()+170);
    kibat->setPos(x()+1500,y()+250);
    sait->setPos(x()+1500,y()+330);
    rockleet->setPos(x()+1500,y()+410);
    shikamarut->setPos(x()+1500,y()+490);
    nejit->setPos(x()+1500,y()+570);
    narutot->setPos(x()+1500,y()+650);

    scene->addItem(narutot);
    scene->addItem(hinatat);
    scene->addItem(inot);
    scene->addItem(tentent);
    scene->addItem(kibat);
    scene->addItem(sait);
    scene->addItem(rockleet);
    scene->addItem(nejit);
    scene->addItem(shikamarut);



    // play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));
    music->play();



//    int level = 1;

//    if(level ==2)
//        createEnemies(10);


    //QTimer::singleShot(30,this,SLOT(releaseWave()));

//    QTimer* wave_timer = new QTimer(this);
//    connect(wave_timer, SIGNAL(timeout()),this,SLOT(releaseWave()));
//    wave_timer->start(1000);


//    QTimer *timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(releaseWave()));
//    timer->start(1000);

//    connect(waveTimer, SIGNAL(timeout()),this, SLOT(releaseWave()));
//    waveTimer->start(3000);  //spawn rate


    //releaseWave();
    //newWave();
    createEnemies(90);


}


//void Game::releaseWave(){
//    createEnemies(5);
//}



void Game::setCursor(QString filename)
{
    if(cursor){ //if cursor is not null, remove it
        scene->removeItem(cursor);
        delete cursor;
    }

    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(QPixmap(filename)));
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if(cursor){
        cursor->setPos(event->pos());
    }
}

void Game::mousePressEvent(QMouseEvent *event)
{
    // if we are building
    if (building){
        // return if the cursor is colliding with a tower
        QList<QGraphicsItem*> items = cursor->collidingItems();
        for (size_t i=0, n=items.size(); i<n; ++i){
            if (dynamic_cast<Tower*>(items[i])){
                return;
            }
        }

        //QList<QGraphicsItem*> items = cursor->collidingItems();
//        if(cursor->collidingItems)
//            return;


        // otherwise, build at the clicked location
        scene->addItem(building);
        building->setPos(event->pos());
        cursor = nullptr;
        building = nullptr;
    }
    else {
        QGraphicsView::mousePressEvent(event);
    }

}

void Game::createEnemies(int numberOfEnemies)
{
    enemiesSpawned = 0;
    maxNumberOfEnemies = numberOfEnemies;

    connect(spawnTimer, SIGNAL(timeout()),this, SLOT(spawnEnemy()));
    spawnTimer->start(2000);  //spawn rate


}



void Game::spawnEnemy()
{


    // spawn an enemy
    Enemy* enemy = new Enemy(pointsToFollow);
    enemy->setPos(pointsToFollow[0]);
    scene->addItem(enemy);
    ++enemiesSpawned;

    if (enemiesSpawned >= maxNumberOfEnemies){
        spawnTimer->disconnect();
    }


}


void Game::createRoad()
{
    for (size_t i = 0, n = pointsToFollow.size()-1; i < n; ++i){
        // create a line connecting the two points
        QLineF line(pointsToFollow[i],pointsToFollow[i+1]);
        QGraphicsLineItem* lineItem = new QGraphicsLineItem(line);

        QPen pen;
        pen.setCapStyle(Qt::RoundCap);
        pen.setJoinStyle(Qt::RoundJoin);
        pen.setWidth(0);
        pen.setColor(Qt::darkRed);


        lineItem->setPen(pen);

        scene->addItem(lineItem);



    }
}
