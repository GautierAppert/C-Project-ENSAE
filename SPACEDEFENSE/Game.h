#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Score.h"
#include "Life.h"
#include "Ship.h"
#include "ShipSimple.h"
#include "ShipDouble.h"
#include "ShipMaster.h"
#include "Money.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>


// The Game class, which manages the dynamic of our game and the placement of
// all items on the scene
class Game : public QGraphicsView {

public :
    // Constructor
    Game(QWidget * parent=0);
    // A function to put an image as the cursor (used when a ship has been bought)
    void setCursor(QString filename);
    // A function to make the cursor follow the mouse of the player
    void mouseMoveEvent(QMouseEvent *event);
    // What happens when we click on the zone area (after having bought a ship)
    void mousePressEvent(QMouseEvent *event);

// SEE THE LATEX REPORT, WHERE WE EXPLAIN WHY THERE ARE NOT IN PRIVATE
    // The scene, created with the QGraphicsScene class from Qt
    QGraphicsScene * scene;
    // The player, created with our Player class
    Player * player;
    // The score, created with our Score class
    Score * score;
    // The life, created with our Life class
    Life * life;
    // The money, created with our Money class
    Money * money ;
    // The cursor of the game, created with the QGraphicsPixmapItem class from Qt
    QGraphicsPixmapItem * cursor ;
    // Used to create new ships that will help the player to attack ennemies
    Ship * build ;
    // Three booleans to check whether a ship has been bought by the player
    bool testShipSimple;
    bool testShipDouble;
    bool testShipMaster;
    // The background music of the game
    QMediaPlayer * background ;
    // The error sound, played if the player does not have enough money to buy a ship
    QMediaPlayer * errorSound ;
    // The Game Over sound, played at the end of the game
    QMediaPlayer * gameOverSound ;

};



#endif // GAME_H
