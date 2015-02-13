#include "Enemy.h"
#include "Game.h"



// There is an external global object called game
extern Game * game;



// Constructor
Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {

    // We randomly choose the initial y position of the enemy (y from 0 to 400)
    int randomY = rand() % 400;

    // Set the initial position of the enemy
    setPos(800,randomY);

    // Here, we randomly asign 0 or 1. We will derive from it the trajectory of the enemy
    bernoulliMovement = rand() % 2 ;

    // Select the image of the enemy, from Resources files
    setPixmap(QPixmap(":/images/enemy.gif"));

    //----- How we set the speed of the enemy -----//
    // Create a new timer, using the QTimer class from Qt
    QTimer * timer = new QTimer();
    // Do the move() function at each timeout of the timer
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    // Derive the speed of the enemy (it will increase with respect to the score)
    int enemySpeed = fmax(10,60 - 0.5*(game->score->getScore()));
    // Start the timer : here, the enemy will move every X milliseconds, with X in [10,60]
    // (it is 60 at the beginning, then it decreases when the score increases, which means
    // that the enemy will move faster)
    timer->start(enemySpeed);

}


// Set the enemy's movements
void Enemy::move() {

    // In our game, while the score is below 10, all enemies will move straight forward.
    // But, as soon as the score becomes larger than 10 :
    //      - 1/2 of the enemies will still move straight forward
    //      - 1/2 of the enemies will move following a sinusoidal trajectory
    // We will decide in which category each enemy is, using bernoulliMovement (which is 0 or 1
    // for each enemy created)

    // First, we check whether the score is larger than 10
    if(game->score->getScore()>10) {
        // If the score is indeed larger than 10 :
        //      - enemies whose bernoullliMovement=1 will still move straight forward
        //      - enemies whose bernoullliMovement=0 will move following a
        //        sinusoidal trajectory
        if(bernoulliMovement==0) {
            // fmax et fmin functions : we just put boundaries to be sure that enemies
            // never leave the screen
            // sinus function : we insert normalization constants (12 and 50) to obtain
            // appropriate sinusoidal curves for our game
            setPos(x()-10,fmin(400,fmax(0,y()- 12*sin(x()/50)  ))) ;
        }
        else {
            // In this case, the y is of course always the same. Only the x moves to the left
            setPos(x()-10,y()) ;
        }

    }
    // If the score is below 10, all enemies will move straight forward.
    else {
         setPos(x()-10,y()) ;
     }

    // If the enemy reaches the left of the screen, we must delete him, and the player
    // must lose one life
    if (pos().x() + 100 < 0){
        // The number of lifes decreases
        game->life->decrease();
        // The enemy is deleted
        scene()->removeItem(this);
        delete this ;
    }

}
