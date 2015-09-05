/** @file Score.cpp
@brief This file contains member function definitions for the Score class.

Score class keeps track of the GOLD, and can be spent on buying Towers.
*/

#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score
    score = 1000;

    // draw the text
    setPlainText(QString("GOLD: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::darkGreen);
    setFont(QFont("Comic Sans MS",30));
}

void Score::increase(int addToScore){
    score += addToScore;
    //score++;
    setPlainText(QString("GOLD: ") + QString::number(score)); // Score: 1
}

void Score::decrease(int subtractFromScore)
{
    score -= subtractFromScore;
    //score++;
    setPlainText(QString("GOLD: ") + QString::number(score)); // Score: 1
}

int Score::getScore(){
    return score;
}
