/** @file Score.h
@brief This file contains class and member function declarations for Score class.

Score keeps track of GOLD, which goes up when enemies die.
*/

#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem* parent=0);
    void increase(int addToScore);
    void decrease(int subtractFromScore);

    int getScore();

    int score;

};

#endif // SCORE_H
