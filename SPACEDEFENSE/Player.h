#ifndef PLAYER_H
#define PLAYER_H

#include "Enemy.h"
#include "Shoot.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QObject>



// The Player class, for the spaceship that we can control during the game
class Player: public QObject, public QGraphicsPixmapItem {

    Q_OBJECT // Required for Qt, because we use public slots

public:
    // Constructor
    Player(QGraphicsItem * parent=0);
    // Qt function that will make the Player react to some events on the keyboard
    void keyPressEvent(QKeyEvent * event);

public slots:
    // Add enemies to the scene (they will come in front of the player's ship, once it is created)
    void generateEnemy();

private:
    // The sound that the Player will make when he will attack enemies
    QMediaPlayer * shootSound;

};



#endif // PLAYER_H
