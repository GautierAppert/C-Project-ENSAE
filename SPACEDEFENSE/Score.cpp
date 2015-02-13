#include "Score.h"



// Constructor
Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent) {

    // Initialize the score to zero
    score = 0;

    // Display the score on the screen
    setPlainText(QString::number(score));

    // Some parameters : color, font, size
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",24));

}

// Increase the score (used when an enemy is killed)
void Score::increase() {

    score++;

    // Update the display of the score
    setPlainText(QString::number(score));

}

// Accessor of the score
int Score::getScore() {

    return score;

}
