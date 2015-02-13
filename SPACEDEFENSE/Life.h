#ifndef LIFE_H
#define LIFE_H

#include "Score.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>



// The Life class, to manage the number of lifes of the player
class Life : public QGraphicsTextItem {

public :
    // Constructor
    Life(QGraphicsItem * parent=0);
    // Decrease the number of lifes of the player (used when an enemy reaches the left of the screen)
    void decrease();

private :
    // Number of lifes
    int life;

};



#endif // LIFE_H
