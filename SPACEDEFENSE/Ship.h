#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>



// The Ship class, for the spaceships that the player can buy
class Ship :public QObject, public QGraphicsPixmapItem {

    Q_OBJECT // Required for Qt, because we use public slots

public :
    // Constructor
    Ship(QGraphicsItem * parent=0);
    // Accessor of the speed
    int getSpeed();

public slots :
    // Launch shoots to kill enemies
    void launchShoot();
    // Remove from the scene and delete the spaceship
    void end();

protected:
    // Speed of the ship : lauching of shoots
    int speed;
    // Life of the ship : duration in seconds on the scene
    int life;

};



#endif // SHIP_H
