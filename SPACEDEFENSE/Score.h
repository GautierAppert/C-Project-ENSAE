#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>



// The Score class, which corresponds (of course) to the score of the game
class Score : public QGraphicsTextItem {

public :
    // Constructor
    Score(QGraphicsItem * parent=0);
    // Increase the score (used when an enemy is killed)
    void increase();
    // Accessor of the score
    int getScore();

private :
    // Value of the score
    int score;

};



#endif // SCORE_H
