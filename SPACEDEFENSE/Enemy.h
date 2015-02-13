#ifndef ENEMY_H
#define ENEMY_H

#include "math.h"   // for math functions (sin, fmax, fmin)
#include <stdlib.h>   // for rand() function
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>



// The Enemy class, for the enemies of the game
class Enemy: public QObject, public QGraphicsPixmapItem {

    Q_OBJECT // Required for Qt, because we use public slots

public:
    // Constructor
    Enemy(QGraphicsItem * parent=0);

public slots:
    // Set the enemy's movements
    void move();

private:
    // Here, we will randomly asign 0 or 1. According to the value generated,
    // the enemy created will move, respectively, straight forward or following
    // a sinusoidal trajectory (see move() function)
    int bernoulliMovement ;

};



#endif // ENEMY_H
