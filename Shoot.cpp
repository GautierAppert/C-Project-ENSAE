#include "Shoot.h"
#include "Game.h"



// There is an external global object called game
extern Game * game;

// Constructor
Shoot::Shoot(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {

    // Select the image of the bullet shoot, from Resources files
    setPixmap(QPixmap(":/images/redfireball.png"));

    //----- How we set the speed of the shoot -----//
    // Create a new timer, using the QTimer class from Qt
    QTimer * timer = new QTimer();
    // Do the shootMove() function at each timeout of the timer
    connect(timer,SIGNAL(timeout()),this, SLOT(shootMove()));
    // Start the timer : here, the shoot will move every 25 milliseconds
    timer->start(25);

}

// Set the bullet's movements
void Shoot::shootMove() {

    //----- We test whether the shoot touch an enemy -----//
    // If it is the case, we :
    //      - delete the enemy touched
    //      - delete the shoot
    //      - increase the score by 1
    //      - increase the money by 1
    // First, we check whether an enemy is touched, using the collidingItems() function
    // from Qt. Using the typeid() function, we retrieve which enemy is touched.
    QList<QGraphicsItem *> listOfItems = collidingItems();
    for(int i=0 , n=listOfItems.size(); i < n ; ++i){
        if(typeid(*(listOfItems[i])) == typeid(Enemy)) {
            // We increase the score by 1
            game->score->increase();
            // We increase the money by 1
            game->money->increase();
            // We remove from the scene and delete the enemy
            scene()->removeItem(listOfItems[i]);
            delete listOfItems[i];
            // We remove from the scene and delete the shoot
            scene()->removeItem(this);
            delete this;
            // Finally, we get out of the function if the shoot is deleted
            return;
        }
    }


    //----- We move the shoot -----//
    // We move the shoot to the right
    setPos(x()+25,y());
    // If the shoot reaches the right of the screen, it must be removed and deleted
    if (pos().x() > 800) {
        scene()->removeItem(this);
        delete this;
    }

}
