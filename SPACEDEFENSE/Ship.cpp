#include "Ship.h"
#include"Game.h"



// There is an external global object called game
extern Game * game ;

// Constructor
Ship::Ship(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent) {

}

// Launch shoots to kill enemies
void Ship::launchShoot() {

    // Create a new shoot, using our Shoot class
    Shoot * shoot = new Shoot();

    // Ajust the position of the shoot (with respect to the spaceship)
    shoot->setPos(x()+110,y()+48);

    // Add it to the scene
    game->scene->addItem(shoot);

}

// Remove from the scene and delete the ship
void Ship::end() {
    scene()->removeItem(this);
    delete this;
}
